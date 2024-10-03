/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhamad <mmuhamad@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 22:26:46 by suchua            #+#    #+#             */
/*   Updated: 2024/03/25 11:16:54 by mmuhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SERVER_BLOCK_HPP__
# define __SERVER_BLOCK_HPP__

# include "Webserv.hpp"
# include "Location.hpp"

class ServerBlock
{
	private:
		typedef std::string	str;
		str		name;
		int		port;
		str		root;
		str		index;
		int		clientMaxBodySize;
		int		clientMinBodySize;
		bool	autoIndex;
		std::map<int, std::string>	error_page;
		std::vector<std::string>	cgiScript;
		std::vector<str>			methods;
		std::vector<Location>		location;

	public:
		ServerBlock();
		~ServerBlock();
		ServerBlock(const ServerBlock& other);
		ServerBlock& operator=(const ServerBlock& other);

		void	addMethod(str method);
		void	addErrorPage(std::vector<std::string>::iterator &i);
		void	setCgiScript(std::vector<std::string>::iterator &i);
		void	addLocation(Location& location);
		void	setName(str name);
		void	setPort(int port);
		void	setRoot(str root);
		void	setIndex(str index);
		void	setClientMaxBodySize(int size);
		void	setClientMinBodySize(int size);
		void	setAutoIndex(str info);

		str		getName() const;
		int		getPort() const;
		str		getRoot() const;
		str		getIndex() const;
		int		getClientMaxBodySize() const;
		int		getClientMinBodySize() const;
		bool	getAutoIndex() const;
		std::map<int, std::string>	getErrorPage() const;
		std::vector<std::string>	getCgiScript() const;
		std::vector<str>			getMethods() const;
		std::vector<Location>		getLocation() const;

		empty	somethingEmpty();
		void	printMethods();
};

std::ostream&	operator<<(std::ostream& out, ServerBlock& sb);

#endif
