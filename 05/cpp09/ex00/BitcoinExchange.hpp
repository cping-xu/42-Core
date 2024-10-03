/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:21:34 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/17 16:22:50 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>

class BitcoinExchange {
public:
	BitcoinExchange(const std::string &filename);
	void ProcessInput(const std::string &filename);
	
private:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &rhs);

	std::map<std::string, double> data_;
	double GetExchangeRate(const std::string &date);
	bool ValidateDate(const std::string &date);
	bool ValidateValue(const double &value);
};

#endif
