//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220211
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#pragma once
#ifndef SDDS_CHILD_H_
#define SDDS_CHILD_H_

#include<iostream>
#include "Toy.h"
#include <string>
//have attributes to store name and age
namespace sdds {
	class Child
	{
	    Toy* m_toys{ nullptr }; 
		size_t m_count = 0u;
		std::string m_name{ "" };
		int m_age=0;

	public:
		Child() {}
		Child(std::string name, int age, const Toy* toys[], size_t count);
		size_t size() const;


		//rule of 5
		Child(const Child& src);
		Child& operator=(const Child& src);
		Child(Child&& src);
		Child& operator=(Child&& src);
		~Child();

		
		friend std::ostream& operator<<(std::ostream& os, const Child& src);
	};




}
#endif // !SDDS_CHILD_H_

