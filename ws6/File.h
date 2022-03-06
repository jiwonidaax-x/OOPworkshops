//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220225
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#pragma once
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
#include"Flags.h"
#include"Resource.h"
namespace sdds {

	class File :public Resource
	{
      std::string m_contents{};
	public:
		File(std::string name,std::string desc="");
      void update_parent_path(const std::string& path) ;
      std::string name() const;
      int count() const;
      std::string path() const;
      size_t size() const;
      NodeType type() const;
	};





}
#endif // !SDDS_FILE_H_

