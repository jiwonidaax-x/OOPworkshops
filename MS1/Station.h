//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220317
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================

#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <iostream>

namespace sdds {
	class Station
	{
		int m_id{ 0 };
		std::string m_name{""};
		std::string m_desc{""};
		size_t m_serial{ 0u };
		size_t m_current{ 0u };

		static size_t m_widthField;
		static int id_generator;
	public:
		Station(const std::string& ); 
		const std::string& getItemName() const; 
		size_t getNextSerialNumber(); 
		size_t getQuantity() const; 
		void updateQuantity(); 
		void display(std::ostream& os, bool full) const;
	};
}
#endif