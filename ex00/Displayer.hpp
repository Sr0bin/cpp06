/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Displayer.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:34:07 by rorollin          #+#    #+#             */
/*   Updated: 2026/06/01 17:32:56 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DISPLAYER_HPP
# define DISPLAYER_HPP

#include <string>
#include <iostream>
#include <ostream>
#include <cerrno>
#include <sstream>

class Displayer
{
public:
	Displayer(const std::string &to_display);
	Displayer(const Displayer &other);
	Displayer &operator=(const Displayer &other);
	~Displayer(void);
	
	const std::string &getDisplay(void) const;

	void displayChar(void);
	void displayInt(void);
	void displayFloat(void);
	void displayDouble(void);

private:
	enum e_type
	{
		CHAR = 0,
		INT,
		FLOAT,
		DOUBLE,
		UNDEFINED
	};
	
	enum e_floatType
	{
		PINF = 0,
		MINF,
		PINFF,
		MINFF,
		NAN_D,
		NAN_F,
		OTHER
	};

	e_type	fillType(const std::string &str);
	long	convertFloat(const std::string &str);
	e_floatType hashFloatType(const std::string &str);
	bool	isNan(void) const;
	bool	isInf(void) const;


	std::string	_toDisplay;
	long	_intValue;
	double	_floatValue;
	e_type	_type;

	
};

#endif
