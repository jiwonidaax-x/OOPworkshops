//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220403
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;

namespace sdds
{
   size_t CustomerOrder::m_widthField = 0u;

   CustomerOrder::CustomerOrder(const std::string& src)
   {
      Utilities util;
      bool more = true;
      size_t pos = 0u;
      size_t idx = 0u;
      	std::string temp{ "" };
      try {

         m_name = util.extractToken(src, pos, more);
         m_product = util.extractToken(src, pos, more);

         m_cntItem = std::count(src.begin(), src.end(), util.getDelimiter()) - 1;

         if (m_cntItem)
            m_listItem = new Item * [m_cntItem];

         while (more && m_cntItem) {
            m_listItem[idx] = new Item(util.extractToken(src, pos, more));
            ++idx;
         }

         CustomerOrder::m_widthField = max(util.getFieldWidth(), CustomerOrder::m_widthField);
      }
      catch (std::string err) {
         cout << err;
      }
   }

   CustomerOrder::CustomerOrder(const CustomerOrder& src) {
      throw false;
   }

   CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {
      *this = std::move(src);
   }

   CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept {
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

   CustomerOrder::~CustomerOrder() {
      if (m_listItem) {
         for (auto i = 0u; i < m_cntItem; ++i)
            delete m_listItem[i];

         delete[] m_listItem;
         m_listItem = nullptr;
      }
   }

   bool CustomerOrder::isOrderFilled() const {
      bool ok=true;
      for (unsigned int i = 0; i < m_cntItem; i++)
         if (!m_listItem[i]->m_isFilled)
            ok = false;

      return ok;
   }

   bool CustomerOrder::isItemFilled(const std::string& itemName) const {
      bool result = false;

      for (auto i = 0u; i < m_cntItem; ++i)
         m_listItem[i]->m_itemName == itemName ? result = false : result = true;

      return result;
   }

   void CustomerOrder::fillItem(Station& station, std::ostream& os) {
      for (unsigned int i = 0; i < m_cntItem; i++)
      {
         if (m_listItem[i]->m_itemName == station.getItemName())
         {
            if (station.getQuantity() <= 0)
               os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_listItem[i]->m_itemName << "]" << std
               ::endl;
            else
            {
               m_listItem[i]->m_serialNumber = station.getNextSerialNumber();
               station.updateQuantity();
               m_listItem[i]->m_isFilled = true;

               os << "    Filled " << m_name << ", " << m_product << " [" << m_listItem[i]->m_itemName << "]" << std::endl;
            }

            return;
         }
      }
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