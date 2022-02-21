#pragma once
#ifndef SDDS_JOB_H_
#define SDDS_JOB_H_
#include <string>
#include <iostream>
namespace sdds {

	class Job
	{
		//a title describing the job to be done.
		std::string m_title{""};
		
		//a positive number indicating the units of work to be done to finish the job.
		size_t m_unit{ 0u };
		
		//a positive number indicating the remaining units of work to be done to finish the job.
		size_t m_remain{ 0u };

		//a flag to determine if the job is active or not.
		bool isActive{ false };

	public:
		//default constructor
		Job();

		Job(const std::string& title);

		bool is_active();

		bool is_complete();

		std::string name();

		//functor using object like function object
		void operator()(size_t unit);

		std::ostream& display(std::ostream& os)const;

		friend std::ostream& operator<<(std::ostream& os, const Job& src);
	};



}
#endif // !SDDS_JOB_H_
