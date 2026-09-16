/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 14:29:48 by rorollin          #+#    #+#             */
/*   Updated: 2026/09/16 14:50:10 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main(void)
{
	Data *data = new Data(8, "test");
	uintptr_t adress;
	Data *reinterpretData;
	std::cout << "Int stored in data : " << data->getInt() << std::endl;
	adress = Serializer::serialize(data);
	std::cout << "Adress of data : " << adress << std::endl;
	reinterpretData = Serializer::deserialize(adress);
	std::cout << "Int in reintrepreted data " << reinterpretData->getInt() << std::endl;

}
