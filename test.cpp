#include <iostream>
#include <vector>
#include <stack>
//#include "unlint.h"

using namespace std;

typedef long long int lli;
const lli BASE=1000000000000000000LL, BS2=1000000000;
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
	void gen_mod(vector<fmod>&) const;
	num& mult(const lli&, const vector<fmod>&);
	void to_old_type(vector<int>&) const;
	num& from_old_type(vector<int>&);
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
		if(i==this->w.size()) this->w.push_back(add);
		else
		{
			for(;i<this->w.size(); ++i)
			{
				++this->w[i];
				if(this->w[i]<BASE) break;
				this->w[i]-=BASE;
			}
			if(i==this->w.size()) this->w.push_back(add);
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

void old_kas0(vector<int>& _n)
{
	vector<int>::iterator i=_n.end()-1;
	while(i!=_n.begin() && *i==0) --i;
	++i;
	_n.erase(i, _n.end());
}

void num::to_old_type(vector<int>& _n) const
{
	int wl=this->w.size();
	_n.resize(wl<<1);
	for(int i=0; i<wl; ++i)
	{
		_n[(i<<1)+1]=this->w[i]/BS2;
		_n[(i<<1)]=this->w[i]-_n[(i<<1)+1]*BS2;
	}
	old_kas0(_n);
}

num& num::from_old_type(vector<int>& _n)
{
	int nl=_n.size();
	this->w.resize((nl+1)>>1);
	for(int i=0; i<nl; i+=2)
		w[i>>1]=_n[i];
	for(int i=1; i<nl; i+=2)
		w[i>>1]+=_n[i]*BS2;
return *this;
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

void div(vector<int>& a, vector<int>& b)
{
	int al=a.size(), bl=b.size(), iws=al-bl;
	if(bl==1 && b[0]==1) return;
	else
	{
		bool is_grader;
		if(al<bl) is_grader=false;
		else if(al>bl) is_grader=true;
		else
		{
			int i=bl-1;
			while(i>=0 && a[i+iws]==b[i])
				--i;
			if(i<0 || a[i+iws]>b[i]) is_grader=true;
			else is_grader=false;
		}
		if(!is_grader)
		{
			vector<int>(1,0).swap(a);
			return;
		}
	}
	vector<int> w(iws+1), g;
	while(iws>=0)
	{
		bool is_grader;
		if(al-iws<bl) is_grader=false;
		else if(al-iws>bl) is_grader=true;
		else
		{
			int i=bl-1;
			while(i>=0 && a[i+iws]==b[i])
				--i;
			if(i<0 || a[i+iws]>b[i]) is_grader=true;
			else is_grader=false;
		}
		if(is_grader)
		{
			int down=1, up=BS2-1, mean;
			while(down<up)
			{
				mean=1+(down+up)>>1;
				//g=b*mean;
				{
					g.resize(bl);
					int gl=bl;
					lli tmp, add=0;
					for (int i=0; i<gl; ++i)
                    {
                        tmp=static_cast<lli>(b[i])*mean+add;
                        add=tmp/BS2;
                        g[i]=tmp-add*BS2;
                    }
                    if(add>0) g.push_back(add);
                    old_kas0(g);
                }
				int gl=g.size();
				if(al-iws<gl) is_grader=true;
				else if(al-iws>gl) is_grader=false;
				else
				{
					int i=gl-1;
					while(i>=0 && a[i+iws]==g[i])
						--i;
					if(i<0) is_grader=false;
					else if(g[i]>a[i+iws]) is_grader=true;
					else is_grader=false;
				}
				if(is_grader) up=--mean;
				else down=mean;
			}
			//g=b*down;
			{
				g.resize(bl);
				int gl=bl;
				lli tmp, add=0;
				for (int i=0; i<gl; ++i)
				{
					tmp=static_cast<lli>(b[i])*down+add;
					add=tmp/BS2;
					g[i]=tmp-add*BS2;
				}
				if(add>0) g.push_back(add);
				old_kas0(g);
			}
			int gl=g.size();
			bool add=false;
			for(int i=0; i<gl; ++i)
			{
				a[i+iws]-=g[i]+add;
				if(a[i+iws]<0)
				{
					a[i+iws]+=BS2;
					add=true;
				}
				else add=false;
			}
			for(int i=gl+iws; i<al; ++i)
			{
				--a[i];
				if(a[i]<0) a[i]+=BS2;
				else break;
			}
			old_kas0(a);
			al=a.size();
			w[iws]=down;
		}
		--iws;
	}
	a.swap(w);
	old_kas0(a);
}

void mod(vector<int>& a, vector<int>& b)
{
	int al=a.size(), bl=b.size(), iws=al-bl;
	if(bl==1 && b[0]==1)
	{
		vector<int>(1,0).swap(a);
		return;
	}
	else
	{
		bool is_grader;
		if(al<bl) is_grader=false;
		else if(al>bl) is_grader=true;
		else
		{
			int i=bl-1;
			while(i>=0 && a[i+iws]==b[i])
				--i;
			if(i<0 || a[i+iws]>b[i]) is_grader=true;
			else is_grader=false;
		}
		if(!is_grader) return;
	}
	vector<int> g;
	while(iws>=0)
	{
		bool is_grader;
		if(al-iws<bl) is_grader=false;
		else if(al-iws>bl) is_grader=true;
		else
		{
			int i=bl-1;
			while(i>=0 && a[i+iws]==b[i])
				--i;
			if(i<0 || a[i+iws]>b[i]) is_grader=true;
			else is_grader=false;
		}
		if(is_grader)
		{
			int down=1, up=BS2-1, mean;
			while(down<up)
			{
				mean=1+(down+up)>>1;
				//g=b*mean;
				{
					g.resize(bl);
					int gl=bl;
					lli tmp, add=0;
					for (int i=0; i<gl; ++i)
                    {
                        tmp=static_cast<lli>(b[i])*mean+add;
                        add=tmp/BS2;
                        g[i]=tmp-add*BS2;
                    }
                    if(add>0) g.push_back(add);
                    old_kas0(g);
                }
				int gl=g.size();
				if(al-iws<gl) is_grader=true;
				else if(al-iws>gl) is_grader=false;
				else
				{
					int i=gl-1;
					while(i>=0 && a[i+iws]==g[i])
						--i;
					if(i<0) is_grader=false;
					else if(g[i]>a[i+iws]) is_grader=true;
					else is_grader=false;
				}
				if(is_grader) up=--mean;
				else down=mean;
			}
			//g=b*down;
			{
				g.resize(bl);
				int gl=bl;
				lli tmp, add=0;
				for (int i=0; i<gl; ++i)
				{
					tmp=static_cast<lli>(b[i])*down+add;
					add=tmp/BS2;
					g[i]=tmp-add*BS2;
				}
				if(add>0) g.push_back(add);
				old_kas0(g);
			}
			int gl=g.size();
			bool add=false;
			for(int i=0; i<gl; ++i)
			{
				a[i+iws]-=g[i]+add;
				if(a[i+iws]<0)
				{
					a[i+iws]+=BS2;
					add=true;
				}
				else add=false;
			}
			for(int i=gl+iws; i<al; ++i)
			{
				--a[i];
				if(a[i]<0) a[i]+=BS2;
				else break;
			}
			old_kas0(a);
			al=a.size();
		}
		--iws;
	}
	old_kas0(a);
}

num& /*unlint*/num::operator/=(const num& _n)
{
	vector<int> a,b;
	this->to_old_type(a);
	_n.to_old_type(b);
	div(a,b);
	this->from_old_type(a);
return *this;
}

num& /*unlint*/num::operator%=(const num& _n)
{
	vector<int> a,b;
	this->to_old_type(a);
	_n.to_old_type(b);
	mod(a,b);
	this->from_old_type(a);
return *this;
}

num& /*unlint::*/num::nwd(const num& _n)
{
	vector<int> a, b, c;
	this->to_old_type(a);
	_n.to_old_type(b);
	while(!(b.size()==1 && b[0]==0))
	{
		c.swap(a);
		mod(c,b);
		a.swap(b);
		b.swap(c);
	}
	vector<int>().swap(b);
	vector<int>().swap(c);
	this->from_old_type(a);
return *this;
}

num& num::pow(const num& _n)
{
	if(_n.w.size()==1 && _n.w[0]==0)
	{
		vector<lli>(1,1).swap(this->w);
		return *this;
	}
	vector<lli> k(_n.w);
	stack<bool> bin;
	num pow1(*this);
	while(!(k.size()==1 && k[0]==1))
	{
		bin.push(!__builtin_ctz(k[0])); //last bit
		bool add=false;
		for(int i=k.size()-1; i>=0; --i)
		{
			if(add) k[i]+=BASE;
			if(!__builtin_ctz(k[i])) add=true; //if(__builtin_ctz(k[i])==0)
			else add=false;
			k[i]>>=1;
		}
		if(!k[k.size()-1]) k.pop_back(); //if(k[k.size()-1]==0)
	}
	while(!bin.empty())
	{
		this->operator*=(*this);
		if(bin.top()) this->operator*=(pow1);
		bin.pop();
	}
return *this;
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
	for(int i=--k; i>=0; --i)
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

void wypisz(vector<int> a)
{
	int k=a.size()-1;
	cout << a[k];
	for(int i=k-1; i>=0; --i)
	{
		cout.width(9);
		cout.fill('0');
		cout << a[i];
	}
}

int main()
{
	num a;
	num b;
	get(a);
	get(b);
	echo(a+=b);
	cout << endl;
return 0;
}
