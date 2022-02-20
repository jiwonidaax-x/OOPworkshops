#ifndef SDDS_PROCESSOR_H_
#define SDDS_PROCESSOR_H_
#include"Job.h"
#include"CentralUnit.h"
; namespace sdds {

	class Processor
	{
		CentralUnit<Processor>* m_host{ nullptr };
		std::string m_brand{ "" };
		std::string m_code{ "" };
		size_t m_power{ 0u };
		Job* m_current{ nullptr };

	public:

		Processor(CentralUnit<Processor>* host, std::string brand, std::string code, size_t power);
		void run();
		explicit operator bool() const;
		Processor& operator+=(Job*&);
		Job* get_current_job() const;
	};


}
#endif // !SDDS_PROCESSOR_H_
