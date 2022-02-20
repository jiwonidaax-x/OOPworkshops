#pragma once
#ifndef SDDS_CENTRALUNIT_H_
#define SDDS_CENTRALUNIT_H_
#include"Job.h"
#include <iostream>
#include <fstream>
#include<utility>
#include <exception>
#include<string>
namespace sdds {

	template<typename T>
	class CentralUnit
	{
		//desc type of central unit
		std::string m_type{ "" };

		//array pointer to individual units of type T
		T** m_items{ nullptr };
		Job* m_jobs[4];
		size_t m_size = 0u; //unit
		size_t m_count = 0u;//job

	public:
		std::ostream& log = std::cout;

		CentralUnit(const CentralUnit& src) {
			throw 0;
		}
		CentralUnit& operator=(const CentralUnit&) = delete;
		CentralUnit(CentralUnit&& src)
		{
			operator=(move(src));
		}
		CentralUnit& operator=(CentralUnit&& src)
		{
			if (m_items)
			{
				delete[] m_items;
				m_items = nullptr;
			}
			m_size = src.m_size;
			m_count = src.m_count;
			for (size_t i = 0; i < m_count; i++)
			{
				m_jobs[i] = src.m_jobs[i];
			}
			for (size_t i = 0; i < m_size; i++)
			{
				m_items[i] = src.m_items[i];
			}

			src.m_size = 0u;
			src.m_count = 0u;
			src.m_jobs = nullptr;
			src.m_items = nullptr;



		}//move assignment


		CentralUnit(const char* name, const char* init)
		{
			m_type = name;

			std::ifstream in;
			in.open(init);

			if (in.is_open() == false) {

				throw std::invalid_argument("File cannot open.");

			}
			else
			{
				std::string temp{ "" };

				do
				{
					m_size++;
					std::getline(in, temp,'\n');				
					
					
				} while (in);
		
				m_size = 5;
		
				m_items = new T * [m_size];

				in.clear();
				in.seekg(std::ios::beg);

				while (!in.eof())
				{
					size_t index{ 0u };
					std::string brand;
					std::string code;
					int capacity;

					std::getline(in, temp);

					static int i = 0;
					temp.erase(0, temp.find_first_not_of(" "));
					index = temp.find("|");
					brand = temp.substr(0, index);
					brand.erase(brand.find_last_not_of(" ") + 1);
					temp.erase(0, index + 1);

					temp.erase(0, temp.find_first_not_of(" "));
					index = temp.find("|");
					code = temp.substr(0, index);
					code.erase(code.find_last_not_of(" ") + 1);
					temp.erase(0, index + 1);

					temp.erase(0, temp.find_first_not_of(" ")); //remove beginning spaces
					index = temp.find("\n");
					try
					{
						capacity = std::stoi(temp.substr(0, index));
					}
					catch (...)
					{
						capacity = 1;
					}

					temp.erase(0, index + 1);

					m_items[i] = new T(this, brand, code, capacity);
					i++;

				}
				in.close();

			}

		}
		
		void run()
		{					
			for (size_t i = 0; i < m_size; i++)
			{

				if (!*m_items[i])
				{
					if (m_count>0)
					{
						*m_items[i] += m_jobs[m_count-1];
						m_jobs[m_count - 1] = nullptr;
						m_count--;
					}
				}

			}		
			for (size_t i = 0; i < m_size; i++)
			{
				if (*m_items[i])
				{
					m_items[i]->run();
				}
				
			}
			
		}

		bool has_jobs()
		{
			bool ok=false;
			for (size_t i = 0; i < m_size; i++)
			{
				if (*m_items[i])
				{
					ok = true;
				}
			}
			return ok || m_count > 0;
		}

		size_t get_available_units()
		{
			size_t j = 0u;
			for (size_t i = 0; i < m_size; i++)
			{
				if (!*m_items[i])
				{
					j++;
				}
			}
			return j;
		}

		CentralUnit<T>& operator+=(std::string name)
		{
			if (m_count < 4)
			{
				m_jobs[m_count] = new Job(name);
				m_count++;
			}
			else
			{
				throw 0;
			}
			return *this;
		}

		~CentralUnit()
		{
			if (m_items)
			{
				delete[] m_items;
				m_items = nullptr;
			}
		}

	};

}
#endif // !SDDS_CENTRALUNIT_H_

