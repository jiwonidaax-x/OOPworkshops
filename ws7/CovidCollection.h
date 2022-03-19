//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220319
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#pragma once
#ifndef SDDS_COVIDCOLLECTION_H_
#define SDDS_COVIDCOLLECTION_H_
#include<string>
#include<vector>
#include<list>
namespace sdds {
	struct Covid {
		std::string m_country{};
		std::string m_city{ };
		std::string m_variant{};
		int m_numOfcase{ 0 };
		int m_year{ 0 };
		int m_deaths{ 0 };
	};
	class CovidCollection
	{
		std::vector <Covid> m_covid;
		int totalcase = 0;
		int totaldeath = 0;
	public:
		CovidCollection(const char* src);
		void display(std::ostream& out) const;
		void sort(const char* src);
		void cleanList();
		bool inCollection(std::string src) const;
		std::list<Covid> getListForCountry(std::string src) const;
		std::list<Covid> getListForVariant(std::string src) const;
	};

	std::ostream& operator<<(std::ostream& out, const Covid& theCovid);






}
#endif // !SDDS_COVIDCOLLECTION_H_

