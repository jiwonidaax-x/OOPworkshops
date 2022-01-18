//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220118
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#ifndef SDDS_FOODORDER_H_
#define SDDS_FOODORDER_H_
#include <iostream>

extern double g_taxrate, g_dailydiscount;

namespace sdds {

	class FoodOrder
	{		
		//name of customer ordering the food
		char m_name[10] = { '\0' };
		//description of the food
		char m_desc[25] = { '\0' };
		//price of the food
		double m_price = 0.00;
		//wheather or not the order is a daily special
		bool m_isSpecial;

	public:
		//defalut constructor
		FoodOrder() {}
		//query that displays 
		void display();
		//a modifier that receives istream reference
		std::istream& read(std::istream& is);

	};

}

#endif // !SDDS_FOODORDER_H_
