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
		size_t m_widthField = 1; //specifies the length of the token
		static char m_delimiter; //separates the tokens in any given

	public:
		void setFieldWidth(size_t newWidth);//sets the field width of the current object to the value of parameter newWidth
		size_t getFieldWidth() const; //returns the field width of the current object
		std::string extractToken(const std::string& str, size_t& next_pos, bool&
			more);//extracts a token from string str referred to by the first parameter.
		static void setDelimiter(char newDelimiter);//sets the delimiter for this class to the character received
		static char getDelimiter();// returns the delimiter for this class.
	};
	
}
#endif
