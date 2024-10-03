/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhamad <mmuhamad@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:09:56 by mmuhamad          #+#    #+#             */
/*   Updated: 2024/05/07 13:54:58 by mmuhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parse.hpp"

bool	isOnOff(std::string line) {return (line == "on" || line == "off");}

bool	isNum(std::string line)
{
	if ((line[0] == '-' || line[0] == '+') && line[1] >= '0' && line[1] <= '9')
		return (true);
	return (line[0] >= '0' && line[0] <= '9');
}

bool	isMethod(std::string method)
{
	const std::string	met[7] = {"GET", "HEAD", "DELETE", "OPTIONS", "POST", "PUT", "TRACE"};

	for (size_t i = 0; i < 7 ; i++)
	{
		if (met[i] == method)
			return (true);
	}
	return (false);
}

bool	isHead(std::string line)
{
	const std::string head[8] = {"server_name", "listen", "root", "index", "allow_methods", "location", "error_page", "cgi_script"};

	for (size_t i = 0; i < 8; i++)
	{
		if (line == head[i])
			return (true);
	}
	return (false);
}

void	ExceptionDecider(empty type)
{
	if (type == EMPTY_PORT)			throw InvalidFileException("Error : Empty port.");
 	else if (type == EMPTY_NAME)	throw InvalidFileException("Error : Empty name.");
	else if (type == EMPTY_INDEX)	throw InvalidFileException("Error : Empty index.");
	else if (type == EMPTY_ROOT)	throw InvalidFileException("Error : Empty ROOT.");
	else							return ;
}

Parse::Parse(std::string fileName)
{
	if (fileName.length() < 5 || fileName.substr(fileName.length() - 5) != ".conf")
		throw InvalidFileException("Error : file should have a .conf extension !!");

	std::ifstream	infile(fileName.c_str());
	std::string	line;

	if (!infile.is_open())
		throw InvalidFileException("Error opening file.");
	while (std::getline(infile, line))
		tokennize(line);
	tokenValidation();
	pathValidation();

	std::map<int, ServerBlock>::iterator	i = block.begin();

	for (i = block.begin(); i != block.end(); i++)
	{
		std::cout << i->second << std::endl;
	}
	std::cout << "Parsing completed.." << std::endl;
}

/*
	end = find the first index of sep
	start = find the next index of not sep
	push the string between start and end into list

	works like ft_split with sep==isspace
*/
void	Parse::tokennize(std::string line)
{
	const std::string sep(" \t\v\r\n\f");
	size_t	start = 0, end = 0;
	size_t	npos = std::string::npos;

	while (start != npos && end != npos)
	{
		end = line.find_first_of(sep, start);
		if (end == npos && line[start] != 0)
		{
			token.push_back(&line[start]);
			break ;
		}
		if (start != npos && end - start != 0 && line[start] != 0)
			token.push_back(line.substr(start, end - start));
		start = line.find_first_not_of(sep, end);
	}
}

int		Parse::getAvailablePort(iterator i)
{
	Parse::iterator	it = i;

	for (; isNum(*i); i++)
	{
		for (size_t j = 0; (*i)[j]; j++)
		{
			if ((*i)[j] < '0' || (*i)[j] > '9')
			{
				std::cerr << "Error : Invalid port : " << *i;
				throw InvalidFileException("");
			}	
		}
	}
	
	
	while (isNum(*it))
	{
		int	port;

		port = std::atoi((*it).c_str());
		if (port < 0 || port >= UINT16_MAX)
		{
			std::cerr << "Error : Invalid port : " << port;
			throw InvalidFileException("");
		}
	
		int	sockfd;
		struct sockaddr_in	serverAddr;
		int	reuse = 1;

		sockfd = socket(AF_INET, SOCK_STREAM, 0);
		if (sockfd == -1)
		{
			std::cerr << "Error creating socket." << std::endl;
			exit(EXIT_FAILURE);
		}
		if (fcntl(sockfd, F_SETFL, O_NONBLOCK) == -1)
		{
			std::cerr << "Error setting non-blocking mode\n";
			exit(EXIT_FAILURE);
		}
		if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) == -1)
		{
			std::cerr << "Error setting reuse of port." << std::endl;
			exit(EXIT_FAILURE);
		}
		memset(&serverAddr, 0, sizeof(serverAddr));
		serverAddr.sin_family = AF_INET;
		serverAddr.sin_port = htons(port);
		serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
		if (bind(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) != -1)
		{
			setSocketFD(port, sockfd);
			return (port);
		}
		/*
			Not closing socket fd is in case other
			server block wants to use the same port
			hence keeping it occupied
		*/
		it++;
	}
	throw InvalidFileException("Error : All ports not available.");
}

void	Parse::setMethod(Parse::iterator &i, ServerBlock& sb)
{
	while (i != token.end() && *i != "}" && isMethod(*i))
		sb.addMethod(*i++);
	if (i == token.end() || *i == "}")
	{
		--i;
		return ;
	}
	if (!isHead(*i))
	{
		std::cerr << "Error : Invalid syntax : " + *i;
		throw InvalidFileException("");
	}
	--i;
}

void	Parse::serverCheck(Parse::iterator &i)
{
	conf		_conf = NONE;
	ServerBlock	block;
	int			port;
	
	if (*(++i) != "{")
		throw InvalidFileException("Missing {");
	++i;
	for (; i != token.end(); i++)
	{
		if (*i == "}")
			break ;
		if (*i == "server_name")
			_conf = SERVER_NAME;
		else if (*i == "listen")
			_conf = LISTEN;
		else if (*i == "root")
			_conf = ROOT;
		else if (*i == "index")
			_conf = INDEX;
		else if (*i == "error_page")
			_conf = ERROR_PAGE;
		else if (*i == "allow_methods" || (_conf == ALLOW_METHOD && isMethod(*i)))
			_conf = ALLOW_METHOD;
		else if (*i == "location")
			_conf = LOCATION;
		else if (*i == "client_max_body_size")
			_conf = CLIENT_MAX_BODY_SIZE;
		else if (*i == "client_min_body_size")
			_conf = CLIENT_MIN_BODY_SIZE;
		// else if (*i == "cgi_script")
		// 	_conf = CGI_SCRIPT;
		else if (*i == "autoindex")
			_conf = AUTOINDEX;
		if (_conf == NONE)
		{
			std::cerr << "Error : Invalid syntax : " + *i << std::endl;
			throw InvalidFileException("");
		}
		++i;
		if (_conf == SERVER_NAME)
			block.setName(*i);
		else if (_conf == LISTEN)
		{
			port = getAvailablePort(i);
			block.setPort(port);
			while (isNum(*(i + 1)))
				++i;
		}
		else if (_conf == ROOT)
			block.setRoot(*i);
		else if (_conf == INDEX)
			block.setIndex(*i);
		else if (_conf == ERROR_PAGE)
			block.addErrorPage(i);
		else if (_conf == ALLOW_METHOD)
			setMethod(i, block);
		else if (_conf == CLIENT_MIN_BODY_SIZE && isNum(*i))
			block.setClientMinBodySize(std::atoi((*i).c_str()));
		else if (_conf == CLIENT_MAX_BODY_SIZE && isNum(*i))
			block.setClientMinBodySize(std::atoi((*i).c_str()));
		else if (_conf == LOCATION)
		{
			Location	loc(i, token);
			block.addLocation(loc);
		}
		// else if (_conf == CGI_SCRIPT)
		// 	block.setCgiScript(i);
		else if (_conf == AUTOINDEX)
		{
			if (isOnOff(*i))
				block.setAutoIndex(*i);
			else
			{
				std::cerr << "Invalid syntax : autoindex " << *i;
				throw InvalidFileException("");
			}
		}
		if (_conf != ALLOW_METHOD)
			_conf = NONE;
	}
	if (i == token.end())
		throw InvalidFileException("Error : Missing }");
	ExceptionDecider(block.somethingEmpty());
	this->block[port] = block;
}

void	Parse::tokenValidation()
{
	iterator	i;

	for (i = token.begin(); i != token.end(); i++)
	{
		if (*i == "server")
			serverCheck(i);
	}
}

void	Parse::pathValidation()
{
	std::map<int, ServerBlock>::iterator	i;

	for (i = block.begin(); i != block.end(); i++)
	{
		ServerBlock	_sb = i->second;
		std::string	folder = _sb.getRoot();
		std::string	index = folder + std::string("/") + _sb.getIndex();
		std::string	errMsg;

		std::ifstream	in(folder.c_str());
		std::ifstream	in2(index.c_str());
		std::ifstream	cgi;
		bool			cgiExist = false;

		std::vector<std::string>	check = _sb.getCgiScript();
		std::vector<std::string>::iterator it;
		
		if (!_sb.getCgiScript().empty())
		{
			for (it = check.begin(); it != check.end(); ++it)
			{
				std::string filePath = *it;

				cgi.open(filePath.c_str());
				if (cgi.is_open())
					cgi.close();
				else
				{
					errMsg = "cannot open file";
					break ;
				}
			}
			cgiExist = true;
		}
		if (!in)
			errMsg = folder;
		else if (!in2)
			errMsg = index;
		// else if (cgiExist && !cgi)
		// 	errMsg = _sb.getCgiScript();
		if (!errMsg.empty())	
		{
			std::cerr << "Error : no such file or directory : " << errMsg;
			throw InvalidFileException("");
		}
		std::vector<Location>::iterator	j;
		std::vector<Location> lc = _sb.getLocation();
		for (j = lc.begin(); j != lc.end(); j++)
		{
			std::string	str;
			if (!(*j).getRoot().empty())
				folder = (*j).getRoot();
			if (!(*j).getIndex().empty())
				index = folder + std::string("/") + (*j).getIndex();
			std::ifstream	in(folder.c_str());
			std::ifstream	in2(index.c_str());
			
			if (!in)
				errMsg = folder;
			else if (!in2)
				errMsg = index;
			if (!errMsg.empty())	
			{
				std::cerr << "Error : no such file or directory : " << errMsg;
				throw InvalidFileException("");
			}
		}
	}
}

std::map<int, ServerBlock>&	Parse::getBlock() {return this->block;}

void	Parse::setSocketFD(int port, int sockfd) {this->_socketFD[port] = sockfd;}

std::map<int, int>&	Parse::getSocketFD() {return this->_socketFD;}

Parse::~Parse(){}

Parse::Parse(const Parse& other) {*this = other;}

Parse&	Parse::operator=(const Parse& other)
{
	if (this == &other)
		return (*this);
	this->token = other.token;
	this->block = other.block;
	this->_socketFD = other._socketFD;
	return (*this);
}
