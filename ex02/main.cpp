/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 14:55:04 by rorollin          #+#    #+#             */
/*   Updated: 2026/09/16 17:42:06 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
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
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e)
	{
	}
}

int main()
{
	srand(time(0));
	for(int i=0; i< 5;i++)
	{
		std::cout << "--------------------------" << std::endl;
		Base *base;
		base = generate();
		identify(base);
		identify(*base);
		delete base;
	}

}
