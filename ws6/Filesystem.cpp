//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220225
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#include"Filesystem.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
namespace sdds {

   Filesystem::Filesystem(std::string filename, std::string dir)
   {
      m_root = new Directory(dir);
      m_current = m_root;
      //Directory* m_dir1=nullptr;
      //Directory* m_dir2=nullptr;   
      //File* m_file = nullptr;
      std::ifstream in;
      in.open(filename);

      if (in.is_open() == false) {

         throw 0;
      }
      else
      {
         std::string temp{ "" };

         while (!in.eof())
         {
            size_t index{ 0u };
            std::string dir1;
            std::string dir2;
            std::string fname;
            std::string desc;
            Directory* m_dir1 = nullptr;
            Directory* m_dir2 = nullptr;
            File* m_file = nullptr;
           

         
            std::getline(in, temp);
            temp.erase(0, temp.find_first_not_of(" "));
            index = temp.find("/");
            if (index)
            {
               dir1 = temp.substr(0, index + 1);
               temp.erase(0, index + 1);
            }
           
            if (temp.find("/")!=string::npos)
            {
               index = temp.find("/");
               dir2 = temp.substr(0, index + 1);
               temp.erase(0, index + 1);
            }
         
               
               if (temp.find("|")!=string::npos)
               {
                  index = temp.find("|");
                  fname = temp.substr(0, index);
                  fname.erase(fname.find_last_not_of(" ") + 1);
                  temp.erase(0, index + 1);
               }
               if (temp.length()>0)
               {

                  temp.erase(0, temp.find_first_not_of(" ")); 
                  index = temp.find("\n");
                  desc = temp.substr(0, index);
                  desc.erase(desc.find_last_not_of(" ") + 1);
                  temp.erase(0, index + 1);
               }
            
   
        
            if (dir1.length() > 0)
            {
               if (!m_root->find(dir1))
               {
                  
                  m_dir1 = new Directory(dir1);
                  *m_root += m_dir1;
                 
               }
               else
               {
                  m_dir1 = dynamic_cast<sdds::Directory*>( m_root->find(dir1));
               }
               
               if (dir2.length() > 0)
               {
                  if (!m_root->find(dir2))
                  {
                     
                     m_dir2 = new Directory(dir2);
                     *m_dir1 += m_dir2;
                     
                  }
                  else
                  {
                     m_dir2 = dynamic_cast<sdds::Directory*>(m_dir1->find(dir2));
                  }
                  

                  if (fname.length() > 0)
                  {
                     if (!m_dir2->find(fname))
                     {
                        
                        m_file = new File(fname, desc);
                        *m_dir2 += m_file;
                     }
                     else
                     {
                        m_file = dynamic_cast<sdds::File*>(m_dir2->find(fname));
                     }
                     
                  }

               }
               else {
                  if (fname.length() > 0)
                  {

                     if (!m_dir1->find(fname))
                     {
                       
                        m_file = new File(fname, desc);
                     }
                     else
                     {
                        m_file = dynamic_cast<sdds::File*>(m_dir1->find(fname));
                     }
                     *m_dir1 += m_file;
                  }
               }
            }
            else
            {
               if (fname.length() > 0)
               {
                  if (!m_root->find(fname))

                  {
                     delete[] m_file;
                     m_file = new File(fname, desc);
                  }
                  else
                  {
                     m_file = dynamic_cast<sdds::File*>(m_root->find(fname));
                  }
                  *m_root += m_file;
               }
            }

            
         }
      


      }
      in.close();
      

   }

   Filesystem::Filesystem(Filesystem&& src)
   {
      operator=(move(src));
   }
   Filesystem& Filesystem::operator=(Filesystem&& src)
   {
      m_current = src.m_current;
      m_root = src.m_root;
      src.m_current = nullptr;
      src.m_root = nullptr;

      return *this;
   }
   Filesystem& Filesystem::operator+=(Resource* src)
   {
      *m_current += src;
      return *this;
   }
   Directory* Filesystem::change_directory(const std::string& str)
   {
      if (str.length() == 0)
      {
         m_current = m_root;
      }
      else
      {

         if (!m_current->find(str))
         {
            throw std::invalid_argument("Cannot change directory! DIR_NAME not found!");
         }
         else
         {
            m_current = dynamic_cast<sdds::Directory*>(m_current->find(str));
         }
      }


      return m_current;
   }
   Directory* Filesystem::get_current_directory() const
   {
      return m_current;
   }
   Filesystem::~Filesystem()
   {

      delete[] m_root;
       m_root = nullptr;   
       
    
   }



}