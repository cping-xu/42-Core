/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:57:30 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/19 18:59:14 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef IDENTITY_HPP
# define IDENTITY_HPP

# include <iostream>

class Base
{
	public:
		Base();
		virtual ~Base();
		Base * generate(void);
		void identify(Base* p);
		void identify(Base& p);

	private:
};

class A : public Base
{
	public:
	A();
	~A();
};

class B : public Base
{
	public:
	B();
	~B();
};

class C : public Base
{
	public:
	C();
	~C();
};

#endif
