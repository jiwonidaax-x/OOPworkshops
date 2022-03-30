//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220330
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {
		std::vector<T> list;
	public:

		GeneratingList(){}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the 
		//      valadity of SIN No's
		bool luhnAlgorithm(std::string sin)
		{
			size_t nDigits = sin.length();
			size_t sum = size_t(sin[nDigits - 1]);
			int parity = (nDigits - 2) % 2;
			for (size_t i = 0; i < nDigits-2; i++)
			{
				int digit = int(sin[i]);
				if (1%2==parity)
				{
					digit = digit * 2;
				}
				if (digit>9)
				{
					digit = digit - 9;
				}
				sum = sum + digit;
			}
			return((sum % 10) == 0);
				
		}


		//TODO: Overload the += operator with a smart pointer
		// as a second operand.
		void operator+=(const std::unique_ptr<T>& src) {
			list.push_back(*src);
		}

		

		//TODO: Overload the += operator with a raw pointer
		// as a second operand.
		void operator+=(const T* src) {
			list.push_back(*src);
		}

		
		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H
