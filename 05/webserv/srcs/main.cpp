/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhamad <mmuhamad@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:47:59 by suchua            #+#    #+#             */
/*   Updated: 2024/03/26 09:28:06 by mmuhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parse.hpp"
#include "Server.hpp"

int	main(int ac, char **av, char **env)
{
	if (ac != 1 && ac != 2)
	{
		std::cerr << "Error : Incorrect number of arguments\n";
		std::cerr << "Usage : ./webserv <path_to_config_file>\n";
		return (1);
	}

	std::string	ConfigFilename;

	if (ac == 1)
		ConfigFilename = "config/easy.conf";
	else
		ConfigFilename = av[1];
	try
	{
		Parse	parse(ConfigFilename);
		Server	server(parse.getBlock(), parse.getSocketFD(), env);
		server.startServer();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
		return (1);
	}
	return (0);
}
