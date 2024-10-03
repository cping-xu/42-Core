/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:22:05 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/25 12:40:17 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string> // std::string
# include <stack> // stack<>
# include <stdexcept> // std::runtime_error()

class RPN
{
	public:
		typedef int result_type;
		static result_type ResolveExpression(const std::string &line);

	private:
		typedef result_type token_type;
		typedef unsigned char op_type;

		RPN();
		~RPN();
		RPN(const RPN &rhs);
		RPN& operator=(const RPN &rhs);

		static std::stack<token_type> stack1;

		static const int op_size = 4;
		static const struct operations
		{
			op_type symbol;
			token_type (*calc)(const token_type &lhs, const token_type &rhs);
		} operations[op_size];

		static void PopOperandsTokens(token_type &lhs, token_type &rhs);
		static void PushToken(token_type token);

		static void Operate(op_type symbol);

		static token_type Sum(const token_type &lhs, const token_type &rhs);
		static token_type Sub(const token_type &lhs, const token_type &rhs);
		static token_type Mul(const token_type &lhs, const token_type &rhs);
		static token_type Div(const token_type &lhs, const token_type &rhs);
};

#endif
