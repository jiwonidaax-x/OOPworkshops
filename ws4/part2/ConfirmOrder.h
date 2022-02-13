#pragma once
#ifndef SDDS_CONFIRMORDER_H_
#define SDDS_CONFIRMORDER_H_
#include<iostream>
#include "Toy.h"
#include <string>
namespace sdds {

	class ConfirmOrder
	{
		const Toy** m_toys = { nullptr };
		size_t m_count = 0u;
	public:

		ConfirmOrder() {}

		ConfirmOrder& operator-=(const Toy& toy);
		ConfirmOrder& operator+=(const Toy& toy);
		//rule of 5

		ConfirmOrder(const ConfirmOrder& src);
		ConfirmOrder& operator=(const ConfirmOrder& src);
		ConfirmOrder(ConfirmOrder&& src);
		ConfirmOrder& operator=(ConfirmOrder&& src);
		~ConfirmOrder();


		friend std::ostream& operator<<(std::ostream& os, const ConfirmOrder& src);
	};








}




#endif // !SDDS_CONFIRMORDER_H_
