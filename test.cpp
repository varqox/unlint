#include <iostream>
#include <vector>
//#include "unlint.h"

#define DEBUG

using namespace std;

typedef long long int lli;
const lli BASE=1000000000000000000LL;
const int BS2=1000000000;
const char LEN=18;

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
	void kas0();
	void swap(num& _n){this->w.swap(_n.w);}
	num& operator++();
	num& operator--();
	num& operator+=(const num&);
	num& operator-=(const num&);
	num& operator*=(const lli&);
	num& mult(const lli&, const vector<fmod>&);
	void gen_mod(vector<fmod>&) const;
	num& operator*=(const num&);
	num& operator/=(const num&);
	num& operator%=(const num&);
	void nwd(const num&);
	num& pow(const num&);
	bool operator<(const num&) const;
	bool operator>(const num&) const;
	bool operator<=(const num&) const;
	bool operator>=(const num&) const;
	bool operator==(const num&) const;
	bool operator!=(const num&) const;
};

void /*unlint::*/num::kas0()
{
	vector<lli>::iterator i=this->w.end()-1;
	while(i!=this->w.begin() && *i==0) --i;
	++i;
	this->w.erase(i, this->w.end());
}


num& /*unlint::*/num::operator++()
{
	vector<lli>::iterator i=this->w.begin();
	while(i!=this->w.end())
	{
		++*i;
		if(*i<BASE) return *this;
		*i-=BASE;
		++i;
	}
	this->w.push_back(1);
return *this;
}

num& /*unlint::*/num::operator--()
{
	vector<lli>::iterator i=this->w.begin();
	while(i!=this->w.end())
	{
		--*i;
		if(*i>=0) break;
		*i+=BASE;
		++i;
	}
	this->kas0();
return *this;
}

num& /*unlint::*/num::operator+=(const num& _n)
{
	int s=_n.w.size(), i=0;
	if(s>this->w.size()) this->w.resize(s);
	bool add=false;
	for(; i<s; ++i)
	{
		this->w[i]+=_n.w[i];
		if(add) ++this->w[i];
		if(this->w[i]>=BASE)
		{
			this->w[i]-=BASE;
			add=true;
		}
		else add=false;
	}
	if(add)
	{
		if(i==s) this->w.push_back(add);
		else
		{
			for(;i<s; ++i)
			{
				++this->w[i];
				if(this->w[i]<BASE) break;
				this->w[i]-=BASE;
			}
			if(i==s) this->w.push_back(add);
		}
	}
return *this;
}

num& /*unlint::*/num::operator-=(const num& _n)
{
	int s=_n.w.size(), i=0;
	bool add=false;
	for(; i<s; ++i)
	{
		this->w[i]-=_n.w[i];
		if(add) --this->w[i];
		if(this->w[i]<0)
		{
			this->w[i]+=BASE;
			add=true;
		}
		else add=false;
	}
	if(add)
	{
		s=this->w.size();
		for(;i<s; ++i)
		{
			--this->w[i];
			if(this->w[i]>=0) break;
			this->w[i]+=BASE;
		}
	}
	this->kas0();
return *this;
}

num& /*unlint::*/num::operator*=(const lli& _lcb)
{
	if(_lcb==0){vector<lli>(1).swap(this->w);return *this;}
	lli p1=_lcb/BS2, p2=_lcb-p1*BS2, add=0, pom1, pom2, pom3, add1;
	for(vector<lli>::iterator i=this->w.begin(); i!=this->w.end(); ++i)
	{
		pom1=*i/BS2;
		pom2=*i-pom1*BS2;
		*i=add+p2*pom2;
		add1=add=0;
		if(*i>=BASE){++add;*i-=BASE;}
		add1=pom1*p2+pom2*p1;
		pom3=add1/BS2;
		*i+=(add1-pom3*BS2)*BS2;
		while(*i>=BASE)
		{
			++add;
			*i-=BASE;
		}
		add+=pom3+pom1*p1;
	}
	if(add) this->w.push_back(add);
return *this;
}

num& /*unlint::*/num::mult(const lli& _lcb, const vector<num::fmod>& _t)
{
	if(_lcb==0){vector<lli>(1).swap(this->w);return *this;}
	int tl=_t.size();
	this->w.resize(tl);
	lli p1=_lcb/BS2, p2=_lcb-p1*BS2, add=0, pom3, add1;
	for(int i=0; i<tl; ++i)
	{
		this->w[i]=add+p2*_t[i].pom2;
		add1=add=0;
		if(this->w[i]>=BASE){++add;this->w[i]-=BASE;}
		add1=_t[i].pom1*p2+_t[i].pom2*p1;
		pom3=add1/BS2;
		this->w[i]+=(add1-pom3*BS2)*BS2;
		while(this->w[i]>=BASE)
		{
			++add;
			this->w[i]-=BASE;
		}
		add+=pom3+_t[i].pom1*p1;
	}
	if(add) this->w.push_back(add);
return *this;
}

void /*unlint::*/num::gen_mod(vector<num::fmod>& _k) const
{
	int wl=this->w.size();
	_k.resize(wl);
	for(int i=0; i<wl; ++i)
	{
		_k[i].pom1=this->w[i]/BS2;
		_k[i].pom2=this->w[i]-_k[i].pom1*BS2;
	}
}

num& /*unlint::*/num::operator*=(const num& b)
{
	num lol=0, _n;
	lli bl=b.w.size();
	vector<num::fmod> t;
	b.gen_mod(t);
	for(int q=0; q<this->w.size(); ++q)
	{
		_n.mult(w[q], t);
		//k.w.insert(k.w.begin(),i,0);
		//lol+=k;
		int s=_n.w.size(), i=0;
		if(s+q>lol.w.size()) lol.w.resize(s+q);
		bool add=false;
		for(; i<s; ++i)
		{
			lol.w[i+q]+=_n.w[i];
			if(add) ++lol.w[i+q];
			if(lol.w[i+q]>=BASE)
			{
				lol.w[i+q]-=BASE;
				add=true;
			}
			else add=false;
		}
		if(add)
		{
			if(i==s) lol.w.push_back(add);
			else
			{
				for(;i<s; ++i)
				{
					++lol.w[i+q];
					if(lol.w[i+q]<BASE) break;
					lol.w[i+q]-=BASE;
				}
				if(i==s) lol.w.push_back(add);
			}
		}
	}
	this->swap(lol);
	this->kas0();
return *this;
}

num& /*unlint*/num::operator/=(const num& _n)
{
	if(this->operator<(_n))
	{
		vector<lli>(1,0).swap(this->w);
		return *this;
	}
	else if(_n.w.size()==1 && _n.w[0]==1) return *this;
	int wl=this->w.size(), nl=_n.w.size(), iws=wl-nl;
	vector<num::fmod> nmd;
	_n.gen_mod(nmd);
	num k, w;
	w.w.resize(iws+1);
	bool is_grader;
	while(iws>=0)
	{
		if(wl-iws<nl) is_grader=false;
		else if(wl-iws>nl) is_grader=true;
		else
		{
			int i=nl-1;
			while(i>=0 && this->w[i+iws]==_n.w[i])
				--i;
			if(i<0 || this->w[i+iws]>_n.w[i]) is_grader=true;
			else is_grader=false;
		}
		if(is_grader)
		{
			lli down=0, up=BASE-1, mean;
			while(down<up)
			{
				mean=1+(down+up)>>1;
				k.mult(mean, nmd);
				int kl=k.w.size();
				if(wl-iws<kl) is_grader=true;
				else if(wl-iws>kl) is_grader=false;
				else
				{
					int i=kl-1;
					while(i>=0 && this->w[i+iws]==k.w[i])
						--i;
					if(i<0) is_grader=false;
					else if(k.w[i]>this->w[i+iws]) is_grader=true;
					else is_grader=false;
				}
				if(is_grader) up=--mean;
				else down=mean;
			}
			k.mult(down, nmd);
			int gl=k.w.size();
			bool add=0;
			for(int i=0; i<gl; ++i)
			{
				this->w[i+iws]-=k.w[i];
				if(add) --this->w[i+iws];
				if(this->w[i+iws]<0)
				{
					this->w[i+iws]+=BASE;
					add=true;
				}
				else add=false;
			}
			for(int i=gl+iws; i<wl; ++i)
			{
				if(add) --this->w[i];
				if(this->w[i]<0)
				{
					this->w[i]+=BASE;
					add=true;
				}
				else break;
			}
			this->kas0();
			wl=this->w.size();
			w.w[iws]=down;
		}
		--iws;
	}
	w.kas0();
	this->swap(w);
return *this;
}

num& /*unlint*/num::operator%=(const num& _n)
{
	if(this->operator<(_n))
		return *this;
	else if(_n.w.size()==1 && _n.w[0]==1)
	{
		vector<lli>(1,0).swap(this->w);
		return *this;
	}
	int wl=this->w.size(), nl=_n.w.size(), iws=wl-nl;
	vector<num::fmod> nmd;
	_n.gen_mod(nmd);
	num k;
	bool is_grader;
	while(iws>=0)
	{
		if(wl-iws<nl) is_grader=false;
		else if(wl-iws>nl) is_grader=true;
		else
		{
			int i=nl-1;
			while(i>=0 && this->w[i+iws]==_n.w[i])
				--i;
			if(i<0 || this->w[i+iws]>_n.w[i]) is_grader=true;
			else is_grader=false;
		}
		if(is_grader)
		{
			lli down=0, up=BASE-1, mean;
			while(down<up)
			{
				mean=1+(down+up)>>1;
				k.mult(mean, nmd);
				int kl=k.w.size();
				if(wl-iws<kl) is_grader=true;
				else if(wl-iws>kl) is_grader=false;
				else
				{
					int i=kl-1;
					while(i>=0 && this->w[i+iws]==k.w[i])
						--i;
					if(i<0) is_grader=false;
					else if(k.w[i]>this->w[i+iws]) is_grader=true;
					else is_grader=false;
				}
				if(is_grader) up=--mean;
				else down=mean;
			}
			k.mult(down, nmd);
			int gl=k.w.size();
			bool add=0;
			for(int i=0; i<gl; ++i)
			{
				this->w[i+iws]-=k.w[i];
				if(add) --this->w[i+iws];
				if(this->w[i+iws]<0)
				{
					this->w[i+iws]+=BASE;
					add=true;
				}
				else add=false;
			}
			for(int i=gl+iws; i<wl; ++i)
			{
				if(add) --this->w[i];
				if(this->w[i]<0)
				{
					this->w[i]+=BASE;
					add=true;
				}
				else break;
			}
			this->kas0();
			wl=this->w.size();
		}
		--iws;
	}
return *this;
}

void echo(const num&);

void /*unlint::*/num::nwd(const num& _n)
{
	num b=_n, zero(0), c;
	int i=0;
	while(b!=zero)
	{
		c.swap(*this);
		c%=b;
		this->swap(b);
		b.swap(c);
	}
}

bool /*unlint::*/num::operator<(const num& _n) const
{
	int i=this->w.size();
	if(i<_n.w.size()) return true;
	else if(i>_n.w.size()) return false;
	--i;
	while(i>=0 && this->w[i]==_n.w[i])
		--i;
	if(i<0) return false;
	if(this->w[i]>_n.w[i]) return false;
return true;
}

bool /*unlint::*/num::operator>(const num& _n) const
{
return _n<*this;
}

bool /*unlint::*/num::operator<=(const num& _n) const
{
return !(_n<*this);
}

bool /*unlint::*/num::operator>=(const num& _n) const
{
return !this->operator<(_n);
}

bool /*unlint::*/num::operator==(const num& _n) const
{
	int i=this->w.size();
	if(i!=_n.w.size()) return false;
	--i;
	while(i>=0 && this->w[i]==_n.w[i])
		--i;
	if(i<0) return true;
return false;
}

bool /*unlint::*/num::operator!=(const num& _n) const
{
return !this->operator==(_n);
}

void echo(const num& a)
{
	int k=a.w.size()-1;
	cout << a.w[k];
	for(int i=--k; i>=0; i--)
	{
		cout.width(LEN);
		cout.fill('0');
		cout << a.w[i];
	}
}

void get(num& a)
{
	vector<lli>().swap(a.w);
	string str;
	cin >> str;
	lli pom;
	for(int i=str.size(); i>0; i-=LEN)
	{
		pom=0;
		for(int j=max(0,i-LEN); j<i; ++j)
		{
			pom*=10;
			pom+=str[j]-'0';
		}
		a.w.push_back(pom);
	}
	a.kas0();
}

int main()
{
	num a;
	num b;
	get(a);
	get(b);
	a.nwd(b);
	echo(a);
	cout << endl;
return 0;
}
