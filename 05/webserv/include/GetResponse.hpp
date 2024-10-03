/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetResponse.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhamad <mmuhamad@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 23:00:18 by suchua            #+#    #+#             */
/*   Updated: 2024/05/06 15:49:56 by mmuhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __GET_RESPONSE_HPP__
# define __GET_RESPONSE_HPP__

# include "Webserv.hpp"
# include "ServerBlock.hpp"
# include "HttpRequest.hpp"
# include "RequestErrorHandling.hpp"
#include <sys/stat.h>

class	HttpRequest;
class	RequestErrorHandling;

class GetResponse
{
	typedef std::string	str;
	private:
		str		_response;
		str		_path;

		bool	isImgFile(std::string &file);
		str		sendFile(std::string &path, Location target, RequestErrorHandling err);
		// bool	isLocation(std::string &path, Location sb);
		str		locationRequest(std::string &path, Location target, RequestErrorHandling err);
	public:
		GetResponse(const HttpRequest req, const Location target, RequestErrorHandling err);
		~GetResponse();
		GetResponse(const GetResponse& other);
		GetResponse&	operator=(const GetResponse& other);
		
		str	getResponse() const;
};


#endif
