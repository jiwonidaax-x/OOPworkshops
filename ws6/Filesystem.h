//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220311
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#pragma once
#ifndef SDDS_FILESYSTEM_H_
#define SDDS_FILESYSTEM_H_h
#include "File.h"
#include"Directory.h"
namespace sdds {

	class Filesystem
	{
		Directory* m_root = nullptr;
		Directory* m_current = nullptr;

	public:
		Filesystem(std::string filename,std::string dir="");
		Filesystem(const Filesystem& src) = delete;
		Filesystem(Filesystem&& src);
		Filesystem& operator=(Filesystem&& src);
		Filesystem& operator+=(Resource*);
		Directory* change_directory(const std::string& ="");
		Directory* get_current_directory() const;
		~Filesystem();
	};

















 }

#endif // !SDDS_FILESYSTEM_H_
