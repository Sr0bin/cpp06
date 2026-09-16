/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 14:23:41 by rorollin          #+#    #+#             */
/*   Updated: 2026/09/16 14:34:40 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DATA_HPP
# define DATA_HPP
# include <string>

class Data
{
public:
	Data(void);
	Data(int inputInt, std::string string);
	Data(const Data &other);
	Data &operator=(const Data &other);
	~Data(void);
	int getInt() const;
	std::string getString() const;

private:
	int _placeholderInt;
	std::string _placeholderString;
	
};

#endif
