//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NBB
//Date:20220204
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#ifndef SDDS_SET_H_
#define SDDS_SET_H_
#include"Collection.h"

namespace sdds {

	template<typename T>
	class Set : public Collection<T, 100>
	{
	public:

		bool add(const T& item)
		{
			bool ok = true;

			for (size_t i = 0; i < Collection<T, 100>::size(); i++)
			{
				if (item == Collection<T, 100>::arr[i])
				{
					ok = false;

				}

			}
			if (ok == true)
			{
				Collection<T, 100>::add(item);
			}
			return ok;

		}
	};

	template<>
	class Set<Pair> : public Collection<Pair, 100>
	{
	public:

		bool add(const Pair& item)
		{
			bool ok = true;
			Pair obj;
			obj = item;
			for (size_t i = 0; i < Collection<Pair, 100>::size(); i++)
			{
				if (obj.getKey() == Collection<Pair, 100>::arr[i].getKey())
				{
					ok = false;
				}
			}
			if (ok == true)
			{
				Collection<Pair, 100>::add(item);
			}

			return ok;

		}
	};

	template<>
	class Set<double> : public Collection<double, 100>
	{
	public:

		bool add(const double& item)
		{
			bool ok = true;

			for (size_t i = 0; i < Collection<double, 100>::size(); i++)
			{
				if (fabs(item)-fabs( Collection<double, 100>::arr[i])<=fabs(0.01))
				{
					ok = false;

				}

			}
			if (ok == true)
			{
				Collection<double, 100>::add(item);
			}
			return ok;

		}
	};


}
#endif // !SDDS_SET_H_

#pragma once
