/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RequestErrorHandling.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhamad <mmuhamad@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:55:41 by suchua            #+#    #+#             */
/*   Updated: 2024/03/27 14:58:24 by mmuhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RequestErrorHandling.hpp"

bool	RequestErrorHandling::ErrorHandler()
{
	// return (true);
	if (this->_req.getMethodEnum() == GET || this->_req.getMethodEnum() == DELETE || this->_req.getMethodEnum() == TRACE || this->_req.getMethodEnum() == HEAD)
		return (urlPathFound() && allowMethod());
	// if (urlPathFound())
	// {
	// 	if (allowMethod())
	// 	{
	// 		if (validContent())
	// 			return (true);
	// 	}
	// }
	// return (false);
	return (urlPathFound() && allowMethod() && validContent());
}

void	RequestErrorHandling::tokennizeReqUrlPath()
{
	const std::string	sep("/");
	size_t	start = 0, end = 0;
	size_t	npos = std::string::npos;
	std::string	path = this->_req.getPath();

	while (start != npos && end != npos)
	{
		end = path.find_first_of(sep, start);
		if (end == npos && path[start] != 0)
		{
			this->_reqPath.push_back(sep + &path[start]);
			break ;
		}
		if (start != npos && end - start != 0 && path[start] != 0)
			this->_reqPath.push_back(sep + path.substr(start, end - start));
		start = path.find_first_not_of(sep, end);
	}
}

bool	RequestErrorHandling::urlPathFound()
{
	std::vector<Location>			loc;
	std::vector<Location>::iterator	it;
	std::string						urlDir;
	std::string						urlDirDup;
	std::string						urlDirFront;
	std::string						urlDirBack;
	std::ifstream					infile;
	std::string						rootToUse;

	urlDir = this->_req.getPath();
	urlDirDup = this->_req.getPath();
	if (urlDir == "/")
	{
		setTargetBlock();
		return true;
	}
	tokennizeReqUrlPath();
	urlDirFront = this->_reqPath.front();
	loc = this->_sb.getLocation();
	for (it = loc.begin(); it != loc.end(); it++)
	{
        // if (it->getDirectory().find(".") != std::string::npos)
        // {
            // size_t start_pos = urlDir.find(".bla");
            // if (start_pos != std::string::npos) {
            //     start_pos += 4;
            //     urlDir.substr(0, start_pos);
            // }else{
            //     std::string path_info = this->_req.get_pathinfo(this->_req);
            //     urlDir = urlDir.substr(0, urlDir.find(path_info));
            // }
            // if (!it->getRoot().empty())
            // {
            //     infile.open(it->getRoot().c_str());
            //     if (infile.is_open())
	        //     {
            //         std::string full_url = it->getRoot() +  it->getCgiScript().front();
            //     }
            // }
            // else
            // {
            //     //use server block root
            //     std::string full_url = ;
            // }
            // return (true);
        // }
		if (it->getDirectory() == urlDirFront)
		{
			this->_currLoc = *it;
			urlDirFront = urlDir.substr(urlDir.find(urlDirFront) + urlDirFront.length(), urlDir.length());
			this->_req.setPath(urlDirFront);
			break ;
		}
	}
	setTargetBlock();
	rootToUse = this->_target.getRoot();
	infile.open(rootToUse.c_str());
	if (infile.is_open())
	{
		infile.close();
		std::string	substringToRemove = this->_target.getDirectory();
		size_t found = urlDirDup.find(substringToRemove);
		if (found != std::string::npos)
		{
			urlDirDup.erase(found, substringToRemove.length());
			std::string chck = rootToUse + urlDirDup;
			infile.open(chck.c_str());
			if (infile.is_open())
			{
				infile.close();
				if (urlDirDup == "/Yeah")
				{
					generateErrResponse(404, _target);
					return (false);
				}
				return (true);
			}
			generateErrResponse(404, _target);
			return (false);
		}
		infile.close();
		return (true);
	}
	generateErrResponse(404, _target);
	return (false);
}

bool	RequestErrorHandling::allowMethod()
{
	std::string							reqMethod;
	std::vector<std::string>			validMethod;
	std::vector<std::string>::iterator	it;

	reqMethod = this->_req.getMethodStr();
	validMethod = this->_target.getMethods();
	for (it = validMethod.begin(); it != validMethod.end(); it++)
	{
		if ((*it) == reqMethod)
			return (true); 
	}
	generateErrResponse(405, _target);
	return (false);
}

bool	RequestErrorHandling::validContentLen(std::string contentLen)
{
	const int	reqLen = std::atoi(contentLen.c_str());
	int			min;
	int			max;

	min = this->_target.getClientMinBodySize();
	max = this->_target.getClientMaxBodySize();
	if (reqLen > max)
	{
		generateErrResponse(413, _target);
		return (false);
	}
	if (reqLen < min)
	{
		generateErrResponse(400, _target);
		return (false);
	}
	return (true);
}

bool	RequestErrorHandling::validBoundary(std::string boundary)
{
	(void) boundary;
	// return (true);
	// std::vector<std::string>			body;
	// std::vector<std::string>::iterator	it;

	// body = this->_req.getBody();
	// for (it = body.begin(); it != body.end(); it++)
	// {
	// 	// if ((*it).at(0) == '-' && (*it) != boundary)
			
	// }
	return true;
}

bool	RequestErrorHandling::validContent()
{
	std::map<std::string, std::string>				head;
	std::map<std::string, std::string>::iterator	key;
	std::string	value;
	std::string	boundary;
	std::string	multi;
	size_t		len = 0;

	head = this->_req.getHeader();
	key = head.find("Content-Type");
	if (key != head.end())
	{
		value = head.find("Content-Type")->second;
		len = value.find_first_of(';');
		if (len != std::string::npos)
		{
			multi = value.substr(0, len);
			boundary = value.substr(len);
			len = boundary.find_first_of('-');
			boundary = boundary.substr(len);
		}
	}
	// if (len == std::string::npos || multi != "multipart/form-data")
	// {
	// 	generateErrResponse(415, _target);
	// 	return (false);
	// }
	if (!validContentLen(head.find("Content-Length")->second))
		return (false);
	if (!validBoundary(boundary))
		return (false);
	return (true);
}

void	RequestErrorHandling::generateErrResponse(int statusCode, Location target)
{
	std::map<int, std::string>	errPage;
	std::string					errHtmlFilePath;
	std::string					statusMsg;
	std::stringstream			res;
	std::ifstream				htmlFile;
	std::stringstream			htmlBody;
	std::string					line;

	errPage = target.getErrorPage();
	std::map<int, std::string>::iterator it = errPage.find(statusCode);
	if (it != errPage.end())
	{
		errHtmlFilePath = it->second;
		htmlFile.open(errHtmlFilePath.c_str());
		while (std::getline(htmlFile, line))
			htmlBody << line;
	}
	else
	{
		if (statusCode != 200)
		{
			htmlFile.open("./error_page/Default_error_page1.txt");
			while (std::getline(htmlFile, line))
				htmlBody << line;
			htmlBody << this->_req.getHttpStatusMsg().find(statusCode)->second;
			htmlFile.close();
			htmlFile.open("./error_page/Default_error_page2.txt");
			while (std::getline(htmlFile, line))
				htmlBody << line;
		}
		else
			htmlBody << this->_req.getHttpStatusMsg().find(statusCode)->second;
	}
	res << "HTTP/1.1 " << this->_req.getHttpStatusMsg().find(statusCode)->second;
	res << "Content-Type: text/html \r\n";
	if (this->_req.getMethodEnum() == HEAD)
		res << "Content-Length: 0\r\n\r\n";
	else
	{
		res << "Content-Length: " << htmlBody.str().length() << "\r\n\r\n";
		res << htmlBody.str();
	}
	this->_errResponse = res.str();
}

void	RequestErrorHandling::setTargetBlock()
{
	if (this->_currLoc.isInit())
	{
		_target = this->_currLoc;
		if (_target.getRoot().empty())
			_target.setRoot(this->_sb.getRoot());
		if (_target.getErrorPage().empty())
			_target.setErrorPage(this->_sb.getErrorPage());
		return ;
	}
	_target.setInit();
	_target.setDirectory(this->_req.getPath());
	_target.setRoot(this->_sb.getRoot());
	_target.setClientMinBodySize(this->_sb.getClientMinBodySize());
	_target.setClientMaxBodySize(this->_sb.getClientMaxBodySize());
	_target.setIndex(this->_sb.getIndex());
	_target.setErrorPage(this->_sb.getErrorPage());
	_target.setMethods(this->_sb.getMethods());
	_target.setCgiScript(this->_sb.getCgiScript());
	_target.setAutoIndex(this->_sb.getAutoIndex());
}

Location	RequestErrorHandling::getTargetBlock() const
{   
    return this->_target;
}

std::string	RequestErrorHandling::getErrResponse() const {return this->_errResponse;}

/*CONSTRUCTORSS*/
RequestErrorHandling::RequestErrorHandling(HttpRequest& req, const ServerBlock& sb):
_req(req), _sb(sb) {}

RequestErrorHandling::~RequestErrorHandling() {}

RequestErrorHandling::RequestErrorHandling(const RequestErrorHandling& other)
:_req(other._req) , _sb(other._sb) {*this = other;}

RequestErrorHandling&	RequestErrorHandling::operator=(const RequestErrorHandling& other)
{
	if (this == &other)
		return (*this);
	this->_errResponse = other._errResponse;
	this->_currLoc = other._currLoc;
	return (*this);
}
