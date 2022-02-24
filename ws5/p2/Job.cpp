//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220218
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#include <iostream>
#include <iomanip>
#include <string>
#include "Job.h"
#include <execution>

using namespace std;

namespace sdds {

	Job::Job(const std::string& title)
	{
		m_title = title;
		m_unit = (title.length() % 10) + 1;
		m_remain = m_unit;
		isActive = false;
	}
	Job::Job() {
		isActive = false;
	}
	bool Job::is_active()
	{
		return isActive ? true : false;
	}

	bool Job::is_complete()
	{
		return m_remain == 0 ? true : false;
	}

	std::string Job::name()
	{
		return m_title;
	}


	void Job::operator()(size_t unit)
	{
	
		if (unit > m_remain)
		{
			isActive = false;	
			m_remain = 0;
			throw std::underflow_error("");

		}
	
		else
		{
			m_remain -= unit;

			if (m_remain == 0)
			{
				isActive = false;
			}
			if (m_remain != 0)
			{
				isActive = true;
			}
            

		}
		
	}


	std::ostream& Job::display(std::ostream& os)const
	{
		os << "`" << m_title << "` " << "[" << setw(2) << right << setfill('0') << m_remain << "/" << setw(2) << right << setfill('0') << m_unit << " remaining]";
		return os;
	}

	std::ostream& operator<<(std::ostream& os, const Job& src)
	{
		return src.display(os);
	}

}