/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:23:50 by rorollin          #+#    #+#             */
/*   Updated: 2026/09/16 14:14:59 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"
#include "Displayer.hpp"

void	ScalarConverter::convert(const std::string &string)
{
	Displayer	disp(string);

	disp.displayChar();
	disp.displayInt();
	disp.displayFloat();
	disp.displayDouble();
}

ScalarConverter::ScalarConverter(void)
{
	
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
	{
		
	}
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	
}
