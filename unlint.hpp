#ifndef __UNLINT_H
#define __UNLINT_H

#include <bits/localefwd.h>
#include <string>
#include <vector>

namespace unlimited_int
{
	/*
	unlimited integer type
	*/
	typedef long long int lli;
	const lli BASE=1000000000000000000LL, BS2=1000000000;
	const char LEN=18;

	class unlint
	{
	private:
		/*
		unlimited natural type
		*/
		class num
		{
		public:
			struct fmod
			{
				lli pom1, pom2;
				fmod(){}
				~fmod(){}
			};
			std::vector<lli> w;
			num(): w(1,0){}
			~num(){}
			num(const lli& _x): w(1,_x){}
			num(const num& _n): w(_n.w){}
			lli size() const;
			void kas0();
			void swap(num& _n){w.swap(_n.w);}
			num& operator++();
			num& operator--();
			num& operator+=(const num&);
			num& operator-=(const num&);
			num& operator*=(const lli&);
			void gen_mod(std::vector<fmod>&) const;
			num& mult(const lli&, const std::vector<fmod>&);
			void to_old_type(std::vector<int>&) const;
			num& from_old_type(std::vector<int>&);
			class FFT;
			num& operator*=(const num&);
			num& operator/=(const num&);
			num& operator%=(const num&);
			num& nwd(const num&);
			num& pow(const num&);
			bool operator<(const num&) const;
			bool operator>(const num&) const;
			bool operator<=(const num&) const;
			bool operator>=(const num&) const;
			bool operator==(const num&) const;
			bool operator!=(const num&) const;
		};

		bool z; // znak
		num* w; // wartość
	public:
		unlint();
		~unlint();
		unlint(long long int);
		unlint(const char*);
		unlint(const std::string&);
		unlint(const unlint&);
		unlint& operator=(const unlint&);
		template<typename type>
		unlint& operator=(const type&);
		long long int size() const;
		void swap(unlint&);
		std::string str() const;
		unlint& operator++();
		unlint& operator--();
		unlint operator++(int);
		unlint operator--(int);
		friend unlint operator+(const unlint&);
		friend unlint operator-(const unlint&);
		friend unlint operator+(const unlint&, const unlint&);
		unlint& operator+=(const unlint&);
		friend unlint operator-(const unlint&, const unlint&);
		unlint& operator-=(const unlint&);
		friend unlint operator*(const unlint&, const unlint&);
		unlint& operator*=(const unlint&);
		friend unlint operator/(const unlint&, const unlint&);
		unlint& operator/=(const unlint&);
		friend unlint operator%(const unlint&, const unlint&);
		unlint& operator%=(const unlint&);
		friend bool operator>(const unlint&, const unlint&);
		friend bool operator<(const unlint&, const unlint&);
		friend bool operator>=(const unlint&, const unlint&);
		friend bool operator<=(const unlint&, const unlint&);
		friend bool operator==(const unlint&, const unlint&);
		friend bool operator!=(const unlint&, const unlint&);
		unlint& pow(const unlint&);
		unlint& factorial();
		friend unlint nwd(const unlint&, const unlint&);

		/* output unlint with ostream */
		template<class ostream_type>
		friend ostream_type& operator<<(ostream_type& os, const unlint& uli)
		{
			int ul=uli.w->w.size();
			if(!uli.z) os << '-';
			os << uli.w->w[--ul];
			for(int i=--ul; i>=0; --i)
			{
				os.width(LEN);
				os.fill('0');
				os << uli.w->w[i];
			}
		return os;
		}

		/* input unlint with istream */
		template<class istream_type>
		friend istream_type& operator>>(istream_type& is, unlint& uli)
		{
			std::string str;
			is >> str;
			uli=str;
		return is;
		}
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