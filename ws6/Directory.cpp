//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220311
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#include"Flags.h"
#include"Directory.h"
#include<iomanip>
#include<string>
#include<iostream>
#include <algorithm>
#include<vector>
namespace sdds {
   Directory::~Directory()
   {
      for (size_t i = 0; i < m_contents.size(); i++)
      {
         delete m_contents[i];
         m_contents[i] = nullptr;
                 
      }
      std::vector<Resource*>::iterator iter;
      for (iter = m_contents.begin(); iter != m_contents.end(); iter++) {
         delete (*iter);
      }
      //m_contents.clear();
      //std::vector<Resource*> vclear;
      //m_contents.swap(vclear);

      //vclear.clear();
      //m_contents.clear();


   }
   Directory::Directory(std::string name)
   {
      m_name = name;

   }
   void Directory::update_parent_path(const std::string& path)
   {
      m_parent_path = path;
   }
   std::string Directory::name() const
   {
      return m_name;
   }
   int Directory::count() const
   {
      return m_contents.size();
   }
   std::string Directory::path() const
   {
      return  m_parent_path + m_name;
   }
   size_t Directory::size() const
   {
      size_t temp = 0u;
      if (count())
      {
         for (int i = 0; i < count(); i++)
         {
            temp += m_contents[i]->size();
         }

      }
      else
      {
         temp = 0u;
      }

      return temp;
   }
   NodeType Directory::type() const
   {
      return NodeType::DIR;
   }

   Directory& Directory::operator+=(Resource* contents)
   {
      bool ok = false;
      static size_t i = 0;
      size_t j = 0;

      if (i == 0)
      {
         m_contents.push_back(contents);
         m_contents[0]->update_parent_path(m_parent_path);
         i++;
      }
      else
      {
         while (ok == false && j < m_contents.size())
         {
            if (m_contents[j]->name() == contents->name())
            {
               ok = true;
               throw 0;
            }
            j++;

         }
         if (ok == false)
         {
            contents->update_parent_path(path());
            m_contents.push_back(contents);
            i++;

         }
      }


      return *this;
   }

   Resource* Directory::find(const std::string& src, const std::vector<OpFlags>& flag)
   {
      Resource* temp = nullptr;
      Directory* found = nullptr;

      bool ok = false;

      std::string str1 = "";

      size_t j = 0;
      if (flag.size() > 0)
      {
         for (int i = 0; i < count(); i++)
         {

            if (m_contents[i]->type() == NodeType::DIR)
            {
               found = dynamic_cast<sdds::Directory*>(find(m_contents[i]->name()));
               temp = found->find(src);
            }

         }

      }
      else
      {
         while (ok == false && j < m_contents.size())
         {
            temp = nullptr;
            if (m_contents[j]->name() == src)
            {
               ok = true;
               temp = &*m_contents[j];
            }

            j++;

         }

      }
      return temp;
   }

   void Directory::remove(const std::string& str, const std::vector<OpFlags>& flag)
   {
      bool t_flag = false;
      std::vector<sdds::OpFlags> m_flags;
      m_flags.push_back(sdds::OpFlags::RECURSIVE);
      Resource* temp = nullptr;
      int i = 0;
      int j = 0;
      temp = find(str);
      if (temp == find(str))
      {
         
         if (flag != m_flags)
         {
            throw std::invalid_argument(str + " is a directory.Pass the recursive flag to delete directories.");
         }
         else
         {
            while (t_flag == false)
            {
               if (m_contents[i] == temp)
               {
                  t_flag = true;
               }

               i++;
               j++;
            }
            j -= 1;
            m_contents.erase(m_contents.begin() + j);
         }
      }
      else
      {
         throw std::string(str + " does not exist in DIRECTORY_NAME");
      }

   }
   void Directory::display(std::ostream& os, const std::vector<FormatFlags>& flag) const
   {


      if (!flag.size())
      {
         os << "Total size: ";
         std::cout << this->size();

         os << " bytes" << std::endl;
         for (size_t i = 0; i < this->m_contents.size(); i++)
         {
            if (m_contents[i]->type() == NodeType::DIR)
            {
               os << "D";
            }
            else
            {
               os << "F";
            }
            os << " | ";
            os << std::setw(15) << std::left << m_contents[i]->name();
            os << " |" << std::endl;
         }


      }
      else
      {
         os << "Total size: ";
         std::cout << this->size();

         os << " bytes" << std::endl;
         for (size_t i = 0; i < this->m_contents.size(); i++)
         {
            if (m_contents[i]->type() == NodeType::DIR)
            {
               os << "D";
            }
            else
            {
               os << "F";
            }
            os << " | ";
            os << std::setw(15) << std::left << m_contents[i]->name();
            os << " | ";
            if (m_contents[i]->count() > -1)
            {
               os << std::setw(2) << std::right << m_contents[i]->count();
            }
            else
            {
               os << "  ";
            }

            os << " | ";
            os << std::setw(4) << std::right << m_contents[i]->size();
            os << " bytes | " << std::endl;
         }

      }

   }

}