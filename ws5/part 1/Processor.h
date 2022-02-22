#ifndef SDDS_PROCESSOR_H_
#define SDDS_PROCESSOR_H_
#include<iostream>
#include<functional>
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
		void (*m_address) (const CentralUnit<Processor>&, const Processor&);

		std::function<void(Processor&)>f_error;



	public:
		Processor() {}
		Processor(CentralUnit<Processor>* host, std::string brand, std::string code, size_t power);
		void run();
		explicit operator bool() const;
		Processor& operator+=(Job*&);
		Job* get_current_job() const;
		
		void operator()();
		void on_complete(void (*address) (const CentralUnit<Processor>&, const Processor&));
	
		void on_error(std::function<void(Processor&)> error);
		Job* free();
		friend std::ostream& operator<<(std::ostream&, const Processor&);
	};


}
#endif // !SDDS_PROCESSOR_H_
