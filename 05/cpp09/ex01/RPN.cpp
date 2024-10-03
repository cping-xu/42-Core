/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:21:57 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/25 12:41:37 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <cctype> // std::isdigt(), std::isspace()

std::stack<RPN::token_type> RPN::stack1;

const struct RPN::operations RPN::operations[op_size] = {
	{ '+', &RPN::Sum },
	{ '-', &RPN::Sub },
	{ '*', &RPN::Mul },
	{ '/', &RPN::Div }
};

RPN &RPN::operator=(RPN const &other) {
	if (this == &other) 
		return (*this);
	return *this;
}

RPN::~RPN() {
}

RPN::result_type RPN::ResolveExpression(const std::string &line)
{
	if (line.empty()) {
		return (0);
	}
	for (std::string::const_iterator iter = line.begin(); iter != line.end(); ++iter)
	{
		if (std::isspace(*iter))
			continue;
		else if (std::isdigit(*iter))
			PushToken(static_cast<token_type>(*iter - '0'));
		else
			Operate(static_cast<op_type>(*iter));
	}
	if (stack1.size() > 1)
		throw::std::runtime_error("Operations ended and stack has more than 1 item");
	result_type ret = stack1.top();
	stack1 = std::stack<token_type>();
	return (ret);
}

void RPN::PopOperandsTokens(token_type &lhs, token_type &rhs)
{
	if (stack1.size() < 2)
		throw std::runtime_error("RPN stack must have at less 2 items to do operations");
	rhs = stack1.top();
	stack1.pop();
	lhs = stack1.top();
	stack1.pop();
}

void RPN::PushToken(token_type token)
{
	stack1.push(token);
}

void RPN::Operate(op_type symbol)
{
	for (short i = 0; i < op_size; ++i)
	{
		if (operations[i].symbol == symbol)
		{
			token_type lhs = 0, rhs = 0;
			PopOperandsTokens(lhs, rhs);
			token_type res = (*(operations[i].calc))(lhs, rhs);
			PushToken(res);
			return;
		}
	}
	throw std::runtime_error("Encoutered an undefined operator");
}

RPN::token_type RPN::Sum(const token_type &lhs, const token_type &rhs)
{
	return (lhs + rhs);
}
RPN::token_type RPN::Sub(const token_type &lhs, const token_type &rhs)
{
	return (lhs - rhs);
}
RPN::token_type RPN::Mul(const token_type &lhs, const token_type &rhs)
{
	return (lhs * rhs);
}
RPN::token_type RPN::Div(const token_type &lhs, const token_type &rhs)
{
	if (rhs == 0)
		throw std::runtime_error("Number couldn't divide by 0");
	return (lhs / rhs);
}
