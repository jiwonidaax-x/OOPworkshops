//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220319
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#include"CovidCollection.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;
namespace sdds {

  
      CovidCollection::CovidCollection(const char* src) {

         try
         {
            ifstream readfile(src);
            Covid    covid;
            string   temp;

            auto extract_data = [](string& src, int idx) {
               string result = src.substr(0, idx);

               src = src.substr(idx);
               result.erase(0, result.find_first_not_of(' '));
               result.erase(result.find_last_not_of(' ') + 1);

               return result;
            };
            auto extract_lastdata = [](string& src) {
               int idx = src.find("\n");
               string result = src.substr(0, idx);
               result.erase(0, result.find_first_not_of(' '));
               result.erase(result.find_last_not_of(' ') + 1);

               return result;
            };
            if (!readfile)
               throw "Error";
            else
            {
               while (getline(readfile, temp)) {
                  covid.m_country = extract_data(temp, 25);
                  covid.m_city = extract_data(temp, 25);
                  covid.m_variant = extract_data(temp, 25);
                  covid.m_year = stoi(extract_data(temp, 5));
                  if (covid.m_year < 0)
                  {
                     covid.m_year = -1;
                  }
                  covid.m_numOfcase =stoi( extract_data(temp, 5));   
                  covid.m_deaths = stoi(extract_lastdata(temp));

                  m_covid.push_back(covid);
                  totalcase += covid.m_numOfcase;
                  totaldeath += covid.m_deaths;
               }
            }
            
         }
         catch (const std::exception&)
         {
            std::cout << "error" << std::endl;
         }
      }

      void CovidCollection::sort(const char* src)
      {
         if (src=="country")
         {
            std::sort(m_covid.begin(), m_covid.end(), [](Covid& covid1, Covid& covid2) {
               return covid1.m_country < covid2.m_country;
               });
         }
         else if (src == "variant")
         {
            std::sort(m_covid.begin(), m_covid.end(), [](Covid& covid1, Covid& covid2) {
               return covid1.m_variant< covid2.m_variant;
               });
         }
         else if (src == "cases")
         {
            std::sort(m_covid.begin(), m_covid.end(), [](Covid& covid1, Covid& covid2) {
               return covid1.m_numOfcase < covid2.m_numOfcase;
               });
         }
         else if (src == "deaths")
         {
            std::sort(m_covid.begin(), m_covid.end(), [](Covid& covid1, Covid& covid2) {
               return covid1.m_deaths< covid2.m_deaths;
               });
         }

      }
      void CovidCollection::cleanList()
      {
         for_each(m_covid.begin(), m_covid.end(), [](Covid& covid) {
            covid.m_variant = covid.m_variant == "[None]" ? "" : covid.m_variant;
            });

      }
      bool CovidCollection::inCollection(std::string src) const
      {
         return any_of(m_covid.begin(), m_covid.end(), [src](const Covid& covid) {
            return covid.m_variant == src;
            });

      }
      std::list<Covid> CovidCollection::getListForCountry(std::string src) const
      {
         std::list<Covid> result;

         copy_if(m_covid.begin(), m_covid.end(), back_inserter(result), [src](const Covid& covid) {
            return covid.m_country== src;
            });

         return result;

      }
      std::list<Covid> CovidCollection::getListForVariant(std::string src) const
      {
         std::list<Covid> result;

         copy_if(m_covid.begin(), m_covid.end(), back_inserter(result), [src](const Covid& covid) {
            return covid.m_variant == src;
            });

         return result;

      }

      void CovidCollection::display(std::ostream& out) const {

         for_each(m_covid.begin(), m_covid.end(), [&out](const Covid& covid) {
            out << covid << endl;
            });
         out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
         
         out << "| " << right<<setw(78) <<"Total Cases Around the World: " << setw(6) << totalcase << std::right << " |\n";
         out << "| " << right << setw(78) << "Total Deaths Around the World: " << setw(6) << totaldeath << std::right << " |\n";
         out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');

      }

      std::ostream& operator<<(std::ostream& out, const Covid& theCovid)
      {
         out << "| " << left << setw(20) << setfill(' ') << theCovid.m_country;
         out << " | " << setw(15) << setfill(' ') << theCovid.m_city;
         out << " | " << setw(20) << setfill(' ') << theCovid.m_variant;
        if (theCovid.m_year < 0)
        {
               out << " | " << right << setw(9) << setfill(' ');
        }
        else
        {
           out << " | " << right << setw(6) << theCovid.m_year;
        }
         out << " | " << right << setw(5) << theCovid.m_numOfcase;
         out << " | " << setw(3) << theCovid.m_deaths << " |";

         return out;
      }


}