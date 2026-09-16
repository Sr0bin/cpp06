/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 14:55:04 by rorollin          #+#    #+#             */
/*   Updated: 2026/09/16 17:00:04 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void)
{
	switch (rand() % 3) {
		case (0):
			return new A;
		case (1):
			return new B;
		case (2):
			return new C;
	}
	return new A;
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p) != 0)
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p) != 0)
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p) != 0)
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try {
		A a;
		a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try {
		B b;
		b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try {
		C c;
		c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e)
	{
	}
}

int main()
{
	Base *base;
	srand(time(0));
	base = generate();
	identify(base);
	identify(base);

}
