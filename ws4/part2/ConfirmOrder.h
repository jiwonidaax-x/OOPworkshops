//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220211
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
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
