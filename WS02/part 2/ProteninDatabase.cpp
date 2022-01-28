//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220128
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#include<fstream>
#include"ProteinDatabase.h"
using namespace std;
namespace sdds {

	ProteinDatabase::~ProteinDatabase()
	{
		if (m_msg)
		{
			delete[] m_msg;
			m_msg = nullptr;
		}
	}
	ProteinDatabase::ProteinDatabase(const char* name)
	{
		if (name)
		{
			string str;

			ifstream file(name);

			if (file)
			{
				while (!file.eof())
				{
					getline(file, str, '\n');
					if (str[0] == '>')
					{
						str = "";
						getline(file, str, '\n');
						++m_noOfstr;
						str = "";
					}
				}
				m_msg = new string[m_noOfstr];

				str = "";
				file.clear();
				file.seekg(0, ios::beg);

				int i = -1;
				while (!file.eof())
				{
					getline(file, str, '\n');
					if (str[0] == '>')
					{
						++i;
						str = "";
					}
					else
					{
						m_msg[i] += str;
						str = "";

					}
				}

			}
		}

	}
	ProteinDatabase::ProteinDatabase(const ProteinDatabase& src)
	{
		operator=(src);
	}
	ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& src)
	{
		if (this != &src)
		{
			if (m_msg)
			{
				delete[] m_msg;
				m_msg = nullptr;
			}
			m_noOfstr = src.m_noOfstr;
			m_msg = new string[m_noOfstr];
			for (size_t i = 0; i < m_noOfstr; i++)
			{
				m_msg[i] = src.m_msg[i];
			}

		}
		return*this;
	}
	ProteinDatabase::ProteinDatabase(ProteinDatabase&& src)
	{
		operator=(move(src));
	}
	ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& src)
	{
		if (this != &src)
		{
			if (m_msg)
			{
				delete[] m_msg;
				m_msg = nullptr;
			}
			m_noOfstr = src.m_noOfstr;
			src.m_noOfstr = 0u;
			m_msg = src.m_msg;
			src.m_msg = nullptr;
		}

		return*this;
	}
	size_t ProteinDatabase::size()
	{
		return m_noOfstr;
	}
	std::string ProteinDatabase::operator[](size_t num)const
	{
		string copy = "";
		if (num < m_noOfstr)
		{
			copy = m_msg[num];
		}
		return copy;
	}
}
