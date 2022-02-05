//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220204
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_
#include "Pair.h"

namespace sdds{
	template<typename T,size_t capacity>
	class Collection 
	{   	
		static size_t noOfelement;

	public:
	
		T arr[capacity]{};
		Collection() {}
		size_t size() {
			return noOfelement;
		}
		const void display()
		{
			std::cout << "----------------------" << std::endl;
			std::cout << "| " << "Collection Content" << " |" << std::endl;
			std::cout << "----------------------" << std::endl;

			for (size_t i = 0; i < noOfelement; i++)
			{
				std::cout << arr[i] << std::endl;
			}
			std::cout << "----------------------" << std::endl;
		}
		 virtual bool add(const T& item)
		{
			bool ok = false;
			if (noOfelement<capacity)
			{				
				arr[noOfelement] = item;
				noOfelement++;
				ok = true;

			}
			return ok;
		}

		T operator[](unsigned index);
	};

	template<typename T, size_t capacity>
	T Collection<T, capacity>::operator[](unsigned index) {
		T obj;
		if (index<capacity||index>0)
		{
			obj = arr[index];
		}
		return obj;
	}

	template<typename T, size_t capacity>
	size_t Collection<T,capacity>::noOfelement = 0;
	

	template<>
	class Collection<Pair, 100> :public Pair
	{
		static size_t noOfelement;

	public:

		Pair arr[100];
		
		Collection() {
			set();
		}

		Collection& set() {
			for (size_t i = 0; i < 100; i++)
			{
				arr[i] = Pair("No Key", "No Value");
			}
			return *this;
		}
		
		size_t size() {
			return noOfelement;
		}
		const void display()
		{
			std::cout << "----------------------" << std::endl;
			std::cout << "| " << "Collection Content" << " |" << std::endl;
			std::cout << "----------------------" << std::endl;

			for (size_t i = 0; i < noOfelement; i++)
			{
				std::cout << arr[i] << std::endl;
			}
			std::cout << "----------------------" << std::endl;
		}
		 virtual bool add(const Pair& item)
		{
			bool ok = false;
			
			if (noOfelement < 100)
			{
				arr[noOfelement] = item;
				noOfelement++;
				ok = true;

			}
			return ok;
		}

		Pair operator[](unsigned index);

	};


	Pair Collection<Pair, 100>::operator[](unsigned index) {
		Pair obj;
		if (index < 100 || index>0)
		{
			obj = arr[index];
		}
		return obj;
	}


	size_t Collection<Pair,100>::noOfelement = 0;	
}


#endif // !SDDS_COLLECTION_H_

#pragma once
