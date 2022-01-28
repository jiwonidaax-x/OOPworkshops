//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220128
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#ifndef SDDS_TIMEDTASK_H_
#define SDDS_TIMEDTASK_H_

#include<chrono>
#include<string>
namespace sdds {

	class TimedTask
	{
		enum{MAX=10};//enum hack -only interger value (static const)
		size_t noOfrecord{ 0u };
		std::chrono::steady_clock::time_point start_t;
		std::chrono::steady_clock::time_point end_t;

		struct task {
			std::string t_name;
			std::string unit;
			std::chrono::steady_clock::duration d_time;
			task():t_name(""),unit(""){}//initialize
		}t_task[MAX];

	public:
		TimedTask() {}

		void startClock();
		void stopClock();
		void addTask(const char* name );

		friend std::ostream &operator<<(std::ostream &os, const TimedTask &basic);

	};


}
#endif // !SDDS_TIMEDTASK_H_

#pragma once
