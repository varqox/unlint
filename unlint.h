#ifndef __UNLINT_H
#define __UNLINT_H

#include <bits/localefwd.h>
#include <string>
#include <vector>

namespace unlimited_int
{
	class unlint
	{
	private:
		class num;
		bool z; // znak
		num* w; // wartość
		template<typename _CharT, typename _Traits>
		std::basic_ostream<_CharT, _Traits>& out(std::basic_ostream<_CharT, _Traits>&) const;
	public:
		unlint();
		~unlint();
		unlint(const long long int&);
		unlint(const char*);
		unlint(const std::string&);
		unlint(const unlint&);
		unlint& operator=(const unlint&);
		template<typename type>
		unlint& operator=(const type&);
		long long int size() const;
		void swap(unlint&);
		std::string str() const;
		const char* c_str() const;
		unlint& operator++();
		unlint& operator--();
		unlint operator++(int);
		unlint operator--(int);
		friend unlint operator+(const unlint&);
		friend unlint operator-(const unlint&);
		unlint operator+(const unlint&);
		unlint& operator+=(const unlint&);
		unlint operator-(const unlint&);
		unlint& operator-=(const unlint&);
		unlint operator*(const unlint&);
		unlint& operator*=(const unlint&);
		unlint operator/(const unlint&);
		unlint& operator/=(const unlint&);
		unlint operator%(const unlint&);
		unlint& operator%=(const unlint&);
		bool operator>(const unlint&) const;
		bool operator<(const unlint&) const;
		bool operator>=(const unlint&) const;
		bool operator<=(const unlint&) const;
		bool operator==(const unlint&) const;
		bool operator!=(const unlint&) const;
		unlint& pow(const unlint&);
		unlint& factorial();
		friend unlint nwd(const unlint&, const unlint&);
		/* output unlint with ostream */
		friend std::ostream& operator<<(std::ostream&, const unlint&);
		/* input unlint with istream */
		friend std::istream& operator>>(std::istream&, unlint&);
	};

	unlint pow(const unlint&, const unlint&);
	unlint factorial(const unlint&);

	template<typename type>
	unlint& unlint::operator=(const type& _n)
	{
		unlint(_n).swap(*this);
	return *this;
	}
}

using namespace unlimited_int;

#endif /* __UNLINT_H */