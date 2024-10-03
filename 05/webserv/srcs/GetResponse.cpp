/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetResponse.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhamad <mmuhamad@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 00:20:17 by suchua            #+#    #+#             */
/*   Updated: 2024/05/12 13:23:26 by mmuhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GetResponse.hpp"
#include <algorithm>
#include <dirent.h>

// the main GET method function
GetResponse::GetResponse(const HttpRequest req, const Location target, RequestErrorHandling err)
{
	this->_path = req.getPath();

	if (isImgFile(this->_path))
	{
		this->_response = sendFile(this->_path, target, err);
		return;
	}
	this->_response = locationRequest(this->_path, target, err);
}

// check whether the GET request is an image file
bool	GetResponse::isImgFile(std::string &file)
{
	const std::string	type[8] = {".avif", ".gif", ".jpeg", ".png", ".svg", ".csv", ".jpg", ".ico"};
	std::string			check;

	size_t dotPos = file.find_last_of(".");
    if (dotPos != std::string::npos) {
        check = file.substr(dotPos);
    }

	for (size_t i = 0; i < 8; i++)
	{
		if (type[i] == check)
			return (true);
	}
	return (false);
}

std::string readFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        return "";
    }

    std::ostringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

// send img file
std::string GetResponse::sendFile(std::string &path, Location target, RequestErrorHandling err)
{
	std::string file = path.substr(1);
	std::string type ;
	std::string tmp ;
	std::string httpResponse;
	size_t 		dotPos = file.find_last_of(".");
	
	if (dotPos != std::string::npos) {
		type = file.substr(dotPos);
	}

    if (path == "/favicon.ico")
    {
        err.generateErrResponse(404, target);
        return(err.getErrResponse());
    }
    

	int numberOfSlashes = std::count(file.begin(), file.end(), '/');
	if (numberOfSlashes > 0)
	{
		size_t slashPos = file.find_first_of("/");
		tmp = file.substr(0, slashPos);
		if (tmp != "img" || tmp != "error_page")
			file = file.substr(slashPos + 1);
	}

    std::string svgFilePath;
    if (!target.getRoot().empty())
    {
        svgFilePath = target.getRoot();
        svgFilePath += "/";
	    svgFilePath += file;
    }
    else
    {
        svgFilePath += file;
    }

	if (type != ".csv" && type != ".txt")
	{
		// Open the img file
		std::string gifData = readFile(svgFilePath);
        if (gifData.empty())
        {
            err.generateErrResponse(404, target);
            return(err.getErrResponse());
        }

		// Construct the HTTP response
		httpResponse = "HTTP/1.1 200 OK\r\n";
		if (type == ".svg" || type == ".xml")
			httpResponse += "Content-Type: image/svg+xml\r\n";
		else
		{
			httpResponse += "Content-Type: image/";
			httpResponse += type;
			httpResponse += "\r\n";
		}
		
		httpResponse += "Content-Length: " + std::to_string(gifData.size()) + "\r\n";
		httpResponse += "\r\n";
		httpResponse += gifData;
	}
	else
	{
		std::ifstream svgFile(svgFilePath.c_str());

		if (!svgFile.is_open()) {
			err.generateErrResponse(404, target);
            return(err.getErrResponse());
		}

		std::string str;
		char		c;
		while (!svgFile.eof() && svgFile >> std::noskipws >> c){
			str += c;
		}
		svgFile.close();

		std::stringstream	len;
		len << str.length();

		httpResponse = "HTTP/1.1 200 OK\r\n";
		httpResponse += "Content-Type: text/html\r\n";
		httpResponse += "Content-Length: " + len.str() + "\r\n";
		httpResponse += "\r\n";
		httpResponse += str;
				
	}
	return (httpResponse);
}

// execute in Location
std::string	GetResponse::locationRequest(std::string &path, Location target ,RequestErrorHandling err)
{
	std::string						httpResponse, str, dir;
	std::ifstream					input_file;
	char							c;
	
    if (!target.getRoot().empty())
    {
        dir = target.getRoot().substr(2);
	    dir += path;
    }
    else
    {
        dir = path;
    }
    int slashend = 0;
    if(dir[dir.length() - 1] == '/')
        slashend = 1;
    if(dir[dir.length() - 1] != '/')
        dir += '/';
    DIR* in = opendir(dir.c_str());
    if (!in)
    {
        goto label;
    }
    closedir(in);
    if (target.getAutoIndex() && target.getIndex().empty())
    {
        std::string parentDirPath;

        const int maxPathLength = 100;

        char directoryPath[maxPathLength];

        if (getcwd(directoryPath, sizeof(directoryPath)) == NULL) {
            err.generateErrResponse(500, target);
            return(err.getErrResponse());
        }

        std::string directoryPath2 = std::string(directoryPath) + dir;
        
        size_t pos2 = directoryPath2.rfind(target.getRoot().substr(2));

        if (pos2 == directoryPath2.size())
            directoryPath2 = dir;
        else
            directoryPath2 = directoryPath2.substr(pos2);

        // size_t pos = directoryPath2.rfind('/');
        // if (pos != std::string::npos) {
            // parentDirPath = directoryPath2.substr(0, pos);
        // }
        // else
        // {
        //     parentDirPath = "";
        // }
        // parentDirPath = target.getRoot();
        parentDirPath = dir;
        DIR* dir = opendir(directoryPath2.c_str());
        if (!dir) {
            std::cerr << "Failed to open directory." << std::endl;
            err.generateErrResponse(404, target);
            return(err.getErrResponse());
        }
        // if (directoryPath2) autoindex/
        std::string dirList;
        struct dirent* entry;
        while ((entry = readdir(dir)) != NULL) {   
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                std::string fullPath = std::string(directoryPath2) + std::string(entry->d_name);
                int count = 0;
                for (size_t i = 0; i < fullPath.length(); ++i) {
                    if (fullPath[i] == '/') {
                        ++count;
                    }
                }
                DIR* dir1 = opendir(fullPath.c_str());
                if (dir1)
                {
                    if (count > 1 && strncmp(fullPath.c_str(), target.getRoot().c_str(), target.getRoot().size()))
                    {    
                        while (count > 1)
                        {
                            pos2 = fullPath.find('/');
                            fullPath = fullPath.substr(pos2 + 1);
                            count--;
                        }
                    }
                    else
                    {
                        pos2 = fullPath.find('/');
                        fullPath = fullPath.substr(pos2 + 1);
                    }
                    closedir(dir1);
                }
                else
                {
                    if (strncmp(fullPath.c_str(), target.getRoot().c_str(), target.getRoot().size()) && count < 2)
                    {
                        fullPath = fullPath.substr(target.getRoot().size() - 1 );
                    }
                    while (count > 1)
                    {
                        
                        pos2 = fullPath.find('/');
                        fullPath = fullPath.substr(pos2 + 1);
                        count--;
                    }
                }
                if (slashend == 1 && count == 1)
                {
                    pos2 = fullPath.find('/');
                    fullPath = fullPath.substr(pos2 + 1);
                    count--;
                }
                dirList += "<tr><td valign=\"top\"></td><td><a href=\"" + fullPath + "\">" + std::string(entry->d_name) + "</a></td></tr>\n";
            }
        }
        closedir(dir);
        
        std::string htmlContent = "<!DOCTYPE html><html><head><title>Directory Listing</title></head><body><h1>Directory Listing</h1><table><tr><th valign=\"top\"></th><th style=\"text-align: left;\"><a href=\"Name\">Name</a></th></tr><tr><th colspan=\"2\"><hr></th></tr><tr><td valign=\"top\"></td><td><a href=\"$PARENT_DIR\">Parent Directory</a></td></tr>$DIR_LIST<tr><th colspan=\"2\"><hr></th></tr></table></body></html>";
        
        size_t pos1 = htmlContent.find("$DIR_LIST");
        if (pos1 != std::string::npos) {
            htmlContent.replace(pos1, strlen("$DIR_LIST"), dirList);
        }

        pos1 = htmlContent.find("$PARENT_DIR");
        if (pos1 != std::string::npos)
		{
            if (parentDirPath[parentDirPath.length() - 1] == '/')
			{
                parentDirPath = parentDirPath.substr(0, parentDirPath.size() - 1);
			}
            size_t pos = parentDirPath.rfind('/');
            if (pos != std::string::npos) 
            {
                parentDirPath = parentDirPath.substr(0, pos);
			}
			int count = 0;
			for (size_t i = 0; i < parentDirPath.length(); ++i) {
				if (parentDirPath[i] == '/') {
					++count;
				}
			}
			if (count > 0)
			{
				size_t cpos = parentDirPath.find('/');
				parentDirPath = parentDirPath.substr(cpos);
			}
            std::string chck2 = target.getRoot().substr(2);
            int par = chck2.find('/');
            std::string chck = parentDirPath.substr(0, par);
            if (parentDirPath == chck)
            {
                parentDirPath = "/";
            }
            
            htmlContent.replace(pos1, strlen("$PARENT_DIR"), parentDirPath);
        }

        httpResponse = "HTTP/1.1 200 OK\r\n";
        httpResponse += "Content-Type: text/html\r\n";
        httpResponse += "Content-Length: " + std::to_string(htmlContent.size()) + "\r\n";
        httpResponse += "\r\n";
        httpResponse += htmlContent;
        return (httpResponse);
    }

    if (!target.getIndex().empty())
    {
        std::string ind = target.getRoot() + "/" + target.getIndex();
        
        input_file.open(ind.c_str());
        if (!input_file)
        {
            err.generateErrResponse(404, target);
            return(err.getErrResponse());
        }
        while (!input_file.eof() && input_file >> std::noskipws >> c){
            str += c;
            if(str.size() == 0)
                break;
        }
        input_file.close();
        std::stringstream	len;
        len << str.length();

        httpResponse = "HTTP/1.1 200 OK\r\n";
        httpResponse += "Content-Type: text/html\r\n";
        httpResponse += "Content-Length: " + len.str() + "\r\n";
        httpResponse += "\r\n";
        httpResponse += str;
        return (httpResponse);
    }

    err.generateErrResponse(403, target);
    return(err.getErrResponse());
    
    label:
    std::string ind = target.getRoot() + "/" + path.c_str();
	input_file.open(ind.c_str());
	if (!input_file)
	{
        err.generateErrResponse(404, target);
        return(err.getErrResponse());
	}
	while (!input_file.eof() && input_file >> std::noskipws >> c){
		str += c;
		if(str.size() == 0)
			break;
	}
	input_file.close();
	
	std::stringstream	len;
	len << str.length();

	httpResponse = "HTTP/1.1 200 OK\r\n";
	httpResponse += "Content-Type: text/html\r\n";
	httpResponse += "Content-Length: " + len.str() + "\r\n";
	httpResponse += "\r\n";
	httpResponse += str;
	return (httpResponse);
}

std::string	GetResponse::getResponse() const {return this->_response;}

GetResponse::~GetResponse() {}

GetResponse::GetResponse(const GetResponse& other) {*this = other;}

GetResponse&	GetResponse::operator=(const GetResponse& other)
{
	if (this == &other)
		return (*this);
	this->_response = other._response;
	return (*this);
}
