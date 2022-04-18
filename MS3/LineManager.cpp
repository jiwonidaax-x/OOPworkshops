//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220410
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <set>
#include "LineManager.h"
#include "Utilities.h"

using namespace std;

namespace sdds
{
   LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
      Utilities util;
      string    eachLine = "", cur_Wstation = "", next_Wstation = "";
      size_t    pos = 0u;
      bool      more = false;
      vector<string> v_cur_Wstation, v_next_Wstation;
      
      ifstream  read_file(file);

      if (!read_file)
         throw string("\n***Failed to open file ") + string(file) + string(" ***\n");

      else {
         while (std::getline(read_file, eachLine)) {
            if (!eachLine.empty()) {
               cur_Wstation = util.extractToken(eachLine, pos, more);
               v_cur_Wstation.push_back(cur_Wstation);

               next_Wstation = !more ? "" : util.extractToken(eachLine, pos, more);
               v_next_Wstation.push_back(next_Wstation);

               auto cur_err_check = any_of(stations.begin(), stations.end(), [=](Workstation* first_src) {
                  if (first_src->getItemName() == cur_Wstation) {
                     if (!next_Wstation.empty()) {
                        auto next_err_check = any_of(stations.begin(), stations.end(), [=](Workstation* sec_src) {
                           if (sec_src->getItemName() == next_Wstation) {
                              first_src->setNextStation(sec_src);
                              return true;
                           }
                           else
                              return false;
                           });

                        if (!next_err_check) throw string("\n\n***Next Workstation is not found***\n\n");
                        else if (cur_Wstation == next_Wstation) throw string("\n\n***Next Workstation is not found***\n\n");
                     }
                     activeLine.push_back(first_src);
                     return true;
                  }

                  else
                     return false;
                  });

               if (!cur_err_check)
                  throw string("\n\n***Something went wrong***\n\n");
            }
         }
         read_file.close();

         for_each(activeLine.begin(), activeLine.end(), [=](Workstation* first_src) {
            auto start = any_of(stations.begin(), stations.end(), [=](Workstation* sec_src) {
               if (sec_src->getNextStation() == first_src)
                  return true;
               else
                  return false;
               });

            if (!start)
               m_firstStation = first_src;
            });

         m_cntCustomerOrder = g_pending.size();
      }
   }


   void LineManager::reorderStations()
   {
         const Workstation* ws = m_firstStation;
         size_t i{ 0 };
         do
         {
           activeLine[i++] = const_cast<Workstation*>(ws);
            ws = ws->getNextStation();
         } while (ws != nullptr);
   }
   

   bool LineManager::run(std::ostream& os) {
      static size_t count = 0u;

      os << "Line Manager Iteration: " << ++count << endl;

      if (!g_pending.empty()) {
         *activeLine.front() += move(g_pending.front());
         g_pending.pop_front();
      }

      for (auto src : activeLine)
         src->fill(os);

      for (auto src : activeLine)
         src->attemptToMoveOrder();

      return m_cntCustomerOrder == g_completed.size() + g_incomplete.size();
 
   }

  
   void LineManager::display(std::ostream& os) const {
      for_each(activeLine.begin(), activeLine.end(), [&](Workstation* src) {
         src->display(os);
         });
   }
}
