//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220225
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#include"Flags.h"
#include"Directory.h"
#include<string>
#include<iostream>
#include <algorithm>
#include<vector>
namespace sdds {

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
         for (size_t i = 0; i < count(); i++)
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
      static int i = 0;
      int j = 0;

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

      std::string str1;

      int j = 0;
      if (flag.size() > 0)
      {
         for (size_t i = 0; i < count(); i++)
         {

            if (m_contents[i]->type() == NodeType::DIR)
            {
               temp = find(m_contents[i]->name());                
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



}