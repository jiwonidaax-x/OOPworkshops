//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220317
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================

#include <string>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "Utilities.h"
#include "Station.h"

using namespace std;

namespace sdds {
	size_t Station::m_widthField = 0;
	int Station::id_generator = 1;

	Station::Station(const std::string& str)
	{
		m_id = id_generator;
		Utilities utility;
		size_t next_pos = 0;
		bool more = true;
		std::string temp{ "" };

		try
		{
			m_name= utility.extractToken(str, next_pos, more);
			m_serial = stoi(utility.extractToken(str, next_pos, more));
			m_current = stoi(utility.extractToken(str, next_pos, more));
			m_widthField = max(utility.getFieldWidth(), m_widthField);
			temp = utility.extractToken(str, next_pos, more);
			temp.erase(0, temp.find_first_not_of(" "));
			m_desc = temp;

		}
		catch (string& msg)
		{
			cout << msg;
		}
		id_generator++;
	}

	const std::string& Station::getItemName() const
	{
		return m_name;
	}

	size_t Station::getNextSerialNumber()
	{
		m_serial++;
		return m_serial - 1;
	}

	size_t Station::getQuantity() const
	{
		return m_current;
	}

	void Station::updateQuantity()
	{

		m_current == 0 ? m_current = 0 : --m_current;
	}

	void Station::display(std::ostream& os, bool full) const
	{
		os << right << setw(3) << setfill('0') << m_id << " | ";
		os << left << setw(Station::m_widthField) << setfill(' ') << m_name;
		os << " | " << right << setw(6) << setfill('0') << m_serial << " | ";

		if (full) {
			os << right << setw(4) << setfill(' ') << m_current << " | ";
			os << m_desc << endl;
		}
		else
			os << endl;
	}

}