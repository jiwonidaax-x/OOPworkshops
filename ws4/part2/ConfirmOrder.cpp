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
#include"ConfirmOrder.h"
using namespace std;

namespace sdds {

	ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy)
	{
		//size_t cnt = 0u;
		bool ok = false;
		for (auto i = 0u; i < m_count; i++)
		{
			if (m_toys[i] == &toy)
			{
				ok = true;
				m_toys[i] = nullptr;
				//cnt++;
			}
		}
		if (ok)
		{
			const Toy** temp = new const Toy * [m_count - 1u];
			for (auto i = 0u, j = 0u; i < m_count; i++)
			{
				if (m_toys[i] != nullptr)
				{
					temp[j] = m_toys[i];
					j++;
				}
			}
			delete[] m_toys;
			m_toys = nullptr;
			m_toys = temp;
			m_count -= 1;


		}
		return*this;
	}
	ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy)
	{
		bool ok = false;
		for (auto i = 0u; i < m_count; i++)
		{
			if (m_toys[i] == &toy)
			{
				ok = true;
			}
		}
		if (ok == false)
		{
			const Toy** temp = new const Toy * [m_count + 1u];
			for (auto i = 0u; i < m_count; i++)
			{
				temp[i] = m_toys[i];
			}
			temp[m_count] = &toy;
			if (m_toys)
			{
				delete[] m_toys;
				m_toys = nullptr;
			}
			m_toys = temp;
			m_count++;
		}


		return*this;
	}
	//rule of 5

	//copy constructor
	ConfirmOrder::ConfirmOrder(const ConfirmOrder& src)
	{
		operator=(src);
	}

	//copy assignment operator
	ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& src)
	{
		//check this is not same with src
		if (this != &src)
		{
			//if there are values in m_toys delete values
			if (m_toys)
			{
				delete[] m_toys;
				m_toys = nullptr;
			}

			//deep copy
			m_count = src.m_count;
			m_toys = new const Toy * [m_count];
			for (auto i = 0u; i < m_count; i++)
			{
				m_toys[i] = src.m_toys[i];
			}
		}
		return *this;
	}

	//move constructor
	ConfirmOrder::ConfirmOrder(ConfirmOrder&& src)
	{
		operator=(move(src));
	}

	//move assignment operator
	ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& src)
	{
		if (this != &src)
		{
			if (m_toys)
			{
				delete[] m_toys;
				m_toys = nullptr;
			}

			m_count = src.m_count;
			m_toys = src.m_toys;

			src.m_count = 0u;
			src.m_toys = nullptr;
		}

		return *this;
	}
	ConfirmOrder::~ConfirmOrder()
	{
		if (m_toys)
		{
			delete[] m_toys;
			m_toys = nullptr;
		}

	}

	std::ostream& operator<<(std::ostream& os, const ConfirmOrder& src)
	{
		os << "--------------------------" << endl;
		os << "Confirmations to Send" << endl;
		os << "--------------------------" << endl;

		if (src.m_count == 0u)
		{
			os << "There are no confirmations to send!" << endl;
		}
		else
		{
			for (auto i = 0u; i < src.m_count; ++i)
				os << *src.m_toys[i];
		}

		os << "--------------------------" << endl;

		return os;
	}
}


