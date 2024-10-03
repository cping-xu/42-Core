/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpRequest.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhamad <mmuhamad@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 23:24:59 by suchua            #+#    #+#             */
/*   Updated: 2024/05/07 12:27:25 by mmuhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	__HTTP_REQUEST_HPP__
# define __HTTP_REQUEST_HPP__

# include <cstdio>
# include <signal.h>
# include "Webserv.hpp"
# include "ServerBlock.hpp"
# include "GetResponse.hpp"
# include "PutResponse.hpp"
# include "PostResponse.hpp"
# include "DeleteResponse.hpp"
# include "RequestErrorHandling.hpp"

// class	GetResponse;
// class	PutResponse;

class HttpRequest
{
	typedef std::string			str;
	typedef std::map<str, str>	header;
    typedef std::vector<str>	body;
	
	private:
		str					_full;
		str					_methodStr;
		str					_path;			//url dir
		body				_body;
		header				_header;
		httpMethod			_methodEnum;
		std::map<int, str>	_httpStatusMsg;
		char**				_envp;
		int					_CurrEnvp;
	public:
		HttpRequest();
		HttpRequest(const HttpRequest& other);
		HttpRequest&	operator=(const HttpRequest& other);		
		~HttpRequest();

		void			setfull(str full);
		void			setMethod(str method);
		void			setPath(str path);
		void			setBody(str line);
		void			setHeader(str head, str content);
		str				getfull() const;
		str				getMethodStr() const;
		httpMethod		getMethodEnum() const;
		body			getBody() const;
		header			getHeader() const;
		str				getPath() const;
		std::map<int, str>	getHttpStatusMsg() const;
        std::string	    get_pathinfo(const HttpRequest req);

		void			populateEnvp(std::string input);

		void			parseHttpRequest(const str& req);
		str				generateHttpResponse(const str& req, const int clientSocket, const ServerBlock sb, char **env);
};

#endif
