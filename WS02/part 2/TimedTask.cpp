//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220128
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#include<iostream>
#include<iomanip>
#include"TimedTask.h"
using namespace std;
namespace sdds {

	void TimedTask::startClock() {
		start_t= std::chrono::steady_clock::now();
	}
	void TimedTask::stopClock()
	{
		end_t= std::chrono::steady_clock::now();
	}
	void TimedTask::addTask(const char* name)
	{
		if (noOfrecord<MAX)
		{
			if (name!=nullptr||name[0] != '\0')
			{
				t_task[noOfrecord].t_name = name;
				t_task[noOfrecord].unit = "nanoseconds";
				t_task[noOfrecord].d_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t-start_t);
				++noOfrecord;
			}
			else
			{
				t_task[noOfrecord].t_name = "";
				t_task[noOfrecord].unit = "";
			}
		}
	}
	std::ostream& operator<<(std::ostream& os, const TimedTask& basic)
	{
		os << "--------------------------" << endl;
		os << "Execution Times:" << endl;
		os << "--------------------------" << endl;
		for (size_t i = 0; i < basic.noOfrecord; ++i)
		{
			os << setw(21) << left << basic.t_task[i].t_name;
			os << setw(13) << right << basic.t_task[i].d_time.count();
			os << " " << basic.t_task[i].unit << endl;
		}
		os << "--------------------------" << endl;
		return os;
	}

}