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
#include"Child.h"
using namespace std;

namespace sdds {

	Child::Child(std::string name, int age, const Toy* toys[], size_t count)
	{
		m_count = count;
		m_age = age;
		m_name = name;
		m_toys = new Toy [m_count];
		for (auto i = 0u; i < m_count; i++)
		{
			m_toys[i] = *toys[i];
		}
	}
	size_t Child::size() const
	{
		return m_count;
	}

	//rule of 5
	Child::Child(const Child& src)
	{
		operator=(src);
	}
	Child& Child::operator=(const Child& src)
	{
		if (this != &src)
		{
			if (m_toys)
			{
				delete[] m_toys;
				m_toys = nullptr;
			}

			if (src.m_count > 0)
			{
				m_count = src.m_count;
				m_age = src.m_age;
				m_name = src.m_name;
				m_toys = new Toy[m_count];
				for (auto i = 0; i < m_count; i++)
				{
					m_toys[i] = src.m_toys[i];
				}
			}
		}
		return *this;
	}
	Child::Child(Child&& src)
	{
		operator=(move(src));
	}
	Child& Child::operator=(Child&& src)
	{
		if (this != &src)
		{
			
			if (m_toys)
			{
				delete[] m_toys;
				m_toys = nullptr;
			}

			m_count = src.m_count;
			m_age = src.m_age;
			m_name = src.m_name;
			m_toys = src.m_toys;

			src.m_count = 0u;
			src.m_age = 0;
			src.m_name = { "" };
			src.m_toys = nullptr;


		}
		return *this;
	}
	Child::~Child()
	{
		if (m_toys)
		{
			delete[] m_toys;
			m_toys = nullptr;
		}
	}


	std::ostream& operator<<(std::ostream& os, const Child& src)
	{
	    static int cnt = 0;
		os << "--------------------------" << endl;
		os << "Child " << ++cnt<<": " << src.m_name << " " << src.m_age << " years old:" << endl;
		os << "--------------------------" << endl;

		if (src.m_count == 0u)
			os << "This child has no toys!" << endl;
		else {
			for (auto i = 0u; i < src.m_count; ++i)
				os << src.m_toys[i];
		}

		os << "--------------------------" << endl;

		return os;
	}
}

