//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220118
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<iostream>
#include<iomanip>
#include"foodorder.h"

double g_taxrate, g_dailydiscount=0.0;
using namespace std;

namespace sdds {

	//query that displays 
	void FoodOrder::display()
	{
		static int counter = 1;

		
		
		cout << setw(2)<<left << setfill(' ') << counter << ". ";

		if (m_name == nullptr || m_name[0] == '\0')
		{
			cout << "No Order" << endl;
		}
		else {
			cout << setw(10) << left << setfill(' ') << m_name << "|";
			cout << setw(25) << left << setfill(' ') << m_desc << "|";
			cout.setf(ios::fixed);
			cout.precision(2);

			m_price = m_price+(m_price* g_taxrate);
			cout << setw(12)<< left << setfill(' ') << m_price << "|";
			if (m_isSpecial == true)
			{
				cout << setw(13) << right << setfill(' ') << m_price - g_dailydiscount<<endl;
			}
			else {
				cout << endl;
			}
			
		}
		
		counter++;
	}
	//a modifier that receives istream reference
	std::istream& FoodOrder::read(std::istream& is)
	{
		char name[10]={'\0'};
		char desc[25] = {'\0'};
		double price = 0.00;
		char special = '\0';


		if (is)
		{
			is.get(name, 10, ',');
			is.ignore();
			is.get(desc, 25, ',');
			is.ignore();
			is >> price;
			is.ignore();
			is >> special;
			
			m_price = price;
				strcpy(m_name, name);
				strcpy(m_desc, desc);
				//m_price = price+(price * g_taxrate);

				if (special == 'Y')
				{
					m_isSpecial = true;
				}
				else if (special=='N')
				{
					m_isSpecial = false;
				}
			
		}
	
		return is;
	}


}