//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220128
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#ifndef SDDS_PROTEINDATABASE_H_
#define SDDS_PROTEINDATABASE_H_
#include <string>
namespace sdds
{
	class ProteinDatabase
	{
		std::string* m_msg = nullptr;
		size_t m_noOfstr = { 0u };
	public:
		ProteinDatabase() {};
		~ProteinDatabase();
		ProteinDatabase(const char* name); //one argument constructor
		ProteinDatabase(const ProteinDatabase& src);//copy constructor
		ProteinDatabase& operator=(const ProteinDatabase& src);//copy assignment
		ProteinDatabase(ProteinDatabase&& src);//move constructor
		ProteinDatabase& operator=(ProteinDatabase&& src);//move assignment
		size_t size();
		std::string operator[](size_t)const;

	};
}



#endif // !SDDS_PROTEINDATABASE_H_

#pragma once
