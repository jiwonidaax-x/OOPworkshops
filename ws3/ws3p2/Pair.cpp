//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220204
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#include<iostream>
#include"Pair.h"
#include<iomanip>
using namespace std;
namespace sdds {
	void Pair::display(std::ostream& os)const
	{
		os <<setw(21)<<right<<m_key<< ":" <<left<<m_value;
	}

	std::ostream& operator<<(std::ostream& os, const Pair& pair)
	{
		pair.display(os);
		return os;
	}
}