//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220317
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================

#pragma once
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <iostream>

namespace sdds {
	class Utilities {
		size_t m_widthField = 1;
		static char m_delimiter;

	public:
		void setFieldWidth(size_t newWidth); 
		size_t getFieldWidth() const; 
		std::string extractToken(const std::string& str, size_t& next_pos, bool&
			more); 

		static void setDelimiter(char newDelimiter); 
		static char getDelimiter(); 
	};
}
#endif