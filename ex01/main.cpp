/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 14:29:48 by rorollin          #+#    #+#             */
/*   Updated: 2026/09/16 14:51:42 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main(void)
{
	Data *data = new Data;
	uintptr_t address;
	data->number = 8;
	data->string = "test";
	Data *reinterpretData;
	std::cout << "Int stored in data : " << data->number << std::endl;
	address = Serializer::serialize(data);
	std::cout << "Address of data : 0x" << std::hex << address << std::dec << std::endl;
	reinterpretData = Serializer::deserialize(address);
	std::cout << "Int in reinterpreted data : " << reinterpretData->number << std::endl;
	std::cout << "Original pointer : " << data << std::endl;
	std::cout << "Deserialized pointer : " << reinterpretData << std::endl;
	std::cout << (reinterpretData == data ? "Same pointer" : "Different pointer") << std::endl;
	delete data;

}
