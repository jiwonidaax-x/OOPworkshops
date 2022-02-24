//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220225
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
#include"Processor.h"

using namespace std;

namespace sdds {

   Processor::Processor(CentralUnit<Processor>* host, std::string brand, std::string code, size_t power)
   {
      m_host = host;
      m_brand = brand;
      m_code = code;
      m_power = power;
   }
   void Processor::operator()()
   {

      try
      {
         (*m_current)(m_power);
         m_address;
         if (m_current->is_complete())
         {
            delete m_current;
            m_current = nullptr;
         }
      }
      catch (std::underflow_error& e)
      {
         f_error;
         free();

      }

   }
   void Processor::on_complete(void (*address) (const CentralUnit<Processor>&, const Processor&))
   {
      m_address = address;
   }

   void Processor::on_error(std::function<void(Processor& src)> error)
   {
      f_error = error;
   }

   Job* Processor::free()
   {

      m_current = nullptr;
      return m_current;
   }

   std::ostream& operator<<(std::ostream& os, const Processor& src)
   {
      os << "(" << src.m_power << ") " << src.m_brand << " " << src.m_code;
      if (src.m_current)
      {
         if (src.m_current->is_complete() == false)
         {
            os << " processing ";
            src.m_current->display(os);
         }

      }
      return os;
   }


   void Processor::run()
   {
      try
      {
         if (m_current->is_complete())
         {
            delete m_current;
            m_current = nullptr;
         }
         else
         {
            (*m_current)(m_power);
         }

      }
      catch (std::underflow_error& e)
      {

         m_host->log << "Processed over quota for " << *m_current;

         delete m_current;
         m_current = nullptr;
      }
   }

   Processor::operator bool() const
   {
      return m_current ? true : false;

   }

   Processor& Processor::operator+=(Job*& job)
   {
      if (m_current == nullptr)
      {
         m_current = job;
      }
      else
      {
         throw runtime_error("dd");
      }
      return *this;
   }

   Job* Processor::get_current_job() const
   {
      return m_current;
   }

}

