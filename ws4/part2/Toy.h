//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220211
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#ifndef SDDS_TOY_H_
#define SDDS_TOY_H_
#include<string>
#include<iostream>
extern double tax;//HST
 namespace sdds {
	 
	 class Toy
	 {
		 size_t m_orderId = 0u; //order id of the toy
		 std::string m_name = { "" }; //name of toy
		 size_t m_noOfitem = 0u; //number of toys of this type to be ordered
		 double m_price = 0.0; //price of toy
		
	 public:
		 Toy() {}
		 void update(int numItems);
		 Toy(const std::string& toy);
		 friend std::ostream& operator<<(std::ostream& os, const Toy& src);
	 };

}
#endif
#pragma once
