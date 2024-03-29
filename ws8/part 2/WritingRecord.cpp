//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220330
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using raw pointers
		for (auto i = 0u; i < emp.size(); ++i) {
			for (auto j = 0u; j < sal.size(); ++j) {
				if (emp[i].id == sal[j].id) {
					EmployeeWage* temp = new EmployeeWage(emp[i].name, sal[j].salary);

					try {
						temp->rangeValidator();
					}
					catch (std::string str) {

						delete temp;
						temp = nullptr;
						throw str;
					}
					activeEmp += temp;

					if (activeEmp.luhnAlgorithm(emp[j].id))
					{
						activeEmp += temp;

					}

					delete temp;
					temp = nullptr;


				}
			}
		}

		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using smart pointers
		for (auto i = 0u; i < emp.size(); ++i) {
			for (auto j = 0u; j < sal.size(); ++j) {
				if (emp[i].id == sal[j].id) {
					unique_ptr<EmployeeWage> temp(new EmployeeWage(emp[i].name, sal[j].salary));
					try {
						temp->rangeValidator();
					}
					catch (std::string str) {

						throw str;
					}
					activeEmp += temp;
					if (activeEmp.luhnAlgorithm(emp[j].id))
					{
						activeEmp += temp;

					}
					
					temp.get_deleter();
				}
			}
		}

		return activeEmp;
	}
}