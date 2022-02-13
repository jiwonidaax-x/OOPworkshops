//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220211
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#include <iostream>
#include <iomanip>
#include"Toy.h"
using namespace std;
double tax{ 0.13 };
namespace sdds {
	
	void Toy::update(int numItems)
	{
		m_noOfitem = numItems; //updates the number of items
	}
	Toy::Toy(const std::string& toy)
	{
		std::string temp{ toy };
		size_t index{ 0u };

		//ID:NAME:NUM:PRICE
		
		//orderID
		temp.erase(0, temp.find_first_not_of(" ")); //remove beginning spaces
		index = temp.find(":");
		m_orderId=std::stoi(temp.substr(0, index));//stoi translate str->integer
		temp.erase(0, index + 1);

		//Name
		temp.erase(0, temp.find_first_not_of(" "));
		index = temp.find(":");
		m_name = temp.substr(0,index);
		m_name.erase(m_name.find_last_not_of(" ")+1);
		temp.erase(0, index + 1);

		//orderID
		temp.erase(0, temp.find_first_not_of(" ")); //remove beginning spaces
		index = temp.find(":");
		m_noOfitem = std::stoi(temp.substr(0, index));//stoi translate str->integer
		temp.erase(0, index + 1);

		//
		temp.erase(0, temp.find_first_not_of(" ")); //remove beginning spaces
		index = temp.find("\n");
		m_price = std::stod(temp.substr(0, index));//stod translate str->double
		temp.erase(0, index + 1);

	}
	std::ostream& operator<<(std::ostream& os, const Toy& src)
	{
		double subtotal = src.m_noOfitem * src.m_price;
		double m_tax = subtotal * tax;
		double m_total = subtotal + m_tax;
		os << "Toy" << setw(8) << src.m_orderId << right << ":" << setw(18) << right << src.m_name;
		os << setw(3) << right << src.m_noOfitem << " items" << setw(8) << right <<src.m_price;
		os << "/item  subtotal:" << setw(7) << right;
		os.setf(ios::fixed);
		os.precision(2); 
		os<< subtotal << " tax:" << setw(6) << right << m_tax;
		os << " total:" << setw(7) << right << m_total<<endl;
		return os;
	}


}