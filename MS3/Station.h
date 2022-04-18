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
		std::string m_name{ "" };//name of the item
		std::string m_desc{ "" };//description
		size_t m_serial{ 0u };//starting serial number
		size_t m_current{ 0u };//quantity in stock

		static size_t m_widthField; //the maximum number of characters
		static int id_generator; // a variable used to generate IDs for new instances of type Station
	public:
		Station(const std::string&);
		const std::string& getItemName() const;// returns the name of the current Station object
		size_t getNextSerialNumber();//returns the next serial number to be used on the assembly line and increments m_serialNumber
		size_t getQuantity() const;//returns the remaining quantity of items in the Station object
		void updateQuantity();//subtracts 1 from the available quantity; should not drop below 0.
		void display(std::ostream& os, bool full) const;//inserts information about the current object into stream os.
	};
}
#endif