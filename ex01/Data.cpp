/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 14:31:28 by rorollin          #+#    #+#             */
/*   Updated: 2026/09/16 14:35:35 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Data.hpp"

Data::Data(void) : _placeholderInt(42), _placeholderString("Default")
{
	
}

Data::Data(int inputInt, std::string string) : _placeholderInt(inputInt), _placeholderString(string)
{
	
}
int Data::getInt() const
{
	return (_placeholderInt);
}

std::string Data::getString() const
{
	return (_placeholderString);
}

Data::Data(const Data &other)
{
	*this = other;
}

Data &Data::operator=(const Data &other)
{
	if (this != &other)
	{
		_placeholderInt = other._placeholderInt;
		_placeholderString = other._placeholderString;
	}
	return (*this);
}

Data::~Data(void)
{
	
}
