/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhamad <mmuhamad@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:20:51 by suchua            #+#    #+#             */
/*   Updated: 2024/04/25 11:30:33 by mmuhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SERVER_HPP__
# define __SERVER_HPP__

# include "ServerBlock.hpp"
# include "Webserv.hpp"
# include "HttpRequest.hpp"

class Server
{
	private:
		const std::map<int, ServerBlock>&	_conf;
		const std::map<int, int>&			_socketFD;
		HttpRequest							_httpReq;
		char								**_env;

		void			acceptConnection();
		std::string		AcceptRequest(struct sockaddr_in&	clientAddr, int clientSocket, ServerBlock sb);
		void			sendResponse(std::string response, int clientSocket, int port, fd_set writeFds);
	public:
		Server(std::map<int, ServerBlock>& conf, std::map<int, int>& socketFD, char **env);
		~Server();
		Server(const Server& other);
		Server&	operator=(const Server& other);
		void	startServer();

};

#endif
