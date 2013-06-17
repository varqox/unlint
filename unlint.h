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
	public:
		unlint();
		~unlint();
		unlint(long long int);
		unlint(const char*);
		unlint(const std::string&);
		unlint(const unlint&);
		int size() const;
		void swap(unlint&);
		template<typename type>
		unlint& operator=(type a);
		std::string& str() const;
		const char* c_str() const;
		unlint& operator++();
		unlint& operator--();
		unlint& operator++(int);
		unlint& operator--(int);
		unlint& operator+();
		unlint& operator-();
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
		friend unlint& nwd(const unlint&, const unlint&);
		/* output unlint with ostream */
		template<typename _CharT, typename _Traits>
		friend std::basic_ostream<_CharT, _Traits>&
		operator<<(std::basic_ostream<_CharT, _Traits>&, const unlint&);
	};

	/* output unlint with ostream */
	template<typename _CharT, typename _Traits>
	std::basic_ostream<_CharT, _Traits>&
	operator<<(std::basic_ostream<_CharT, _Traits>& os, const unlint& uli);

	/* input unlint with istream */
	template<typename _CharT, typename _Traits>
	std::basic_istream<_CharT,_Traits>&
	operator>>(std::basic_istream<_CharT,_Traits>& is, unlint& uli);
}

using namespace unlimited_int;

#endif /* __UNLINT_H */