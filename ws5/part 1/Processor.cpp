#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
#include"Processor.h"

using namespace std;

namespace sdds {

	Processor::Processor(CentralUnit<Processor>* host, std::string brand, std::string code, size_t power)
	{
		m_host = host;
		m_brand = brand;
		m_code = code;
		m_power = power;
	}

	void Processor::run()
	{	
		if (m_host)
		{
			if (get_current_job()->is_complete())
			{
				m_current = nullptr;				
			}
			else
			{
				try
				{
					(*m_current)(m_power);
				}
				catch (std::underflow_error& e)
				{
					m_host->log << "Processed over quota for " << *m_current << endl;
				}
			}
		}
		
	}

	 Processor::operator bool() const
	{
		return m_current ? true : false;
		 
	}

	Processor& Processor::operator+=(Job*& job)
	{
		if (m_current == nullptr)
		{
			m_current = job;
		}
		return *this;
	}

	Job* Processor::get_current_job() const
	{
		return m_current;		
	}

} 
