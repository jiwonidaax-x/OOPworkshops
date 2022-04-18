//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220410
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H

#include <vector>
#include "Workstation.h"

namespace sdds
{
   class LineManager
   {
      //the collection of workstations for the current assembly line.   
      std::vector<Workstation*> activeLine;  
      //the total number of CustomerOrder objects
      size_t m_cntCustomerOrder{ 0u }; 
      //points to the first active station on the current line
      Workstation* m_firstStation; 

   public:
      //this constructor receives the name of the file that identifies the active stations on the assembly line 
      LineManager(const std::string& file, const std::vector<Workstation*>& stations);
      //this modifier reorders the workstations present in the instance variable
      void reorderStations();
      //this modifier performs one iteration of operations on all of the workstations
      bool run(std::ostream& os); 
      //display
      void display(std::ostream& os) const; 
   };
}
#endif // !SDDS_LINEMANAGER_H
