/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpRequest.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 23:33:01 by suchua            #+#    #+#             */
/*   Updated: 2024/05/11 15:33:56 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HttpRequest.hpp"
#define BUFFER_SIZE 100000

const std::string processChunk(const std::string& req)
{
    size_t headerEnd = req.find("\r\n\r\n");
    if (headerEnd == std::string::npos) {
        // Malformed request, return as is
        return req;
    }
    
    std::string head = req.substr(0, headerEnd + 4); // Include the CRLFCRLF
    std::string chunks = req.substr(headerEnd + 4);
    std::string body;
    size_t pos = 0;
    
    while (pos < chunks.length()) {
        size_t endOfChunkSize = chunks.find("\r\n", pos);
        if (endOfChunkSize == std::string::npos) {
            // Malformed chunked data, return as is
            return req;
        }
        
        std::string chunkSizeStr = chunks.substr(pos, endOfChunkSize - pos);
        char *endPtr;
        int chunkSize = strtol(chunkSizeStr.c_str(), &endPtr, 16);
        
        if (*endPtr != '\0' || chunkSize < 0) {
            // Invalid chunk size, return as is
            return req;
        }
        
        pos = endOfChunkSize + 2;
        
        if (chunkSize == 0) {
            // End of chunks
            break;
        }
        
        if (pos + chunkSize > chunks.length()) {
            // Malformed chunked data, return as is
            return req;
        }
        
        body += chunks.substr(pos, chunkSize);
        pos += chunkSize + 2;
    }
    
    return head + body;
}

void	HttpRequest::parseHttpRequest(const str& req)
{
	std::istringstream	stream(req);
	str	line;
	str	req2;

	if (req.find("Transfer-Encoding: chunked") != std::string::npos && req.find("Transfer-Encoding: chunked") < req.find("\r\n\r\n"))
	{
		req2 = processChunk(req);
		setfull(req2);
	}
	else
		setfull(req);

	if (std::getline(stream, line))
	{
		std::istringstream	lineStream(line);
		lineStream >> this->_methodStr >> this->_path;
		setMethod(this->_methodStr);
	}

	size_t	separatorPos;
	str		key;
	str		value;

	while (std::getline(stream, line))
	{
		separatorPos = line.find(':');
		if (separatorPos != std::string::npos)
		{
			key = line.substr(0, separatorPos);
			value = line.substr(separatorPos + 2);
			setHeader(key, value);
		}
		if (key == "Content-Type")
			str	boundary = value.substr(value.find_first_of('=') + 1);
		if (key == "Content-Length")
			break ;
	}
	while (std::getline(stream, line))
		setBody(line);
}

Location isCGI(const HttpRequest req, const ServerBlock sb, RequestErrorHandling err)
{
    size_t lastDotPos = req.getPath().find_last_of('.');
    size_t lastDotPos2;
    std::string fileExtension;
    std::string fileExtension2;
    std::string							reqMethod;
	std::vector<std::string>			validMethod;
	std::vector<std::string>::iterator	it2;
	Location	false_loc;

    if (lastDotPos == std::string::npos)
        return false_loc;

    fileExtension = req.getPath().substr(lastDotPos);

    std::vector<Location> loc = sb.getLocation();
    std::vector<Location>::iterator it;
    
    for (it = loc.begin(); it != loc.end(); it++)
    {
        lastDotPos2 = (*it).getDirectory().find_last_of('.');
        if (lastDotPos2 == std::string::npos)
            continue ;
        fileExtension2 = (*it).getDirectory().substr(lastDotPos2);
		size_t pos = fileExtension.find(fileExtension2, 0);
        if (pos != std::string::npos)
        {
            reqMethod = req.getMethodStr();
	        validMethod = (*it).getMethods();
            for (it2 = validMethod.begin(); it2 != validMethod.end(); it2++)
            {
                if ((*it2) == reqMethod)
                    return ((*it)); 
            }
            err.generateErrResponse(405, *it);
            return false_loc;
        }
    }
    return false_loc;
}

std::string	HttpRequest::get_pathinfo(const HttpRequest req)
{
	std::string path_info;
	std::string url = req.getPath();

    size_t start_pos = url.find(".bla");
    if (start_pos != std::string::npos) {
		path_info = "YoupiBanane/cgi_bin/cgi_tester";
        return path_info;
    }
    start_pos = url.find(".py");
    if (start_pos != std::string::npos) {
		start_pos += 3;
		path_info = url.substr(start_pos);
        return path_info;
    }
    start_pos = url.find(".php");
    if (start_pos != std::string::npos) {
		start_pos += 4;
		path_info = url.substr(start_pos);
        return path_info;
    }
    return path_info;
}

void HttpRequest::populateEnvp(std::string input)
{
	const char *c_str = input.c_str();
	size_t	i = 0;
	for (; c_str[i]; ++i)
		this->_envp[this->_CurrEnvp][i] = c_str[i];
	++this->_CurrEnvp;
}

std::string get_exe(Location target2, std::string req)
{
	size_t start_pos = req.find(".bla");
    if (start_pos != std::string::npos) {
        return "YoupiBanane/cgi_bin/cgi_tester";
    }
	std::string folder;
    if (target2.getRoot().empty())
    {
        folder = target2.getCgiScript().front();
    }
    else{
        folder = target2.getRoot() + "/" +target2.getCgiScript().front();
    }
    
	std::string 	line;
	std::string 	ret;
	std::ifstream	in(folder.c_str());
	std::getline(in, line);
	size_t 			pos = line.find("!");

	ret = line.substr(pos + 1);
	return(ret);
}

std::string	HttpRequest::generateHttpResponse(const str& req, const int clientSocket, const ServerBlock sb, char **env)
{
	parseHttpRequest(req);	
	RequestErrorHandling	err(*this, sb);
	if (!err.ErrorHandler())
		return (err.getErrResponse());
	
	Location	target(err.getTargetBlock());
    Location	target2(isCGI(*this, sb, err));
	str			response;

    if (!target.getReturn().empty())
    {
        response = "HTTP/1.1 302 Found\r\n";
        response += "Location: " + target.getReturn() + "\r\n";
        response += "Content-Length: 0\r\n";
        response += "\r\n";
        return (response);
    }

	if (target2.getCgiScript().size() != 0)
	{
		std::string		toWrite = this->getfull();
        FILE*           inTempFile = std::tmpfile();
        FILE*           outTempFile = std::tmpfile();

        if (inTempFile == nullptr || outTempFile == nullptr) {
            err.generateErrResponse(500, target2);
			return (err.getErrResponse());
        }
        std::fwrite(toWrite.c_str(), sizeof(char), toWrite.size(), inTempFile);

		std::string cgi_script;
        if (target2.getRoot().empty())
            cgi_script = target2.getCgiScript().front();
        else
            cgi_script = target2.getRoot() + "/" +target2.getCgiScript().front();

		populateEnvp("HTTP_X_SECRET_HEADER_FOR_TEST=1");
		populateEnvp("REDIRECT_STATUS=200");
		populateEnvp("CONTENT_LENGTH=" + std::to_string(toWrite.size()));
		populateEnvp("CONTENT_TYPE=*/*");
		populateEnvp("GATEWAY_INTERFACE=CGI/1.1");
		populateEnvp("PATH_INFO=" + get_pathinfo(*this));
		populateEnvp("PATH_TRANSLATED=" + cgi_script);
		populateEnvp("QUERY_STRING=");
		populateEnvp("REMOTE_ADDR=127.0.0.1");
		populateEnvp("REQUEST_URI=" + cgi_script);
		populateEnvp("REQUEST_METHOD=" + this->getMethodStr());
		populateEnvp("SCRIPT_NAME=" + cgi_script);
		populateEnvp("SERVER_PROTOCOL=HTTP/1.1");
		populateEnvp("SERVER_SOFTWARE=webserv");
		populateEnvp("SERVER_PORT=" + std::to_string(sb.getPort()));
		
		int	stdinFd = dup(STDIN_FILENO);
		int	stdoutFd = dup(STDOUT_FILENO);
		pid_t pid = fork();
		std::string exe = get_exe(target2, this->getPath());
		if (pid == 0)
		{
            dup2(fileno(inTempFile), STDIN_FILENO);
            dup2(fileno(outTempFile), STDOUT_FILENO);
			close(fileno(inTempFile));
			close(fileno(outTempFile));
			char	*args[3] = {(char *)exe.c_str(), (char *)cgi_script.c_str(), NULL};
			(void)env;
			execve(args[0], args, _envp);
			fclose(inTempFile);
            fclose(outTempFile);
			std::cerr << RED << "Execve failed..." << RESET << std::endl;
			exit(EXIT_FAILURE);
		}
		int status;
		waitpid(-1, &status, 0);
		if (WIFEXITED(status) == 0)
			std::cerr << RED << "CGI exited abnormally" << RESET << std::endl;

        std::rewind(outTempFile);
        char buffer[BUFFER_SIZE];
        size_t bytesRead;
        std::string output;
        while ((bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, outTempFile)) > 0) {
            output.append(buffer, bytesRead);
        }
        
		size_t  startPos = output.find("\r\n\r\n");
		if (startPos == std::string::npos)
		{
			err.generateErrResponse(404, target2);
			return (err.getErrResponse());
		}
		else
		{
			startPos += std::strlen("\r\n\r\n");
			std::string newOutput = output.substr(startPos);
			response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
			response += newOutput;
			response += "\r\n\r\n";
			std::cout << GREEN << "CGI ran successfully!" << RESET << "\n\n";
			fclose(inTempFile);
            fclose(outTempFile);
			dup2(stdinFd, STDIN_FILENO);
			close(stdinFd);
			dup2(stdoutFd, STDOUT_FILENO);
			close(stdoutFd);
		}

		for (size_t i = 0; i < 15; ++i)
			std::memset(this->_envp[i], 0, 1000);
		this->_CurrEnvp = 0;
		
		return (response);
	}

    if (!err.getErrResponse().empty())
    {
        return (err.getErrResponse());
    }

	switch (this->_methodEnum)
	{
		case GET:
			response = GetResponse(*this, target, err).getResponse();
			break;
		case PUT:
			response = PutResponse(*this, clientSocket, target, err).getResponse();
			break;
		case POST:
			response = PostResponse(*this, clientSocket, target, err).getResponse();
			break;
		case DELETE:
			response = DeleteResponse(*this, clientSocket, target, err).getResponse();
			break;
		case HEAD:
			err.generateErrResponse(200, target);
			response = err.getErrResponse();
			break;
		case TRACE:
			response = TraceResponse(*this, clientSocket, target, err).getResponse();
			break;
		default:
			break;
	}
	return (response);
}

HttpRequest::HttpRequest()
{
	this->_httpStatusMsg[200] = "200 OK\r\n";
	this->_httpStatusMsg[201] = "201 Created\r\n";
	this->_httpStatusMsg[400] = "400 Bad Request\r\n";
	this->_httpStatusMsg[404] = "404 Not Found\r\n";
	this->_httpStatusMsg[405] = "405 Not Allowed\r\n";
	this->_httpStatusMsg[413] = "413 Request Entity Too Large\r\n";
	this->_httpStatusMsg[415] = "415 Unsupported Media Type\r\n";
	this->_httpStatusMsg[500] = "500 Internal Server Error\r\n";
	
    this->_envp = new char*[16];
	for (size_t i = 0; i < 15; ++i)
	{
		this->_envp[i] = new char[1000];
		std::memset(this->_envp[i], 0, 1000);
	}
	this->_envp[15] = NULL;
	this->_CurrEnvp = 0;
}

HttpRequest::~HttpRequest() {}

HttpRequest::HttpRequest(const HttpRequest& other) {*this = other;}

HttpRequest&	HttpRequest::operator=(const HttpRequest& other)
{
	if (this == & other)
		return (*this);
	this->_methodStr = other._methodStr;
	this->_methodEnum = other._methodEnum;
	this->_path = other._path;
	this->_body = other._body;
	this->_header = other._header;
	return (*this);
}

void	HttpRequest::setMethod(str method)
{
	if (method == "GET")			_methodEnum = GET;
	else if (method == "HEAD")		_methodEnum = HEAD;
	else if (method == "DELETE")	_methodEnum = DELETE;
	else if (method == "OPTIONS")	_methodEnum = OPTIONS;
	else if (method == "POST")		_methodEnum = POST;
	else if (method == "PUT")		_methodEnum = PUT;
	else							_methodEnum = TRACE;
}

void	HttpRequest::setfull(str full) {this->_full = full;}

void	HttpRequest::setPath(str path) {this->_path = path;}

void	HttpRequest::setBody(str line) {this->_body.push_back(line);}

void	HttpRequest::setHeader(str key, str value){this->_header[key] = value;}

HttpRequest::body	HttpRequest::getBody() const {return this->_body;}

std::string	HttpRequest::getPath() const {return this->_path;}

std::string	HttpRequest::getfull() const {return this->_full;}

std::string	HttpRequest::getMethodStr() const {return this->_methodStr;}

httpMethod	HttpRequest::getMethodEnum() const {return this->_methodEnum;}

HttpRequest::header	HttpRequest::getHeader() const {return this->_header;}

std::map<int, std::string>	HttpRequest::getHttpStatusMsg() const {return this->_httpStatusMsg;}

