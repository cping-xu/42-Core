/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:22:10 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/02 13:09:07 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <fstream>

void	ft_replace(std::string &line, std::string find, std::string replace)
{
	size_t pos = 0;
	pos = line.find(find, pos);
	while (pos != std::string::npos)
	{
		line.erase(pos, find.length());
		line.insert(pos, replace);
		pos = line.find(find, pos);
	}
}

char	*ft_outname(char *infile)
{
	return (strcat(infile, ".replace"));
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Invalid Argument Count !" << std::endl;
		return (1);
	}
	std::string find = av[2];
	std::string replace = av[3];
	std::ifstream infile(av[1]);	//ifstream = input file stream
	if (!(infile))
	{
		std::cout << "Invalid Infile !" << std::endl;
		return(1);
	}
	char *outname = ft_outname(av[1]);
	std::ofstream outfile(outname);		//ofstream = output file stream
	if (!(outfile))
	{
		std::cout << "Invalid Outfile !" << std::endl;
		infile.close();
		return (1);
	}
	if (infile.is_open())
	{
		std::string line;
		while (std::getline(infile, line))
		{
			ft_replace(line, find, replace);
			outfile << line << std::endl;
		}
	}
	outfile.close();
	infile.close();
	return (0);
}
