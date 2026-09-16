/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Displayer.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:35:23 by rorollin          #+#    #+#             */
/*   Updated: 2026/09/16 14:19:45 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Displayer.hpp"
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <limits>
Displayer::Displayer(const std::string &toDisplay) :
	_toDisplay(toDisplay), _intValue(0), _floatValue(0)
{
	_type = fillType(_toDisplay);
}

Displayer::Displayer(const Displayer &other)
{
	*this = other;
}

Displayer &Displayer::operator=(const Displayer &other)
{
	if (this != &other)
	{
		_toDisplay = other._toDisplay;
		_intValue = other._intValue;
		_floatValue = other._floatValue;
		_type = other._type;
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

Displayer::e_floatType Displayer::hashFloatType(const std::string &str)
{
	if (str == "+inf")
		return (PINF);
	if (str == "-inf")
		return (MINF);
	if (str == "+inff")
		return (PINFF);
	if (str == "-inff")
		return (MINFF);
	if (str == "nan")
		return (NAN_D);
	if (str == "nanf")
		return (NAN_F);
	return (OTHER);
}
bool	Displayer::isNan(void) const
{
	return (_floatValue != _floatValue);
}

bool	Displayer::isInf(void) const
{
	return (!isNan() && (_floatValue > std::numeric_limits<double>::max()
			|| _floatValue < -std::numeric_limits<double>::max()));
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
		{
			_intValue = static_cast<unsigned char>(str[0]);
			return (CHAR);
		}
	}
	if (std::isspace(static_cast<unsigned char>(str[0])))
		return (UNDEFINED);
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
		double	val;

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
	switch(hashFloatType(str))
	{
		case (PINF) :
			_floatValue = std::numeric_limits<double>::infinity();
			return (DOUBLE);
		case (MINF) :
			_floatValue = - std::numeric_limits<double>::infinity();
			return (DOUBLE);
		case (PINFF) :
			_floatValue = std::numeric_limits<float>::infinity();
			return (FLOAT);
		case (MINFF) :
			_floatValue = - std::numeric_limits<float>::infinity();
			return (FLOAT);
		case (NAN_D) :
			_floatValue = std::numeric_limits<double>::quiet_NaN();
			return (DOUBLE);
		case (NAN_F) :
			_floatValue = std::numeric_limits<float>::quiet_NaN();
			return (FLOAT);
		case (OTHER) :
			break;
	}
	return (UNDEFINED);
}

void Displayer::displayChar(void)
{
	std::cout << "char: ";
	switch (_type)
	{
		case (CHAR) :
			std::cout << "\'" << static_cast<char>(_intValue) << "\'" << std::endl;
			break;
		case (INT) :
			if (_intValue < 0 || _intValue > std::numeric_limits<unsigned char>::max())
			{
				std::cout << "impossible" << std::endl;
				break;
			}
			if (!std::isprint(static_cast<int>(_intValue)))
			{
				std::cout << "Non displayable" << std::endl;
				break;
			}
			std::cout << "\'" << static_cast<char>(_intValue) << "\'" << std::endl;
			break;
		case (FLOAT) : case (DOUBLE) :
			if (isNan() || isInf() || _floatValue < 0
				|| _floatValue > std::numeric_limits<unsigned char>::max())
			{
				std::cout << "impossible" << std::endl;
				break;
			}
			if (!std::isprint(static_cast<int>(_floatValue)))
			{
				std::cout << "Non displayable" << std::endl;
				break;
			}
			std::cout << "\'" << static_cast<char>(_floatValue) << "\'" << std::endl;
			break;
		case (UNDEFINED) :
			std::cout << "impossible" << std::endl;
			break;
	}
}

void Displayer::displayInt(void)
{
	std::cout << "int : ";
	switch (_type)
	{
		case (INT) : case (CHAR) :
			std::cout << static_cast<int>(_intValue) << std::endl;
			break;
		case (FLOAT) : case (DOUBLE) :
			if (isNan() || isInf()
				|| _floatValue > std::numeric_limits<int>::max()
				|| _floatValue < std::numeric_limits<int>::min())
			{
				std::cout << "impossible" << std::endl;
				break;
			}
			std::cout << static_cast<int>(_floatValue) << std::endl;
			break;
		case (UNDEFINED) :
			std::cout << "impossible" << std::endl;
			break;
	}
}

void Displayer::displayFloat(void)
{
	std::cout << "float : ";
	switch (_type)
	{
		case (INT) : case (CHAR) :
			std::cout << std::fixed << std::setprecision(1)
				<< static_cast<float>(_intValue) << "f" << std::endl;
			break;
		case (FLOAT) : case (DOUBLE) :
			if (isNan() || isInf())
			{
				std::cout << static_cast<float>(_floatValue) << "f" << std::endl;
				break;
			}
			std::cout << std::fixed << std::setprecision(1)
				<< static_cast<float>(_floatValue) << "f" << std::endl;
			break;
		case (UNDEFINED) :
			std::cout << "impossible" << std::endl;
			break;
	}
}

void Displayer::displayDouble(void)
{
	std::cout << "double : ";
	switch (_type)
	{
		case (INT) : case (CHAR) :
			std::cout << std::fixed << std::setprecision(1)
				<< static_cast<double>(_intValue) << std::endl;
			break;
		case (FLOAT) : case (DOUBLE) :
			if (isNan() || isInf())
			{
				std::cout << _floatValue << std::endl;
				break;
			}
			std::cout << std::fixed << std::setprecision(1)
				<< _floatValue << std::endl;
			break;
		case (UNDEFINED) :
			std::cout << "impossible" << std::endl;
			break;
	}
}
