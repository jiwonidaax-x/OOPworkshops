//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220204
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#ifndef SDDS_PAIR_H_
#define SDDS_PAIR_H_

namespace sdds {

	class Pair
	{
		std::string m_key{};
		std::string m_value{};
	public:
		const std::string& getKey() { return m_key; }
		const std::string& getValue() { return m_value; }
		Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value }{};
		Pair() {}

		void display(std::ostream& os)const;

	};

	std::ostream& operator<<(std::ostream& os, const Pair& pair);

}
#endif // !SDDS_PAIR_H_

#pragma once
