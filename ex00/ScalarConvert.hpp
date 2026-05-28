/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:21:11 by rorollin          #+#    #+#             */
/*   Updated: 2026/05/28 15:33:16 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVERT_HPP
# define SCALARCONVERT_HPP

#include <string>
class ScalarConvert
{

public:
	static void	convert(std::string string);

private:
	ScalarConvert(void);
	ScalarConvert(const ScalarConvert &other);
	ScalarConvert &operator=(const ScalarConvert &other);
	~ScalarConvert(void);
	
};

#endif
