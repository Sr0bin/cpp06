/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Displayer.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:35:23 by rorollin          #+#    #+#             */
/*   Updated: 2026/05/28 23:52:53 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Displayer.hpp"
#include <cctype>
#include <cstdlib>
#include <limits>
Displayer::Displayer(std::string &toDisplay) : _toDisplay(toDisplay)
{
	_type = fillType(_toDisplay);
	// switch (_type) {
	// 	case (CHAR) : case (INT) :
	// 		fillInt(_toDisplay);
	// 	case (FLOAT) : case (DOUBLE) :
	// 		fillFloat(_toDisplay);
	// 	case (UNDEFINED) :
	// 		_intValue = 0;
	// 		_floatValue = 0;
	// }
	
}

Displayer::Displayer(const Displayer &other) : _toDisplay(other.getDisplay())
{
	*this = other;
}

Displayer &Displayer::operator=(const Displayer &other)
{
	if (this != &other)
	{
		
	}
	return (*this);
}

Displayer::~Displayer(void)
{
	
}

const std::string &Displayer::getDisplay(void) const
{
	return (_toDisplay);
}

Displayer::e_type	Displayer::fillType(const std::string &str)
{
	if (str.size() == 0)
		return (UNDEFINED);
	if (str.size() == 1)
	{
		if (!std::isprint(str[0]))
			return (UNDEFINED);
		if (!std::isdigit(str[0]))
			return (CHAR);
	}
	{
		std::istringstream ss(str);
		int	val;

		if ((ss >> val) && ss.eof())
		{
			_intValue = val;
			return (INT);
		}
	}
	{
		std::istringstream ss(str);
		float	val;

		if (ss >> val)
		{
			_floatValue = val;
			if (ss.eof())
				return (DOUBLE);
			char end;
			if (ss >> end && (end == 'f' || end == 'F'))
			{
				char extra;
				if (!(ss >> extra))
					return (FLOAT);
			}
		}
	}
	switch (str) {
	
	}
	if (str == "+inf")
	{

	}
	return (UNDEFINED);
}

void Displayer::displayChar(void)
{
	
	std::cout << "char : ";
	switch (_type)
	{
		case (CHAR):
			std::cout << static_cast<int>(*_toDisplay.c_str()) << std::endl;
			break;
		case (INT) :
			if (_intValue > std::numeric_limits<unsigned char>::max() || _intValue < std::numeric_limits<unsigned char>::min())
			{
				std::cout << "impossible \n";
				break;
			}
			if (!std::isprint(static_cast<char>(_intValue)))
			{
				std::cout << "Non displayable \n";
				break;
			}
			std::cout << static_cast<char>(_intValue) << std::endl;
			break;

		case (FLOAT) : case (DOUBLE) :
			if (static_cast<int>(_floatValue) > std::numeric_limits<char>::max()
				|| static_cast<int>(_floatValue) < std::numeric_limits<char>::min())
			{
				std::cout << "impossible \n";
				break;
			}
			std::cout << static_cast<char>(_floatValue) << std::endl;
			break;

		case (UNDEFINED) :
			std::cout << "impossible \n";
			break;
	}
}
