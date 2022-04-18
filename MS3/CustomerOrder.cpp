//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220403
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#include <algorithm>
#include <vector>
#include <iomanip>
#include <iostream>
#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;
namespace sdds {

   size_t CustomerOrder::m_widthField = 0u;


 
   CustomerOrder::CustomerOrder(const std::string& src)
   {
      Utilities util;
      bool more = false;
      size_t pos = 0u;

      if (!src.empty()) {
         m_name = util.extractToken(src, pos, more);

         if (more) m_product = util.extractToken(src, pos, more);

         m_cntItem = std::count(src.begin(), src.end(), util.getDelimiter()) - 1;

         if (m_cntItem) m_listItem = new Item * [m_cntItem];

         for (auto i = 0u; i < m_cntItem && more; ++i)
            m_listItem[i] = new Item(util.extractToken(src, pos, more));

         CustomerOrder::m_widthField = max(util.getFieldWidth(), CustomerOrder::m_widthField);
      }
   }


   CustomerOrder::CustomerOrder(const CustomerOrder& src)
   {
      throw false;
   }

   CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
   {
      *this = std::move(src);
   }

   CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept
   {

      if (this != &src) {
         if (m_listItem) {
            for (auto i = 0u; i < m_cntItem; ++i)
               delete m_listItem[i];

            delete[] m_listItem;
         }

         m_name = src.m_name;
         m_product = src.m_product;
         m_cntItem = src.m_cntItem;
         m_listItem = src.m_listItem;

         src.m_name = "";
         src.m_product = "";
         src.m_cntItem = 0u;
         src.m_listItem = nullptr;
      }

      return *this;
   }


   CustomerOrder::~CustomerOrder()
   {
      if (m_listItem) {
         for (auto i = 0u; i < m_cntItem; ++i)
            delete m_listItem[i];

         delete[] m_listItem;
         m_listItem = nullptr;
      }

   }

   bool CustomerOrder::isOrderFilled() const
   {
      bool result = true;

      for (auto i = 0u; i < m_cntItem; ++i) {
         if (!m_listItem[i]->m_isFilled)
            result = false;
      }

      return result;

   }

   bool CustomerOrder::isItemFilled(const std::string& itemName) const
   {
      bool result = true;
      for (auto i = 0u; i < m_cntItem; ++i) {
         if (m_listItem[i]->m_itemName == itemName && !m_listItem[i]->m_isFilled)
            result = false;
      }
      return result;
   }


   void CustomerOrder::fillItem(Station& station, std::ostream& os)
   {
      bool flag = true;
      std::for_each(m_listItem, m_listItem + m_cntItem, [&](Item* item) {
         if (station.getItemName() == item->m_itemName && flag && item->m_isFilled == false) {
            if (station.getQuantity() > 0) {
               station.updateQuantity();
               item->m_serialNumber = station.getNextSerialNumber();
               item->m_isFilled = true;
               os << "    Filled " << m_name << ", " << m_product << " [" << item->m_itemName << "]" << std::endl;
               flag = false;
            }
            else {
               os << "    Unable to fill " << m_name << ", " << m_product << " [" << item->m_itemName << "]" << std::endl;
            }
         }
         });

   }

   void CustomerOrder::display(std::ostream& os) const {
      os << m_name << " - " << m_product << endl;

      for (auto i = 0u; i < m_cntItem; ++i) {
         os << "[" << right << setw(6) << setfill('0') << m_listItem[i]->m_serialNumber << "] ";
         os << left << setw(CustomerOrder::m_widthField) << setfill(' ') << m_listItem[i]->m_itemName;
         os << " - " << (m_listItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << endl;
      }
   }
}
