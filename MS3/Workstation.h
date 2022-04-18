//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220410
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <iostream>
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

namespace sdds
{
   //holds the orders to be placed onto the assembly line at the first station.
   extern std::deque<CustomerOrder> g_pending;
   //holds the orders that have been removed from the last station and have been completely filled.
   extern std::deque<CustomerOrder> g_completed;
   //holds the orders that have been removed from the last station and could not be filled completely.
   extern std::deque<CustomerOrder> g_incomplete;

   class Workstation : public Station
   {
      //is a double-ended-queue with CustomerOrders entering the back and exiting the front.
      std::deque<CustomerOrder> m_orders;     
      //a pointer to the next Workstation on the assembly line.
      Workstation* m_pNextStation{ nullptr }; 

   public:
      Workstation(const std::string& src) : Station(src) {};
      Workstation(const Workstation&) = delete;
      Workstation(Workstation&&) = delete;
      Workstation& operator=(const Workstation&) = delete;
      Workstation& operator=(Workstation&&) = delete;
      //this modifier fills the order at the front of the queue if there are CustomerOrders in the queue
      void fill(std::ostream& os);  
      //attempts to move the order order at the front of the queue to the next station in the assembly line
      bool attemptToMoveOrder();    
      //this modifier stores the address of the referenced Workstation object in the pointer to the m_pNextStation
      void setNextStation(Workstation* station);    
      //this query returns the address of next Workstation
      Workstation* getNextStation() const;  
      //display
      void display(std::ostream& os) const;   
      Workstation& operator+=(CustomerOrder&& newOrder);
   };
}
#endif // !SDDS_WORKSTATION_H
