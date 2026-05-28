/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Displayer.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:34:07 by rorollin          #+#    #+#             */
/*   Updated: 2026/05/28 18:51:45 by rorollin         ###   ########.fr       */
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
	Displayer(std::string &to_display);
	Displayer(const Displayer &other);
	Displayer &operator=(const Displayer &other);
	~Displayer(void);
	
	const std::string &getDisplay(void) const;

	void displayChar(void);

private:
	enum e_type
	{
		CHAR = 0,
		INT,
		FLOAT,
		DOUBLE,
		UNDEFINED
	};

	e_type	fillType(const std::string &str);
	long	convertFloat(const std::string &str);

	const std::string	&_toDisplay;
	long	_intValue;
	double	_floatValue;
	e_type	_type;

	
};

#endif
