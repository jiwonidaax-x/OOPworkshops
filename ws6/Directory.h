//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220225
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#pragma once
#ifndef SDDS_DIRECTORY_H_
#define SDDS_DIRECTORY_H_
#include "Resource.h"
#include "Flags.h"
#include <vector>
namespace sdds {

	class Directory :public Resource
	{		
		std::vector<Resource*> m_contents;

	public:
		
		Directory(std::string name);
		~Directory();
		void update_parent_path(const std::string& path);
		std::string name() const;
		int count() const;
		std::string path() const;
		size_t size() const;
		NodeType type() const;
		Directory(const Directory& src) = delete;
		Directory(Directory&& src) = delete;
		Directory& operator+=(Resource*);
		Resource* find(const std::string&, const std::vector<OpFlags>& =std::vector<OpFlags> ());
		void remove(const std::string&, const std::vector<OpFlags>& = std::vector<OpFlags>());
		void display(std::ostream& os=std::cout, const std::vector<FormatFlags>& = std::vector<FormatFlags>()) const;
	};







}
#endif // !SDDS_DIRECTORY_H_

