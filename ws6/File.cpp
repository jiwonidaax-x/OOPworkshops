//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220225
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#include"File.h"
#include"Flags.h"
#include<string>
#include<iostream>
namespace sdds {

   File::File(std::string name, std::string desc)
   {
      m_name = name;
      m_contents = desc;
   }
   void File::update_parent_path(const std::string& path)
   {
      m_parent_path = path;
   }
   std::string File::name() const
   {
      return m_name;
   }
   int File::count() const 
   {
      return -1;
   }
   std::string File::path() const
   {    
      return  m_parent_path + m_name;
   }
   size_t File::size() const
   {
      return m_contents.length();
   }
   NodeType File::type() const
   {
      return NodeType::FILE;
   }
}