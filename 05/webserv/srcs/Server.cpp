/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhamad <mmuhamad@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:28:08 by suchua            #+#    #+#             */
/*   Updated: 2024/05/08 16:46:33 by mmuhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

/***********************************
 * SERVER
***********************************/
void	Server::startServer()
{
	std::map<int, int>::const_iterator	it;
	int	sockfd;

	std::cout << std::endl;
	for (it = _socketFD.begin(); it != _socketFD.end(); it++)
	{
		sockfd = it->second;
		if (listen(sockfd, SOMAXCONN) == -1)
		{
			perror("listen");
			std::cerr << "Error : Failed to listen at port " << it->first << std::endl;
			exit(EXIT_FAILURE);
		}
		std::cout << YELLOW << "[ * ] Listening for incoming connections on port " << BLUE << it->first << YELLOW << " ... " << RESET << std::endl;
	}
	std::cout << "\n" << MAGENTA << " --------------------------------- " << RESET << "\n\n";
	while (true)
		acceptConnection();
}

void	Server::acceptConnection()
{
	std::map<int, int>::const_iterator	ite;
	fd_set			readFds;
	fd_set			writeFds;
	int				maxFD;
	int				sockfd;
	int				port;
	int				clientSocket;
	struct timeval	timeout;
    std::string     req;

	FD_ZERO(&readFds);
	FD_ZERO(&writeFds);
	maxFD = -1;
	for (ite = _socketFD.begin(); ite != _socketFD.end(); ite++)
	{
		sockfd = ite->second;
		FD_SET(sockfd, &readFds);
		if (sockfd > maxFD)
			maxFD = sockfd;
	}

	timeout.tv_sec = 5;
	timeout.tv_usec = 0;

    if (select(maxFD + 1, &readFds, &writeFds, NULL, &timeout) == 0)
        return;
	if (select(maxFD + 1, &readFds, &writeFds, NULL, &timeout) == -1)
	{
		perror("select");
		exit(EXIT_FAILURE);
	}
    
	std::map<int, ServerBlock>::const_iterator	it;

	for (it = _conf.begin(); it != _conf.end(); it++)
	{
		port = it->first;
		sockfd = _socketFD.find(port)->second;
		
		if (FD_ISSET(sockfd, &readFds))
		{
			struct sockaddr_in	clientAddr;
			socklen_t			addrLen;
			
			memset(&clientAddr, 0, sizeof(clientAddr));
			addrLen = sizeof(clientAddr);
			clientSocket = accept(sockfd, (struct sockaddr *) &clientAddr, &addrLen);
			if (clientSocket == -1)
			{
				perror("accept");
				std::cerr << "Failed to accept new connection at port " << port << std::endl;
			}
			FD_SET(clientSocket, &readFds);

			if (clientSocket > maxFD)
				maxFD = clientSocket;

			timeout.tv_sec = 5;
			timeout.tv_usec = 0;

			if (select(maxFD + 1, &readFds, NULL, NULL, &timeout) == -1)
			{
				perror("select");
				exit(EXIT_FAILURE);
			}
			if (FD_ISSET(clientSocket, &readFds))
			{
				int chck = fcntl(clientSocket, F_SETFL, O_NONBLOCK);
				if (chck == -1)
				{
					std::cerr << "Error setting non-blocking mode\n";
					close(clientSocket);
				}
				else
				{
				    req = AcceptRequest(clientAddr, clientSocket, it->second);
                    FD_SET(sockfd, &writeFds);
		            FD_CLR(sockfd, &readFds);
				}
			}
		}
		if (FD_ISSET(sockfd, &writeFds))
		{
			std::string	httpResponse = this->_httpReq.generateHttpResponse(req, clientSocket, it->second, _env);
            // receivedData.erase();
            if	(httpResponse == "")
            {
            	std::cout << RED << "[ ❌ ] Msg not sent to client!" << RESET << std::endl;
            	std::cout << std::endl;

            	std::cout << MAGENTA << " --------------------------------- " << RESET << std::endl;
            	std::cout << std::endl;
            	close(clientSocket);
            	return ;
            }
            sendResponse(httpResponse, clientSocket, port, writeFds);
		}
	}
}

int		checkEnd(const std::string& str, const std::string& end)
{
	size_t	i = str.size();
	size_t	j = end.size();

	while (j > 0)
	{
		i--;
		j--;
		if (i < 0 || str[i] != end[j])
			return (1);
	}
	return (0);
}

void receiveData(int clientSocket, std::string& receivedData)
{
    std::vector<char> client_message(100001);
	std::map<long, std::string>	requests;

    while (true) {
    	std::memset(client_message.data(), 0, 100001);
        ssize_t receivedBytes = recv(clientSocket, client_message.data(), 100001, 0);

		requests[clientSocket] += std::string(client_message.data());
		size_t	i = requests[clientSocket].find("\r\n\r\n");
		if (i != std::string::npos)
		{
			if (requests[clientSocket].find("Content-Length: ") == std::string::npos)
			{
				if (requests[clientSocket].find("Transfer-Encoding: chunked") != std::string::npos)
				{
					if (checkEnd(requests[clientSocket], "0\r\n\r\n") == 0)
						break ;
					else
						continue ;
				}
				else
					break ;
			}

			size_t	len = std::atoi(requests[clientSocket].substr(requests[clientSocket].find("Content-Length: ") + 16, 10).c_str());
			if (requests[clientSocket].size() >= len + i + 4)
				break ;
			else
				continue ;
		}
        if (receivedBytes <= 0) {
            if (receivedBytes == -1) {
                perror("Couldn't receive");
            }
            std::cerr << "Couldn't receive message at " << clientSocket << " client fd socket" << std::endl;
            close(clientSocket);
            return;
        }
    }
	receivedData = requests[clientSocket];
}

std::string	Server::AcceptRequest(struct sockaddr_in&	clientAddr, int clientSocket, ServerBlock sb)
{
	std::string 		receivedData;
	const int			port = sb.getPort();

	std::cout << GREEN << "[ ✅ ] New connection" << YELLOW << " : client with IP "  << BLUE << inet_ntoa(clientAddr.sin_addr) << YELLOW ;
	std::cout << ", accepted on port " << BLUE << port << " ==> "<< MAGENTA << "FD -> " << clientSocket << RESET << std::endl << std::endl;

	receiveData(clientSocket, receivedData);

	std::cout << YELLOW << "[ * ]  Msg from client: \n\n" << RESET << std::endl;
	std::cout << receivedData << std::endl;
    return (receivedData);
}

void Server::sendResponse(std::string response, int clientSocket, int port, fd_set writeFds) {
    const char *server_msg = response.c_str();
    ssize_t msg_len = static_cast<ssize_t>(response.length());
    ssize_t total_sent = 0;
    ssize_t sent;

    // std::cout << RED << response << RESET << std::endl;

    while (total_sent < msg_len) {
        sent = send(clientSocket, server_msg + total_sent, msg_len - total_sent, 0);
        if (sent == -1 ) {
            perror("send");
            std::cerr << "Couldn't send message to client at socket " << clientSocket << "\n\n";
            close(clientSocket);
			std::cout << YELLOW << "[ * ] Listening for incoming connections on port " << BLUE << port << YELLOW << " ... " << RESET << std::endl;
			std::cout << MAGENTA << " --------------------------------- " << RESET << "\n\n";
            return;
        }
        if (sent == 0) {
            std::cerr << "Client disconnected prematurely at socket " << clientSocket << "\n\n";
            close(clientSocket);
			std::cout << YELLOW << "[ * ] Listening for incoming connections on port " << BLUE << port << YELLOW << " ... " << RESET << std::endl;
			std::cout << MAGENTA << " --------------------------------- " << RESET << "\n\n";
            return;
        }
        total_sent += sent;
    }
    std::cout << GREEN << "[ ✅ ] Msg sent to client!" << RESET << "\n\n";
    std::cout << MAGENTA << " --------------------------------- " << RESET << "\n\n";
    close(clientSocket); // Close the socket after sending the response
    FD_CLR(clientSocket, &writeFds);
}

/***********************************
 * Constructors & Destructors
***********************************/

Server::Server(std::map<int, ServerBlock>& conf, std::map<int, int>& socketFD, char **env)
: _conf(conf), _socketFD(socketFD), _env(env) {this->_httpReq = HttpRequest();}

Server::Server(const Server& other)
: _conf(other._conf), _socketFD(other._socketFD) {*this = other;}

Server&	Server::operator=(const Server& other)
{
	if (this == &other)
		return (*this);
	return (*this);
}

Server::~Server(){}
