#include <iostream>

using namespace std;

#ifndef unlint_h
#define unlint_h

#include <vector>
#include <bits/localefwd.h>
#include <string>
#include <string.h>

using namespace std;

const int L=9, BASE=1000000000;

inline void MINUS(vector<int> &a, vector<int> &b)
{
    int al=a.size(), bl=b.size();
    bool p=0;
    for(int i=0; i<bl; i++)
    {
        a[i]-=b[i]+p;
        if(a[i]<0){a[i]+=BASE;p=1;}
        else{p=0;}
    }
    for(int i=bl; i<al; i++)
    {
        a[i]-=p;
        if(a[i]<0){a[i]+=BASE;p=1;}
        else{break;}
    }
}

inline void PLUS(vector<int> &a,vector<int> &b)
{
    int al=a.size(), bl=b.size();
    bool p=0;
    if(al<bl){a.insert(a.end(), bl-al, 0);al=a.size();}
    for(int i=0; i<bl; i++)
    {
        a[i]+=b[i]+p;
        if(a[i]>=BASE){a[i]-=BASE;p=1;}
        else{p=0;}
    }
    for(int i=bl; i<al; i++)
    {
        a[i]+=p;
        if(a[i]>=BASE){a[i]-=BASE;p=1;}
        else{p=0;break;}
    }
    if(p>0) a.push_back(p);
}

inline bool ISLARGER(vector<int> &a,vector<int> &b)
{
    int al=a.size(), bl=b.size();
    if(al<bl) return 0;
    else if(al>bl) return 1;
    else
    {
        int i=al-1;
        while(i>=0 && a[i]==b[i])
        {
            i--;
        }
        if(i<0) return 0;
        else if(a[i]>b[i]) return 1;
    }
return 0;
}

inline void MUL(vector<int> &a,int &b)
{
    int al=a.size();
    long long int gd, p1=0;
    for(int i=0; i<al; i++)
    {
        gd=(long long int)(a[i])*b+p1;
        p1=gd/BASE; 
        a[i]=gd-p1*BASE;
    }
    if(p1>0){a.push_back(p1);}
    int o=0, i=a.size()-1;
    while(i>0 && a[i]==0)
    {
        o++;
        i--;
    }
    a.erase(a.end()-o, a.end());
}

class unlint
{
private:
    char z;
    vector<int> l;
    void kas0();
public:
    unlint();
    unlint(const char* a);
    unlint(char* a);
    unlint(string a);
    unlint(int a);
    unlint(long long int a);
    unlint(short int a);
    unlint(char a);
    unlint(bool a);
    ~unlint(){};
    void operator=(unlint a);
    void operator=(char* s);
    void operator=(const char* s);
    void operator=(string s);
    template<typename typ>
    void operator=(typ a);
    void swap(unlint &b);
    int size();
    string str();
    char* c_str();
    void operator++();
    void operator--();
    void operator++(int);
    void operator--(int);
    unlint operator+();
    unlint operator-();
    unlint operator+(unlint b);
    void operator+=(unlint b);
    unlint operator-(unlint b);
    void operator-=(unlint b);
    unlint operator*(unlint b);
    void operator*=(const unlint& b);
    unlint operator/(unlint b);
    void operator/=(unlint b);
    unlint operator%(unlint b);
    void operator%=(unlint b);
    void pow(unlint b);
    void factorial();
    friend bool operator>(unlint a, unlint b);
    friend bool operator<(unlint a, unlint b);
    friend bool operator==(unlint a, unlint b);
    friend bool operator>=(unlint a, unlint b);
    friend bool operator<=(unlint a, unlint b);
    friend bool operator!=(unlint a, unlint b);
    friend unlint nwd(unlint a, unlint b);
};

inline void unlint::kas0()
{
    int o=0, i=l.size()-1;
    while(i>0 && l[i]==0)
    {
        o++;
        i--;
    }
    l.erase(l.end()-o, l.end());
    if(l.size()==1 && l[0]==0) z=1;
}

inline unlint::unlint()
{
    l.push_back(0);
    z=1;
}

inline unlint::unlint(const char* a)
{
    operator=(a);
}

inline unlint::unlint(char* a)
{
    operator=(a);
}

inline unlint::unlint(string a)
{
    operator=(a);
}

inline unlint::unlint(int a)
{
    l.clear();
    if(a==0) l.push_back(0);
    if(a<0){a=-a;z=0;}
    else z=1;
    while(a>0)
    {
        l.push_back(a%BASE);
        a/=BASE;
    }
    kas0();
}

inline unlint::unlint(long long int a)
{
    l.clear();
    if(a==0) l.push_back(0);
    if(a<0){a=-a;z=0;}
    else z=1;
    while(a>0)
    {
        l.push_back(a%BASE);
        a/=BASE;
    }
    kas0();
}

inline unlint::unlint(short int a)
{
    l.clear();
    if(a==0) l.push_back(0);
    if(a<0){a=-a;z=0;}
    else z=1;
    while(a>0)
    {
        l.push_back(a%BASE);
        a/=BASE;
    }
    kas0();
}

inline unlint::unlint(char a)
{
    l.clear();
    if(a==0) l.push_back(0);
    if(a<0){a=-a;z=0;}
    else z=1;
    while(a>0)
    {
        l.push_back(a%BASE);
        a/=BASE;
    }
    kas0();
}

inline unlint::unlint(bool a)
{
    l.clear();
    if(a==0) l.push_back(0);
    if(a<0){a=-a;z=0;}
    else z=1;
    while(a>0)
    {
        l.push_back(a%BASE);
        a/=BASE;
    }
    kas0();
}

inline void unlint::operator=(unlint a)
{
    z=a.z;
    l.swap(a.l);
}

inline void unlint::operator=(char* s)
{
    int j=strlen(s)-1, i=0, g=0, p=strlen(s);
    if(p%9>0){p/=9;p++;}
    else p/=9;
    l.clear();
    if(s[0]=='-'){g++;z=0;}
    else z=1;
    while(j>=g)
    {
        l.push_back(0);
        for(int k=max(g,j-L+1); k<=j; k++)
        {
            l[i]=10*l[i]+(s[k]-'0');
        }
        j-=L;
        i++;
     }
    kas0();
}

inline void unlint::operator=(const char* s)
{
    int j=strlen(s)-1, i=0, g=0, p=strlen(s);
    if(p%9>0){p/=9;p++;}
    else p/=9;
    l.clear();
    if(s[0]=='-'){g++;z=0;}
    else z=1;
    while(j>=g)
    {
        l.push_back(0);
        for(int k=max(g,j-L+1); k<=j; k++)
        {
            l[i]=10*l[i]+(s[k]-'0');
        }
        j-=L;
        i++;
    }
    kas0();
}

inline void unlint::operator=(string s)
{
    int j=s.size()-1, i=0, g=0;
    l.clear();
    if(s[0]=='-'){g++;z=0;}
    else z=1;
    while(j>=g)
    {
        l.push_back(0);
        for(int k=max(g,j-L+1); k<=j; k++)
        {
            l[i]=10*l[i]+(s[k]-'0');
        }
        j-=L;
        i++;
    }
    kas0();
}

template<typename typ>
inline void unlint::operator=(typ a)
{
    l.clear();
    if(a==0) l.push_back(0);
    if(a<0){a=-a;z=0;}
    else z=1;
    while(a>0)
    {
        l.push_back(a%BASE);
        a/=BASE;
    }
    kas0();
}

inline void unlint::swap(unlint &b)
{
    std::swap(z, b.z);
    l.swap(b.l);
}

inline int unlint::size()
{
    int s=l.size(), w=L*(s-1), d;
    d=l[s-1];
    if(d<100000)
    {
        if(d<1000)
        {
            if(d<10){w+=1;}
            else if(d<100){w+=2;}
            else{w+=3;}
        }
        else
        {
            if(d<10000){w+=4;}
            else{w+=5;}
        }
    }
    else
    {
        if(d<10000000)
        {
            if(d<1000000){w+=6;}
            else{w+=7;}
        }
        else
        {
            if(d<100000000){w+=8;}
            else{w+=9;}
        }
    }
return w;
}

inline string unlint::str()
{
    string str;
    char h[]="000000000";
    int i=0, j, k=size()-1;
    if(!z){str.resize(k+2);str[0]='-';i++;k++;}
    else str.resize(k+1);
    int s=l.size(), d;
    d=l[s-1];
    for(int j=8; j>=0; j--)
    {
        h[j]=48+d%10;
        d/=10;
    }
    for(j=0; j<8; j++)
        if(h[j]!=48) break;
    for(;j<9; j++)
    {
        str[i]=h[j];
        i++;
    }
    for(int y=0; y<s-1; y++)
    {
        d=l[y];
        for(j=0; j<9; j++)
        {
            str[k]=48+d%10;
            d/=10;
            k--;
        }
    }
return str;
}

inline char* unlint::c_str()
{
    char *t, h[]="000000000";
    int i=0, j, k=size()-1;
    if(!z){t=new char[k+3];t[0]='-';i++;k++;}
    else t=new char[k+2];
    t[k+1]='\0';
    int s=l.size(), d;
    d=l[s-1];
    for(int j=8; j>=0; j--)
    {
        h[j]=48+d%10;
        d/=10;
    }
    for(j=0; j<8; j++)
        if(h[j]!=48) break;
    for(;j<9; j++)
    {
        t[i]=h[j];
        i++;
    }
    for(int y=0; y<s-1; y++)
    {
        d=l[y];
        for(j=0; j<9; j++)
        {
            t[k]=48+d%10;
            d/=10;
            k--;
        }
    }
return t;
}

inline void unlint::operator++()
{
    bool p=1;
    int ll=l.size();
    if(z)
    {
        for(int i=0; i<ll; i++)
        {
            l[i]+=p;
            if(l[i]>=BASE){l[i]-=BASE;p=1;}
            else{p=0;break;}
        }
        if(p)
        {
            l.push_back(1);
        }
    }
    else
    {
        if(l.size()==1 && l[0]==1){z=1;l[0]=0;}
        else
        {
            for(int i=0; i<ll; i++)
            {
                l[i]-=p;
                if(l[i]<0){l[i]+=BASE;p=1;}
                else{break;}
            }
            kas0();
        }
    }
}

inline void unlint::operator--()
{
    bool p=1;
    int ll=l.size();
    if(z)
    {
        if(l.size()==1 && l[0]==0){z=0;l[0]=1;}
        else
        {
            for(int i=0; i<ll; i++)
            {
                l[i]-=p;
                if(l[i]<0){l[i]+=BASE;p=1;}
                else{break;}
            }
            kas0();
        }
    }
    else
    {
        for(int i=0; i<ll; i++)
        {
            l[i]+=p;
            if(l[i]>=BASE){l[i]-=BASE;p=1;}
            else{p=0;break;}
        }
        if(p)
        {
            l.push_back(1);
        }
    }
}

inline void unlint::operator++(int)
{
    bool p=1;
    int ll=l.size();
    if(z)
    {
        for(int i=0; i<ll; i++)
        {
            l[i]+=p;
            if(l[i]>=BASE){l[i]-=BASE;p=1;}
            else{p=0;break;}
        }
        if(p)
        {
            l.push_back(1);
        }
    }
    else
    {
        if(l.size()==1 && l[0]==1){z=1;l[0]=0;}
        else
        {
            for(int i=0; i<ll; i++)
            {
                l[i]-=p;
                if(l[i]<0){l[i]+=BASE;p=1;}
                else{break;}
            }
            kas0();
        }
    }
}

inline void unlint::operator--(int)
{
    bool p=1;
    int ll=l.size();
    if(z)
    {
        if(l.size()==1 && l[0]==0){z=0;l[0]=1;}
        else
        {
            for(int i=0; i<ll; i++)
            {
                l[i]-=p;
                if(l[i]<0){l[i]+=BASE;p=1;}
                else{break;}
            }
            kas0();
        }
    }
    else
    {
        for(int i=0; i<ll; i++)
        {
            l[i]+=p;
            if(l[i]>=BASE){l[i]-=BASE;p=1;}
            else{p=0;break;}
        }
        if(p)
        {
            l.push_back(1);
        }
    }
}

inline unlint unlint::operator+()
{
    unlint w;
    w.l=l;
    w.z=z;
return w;
}

inline unlint unlint::operator-()
{
    unlint w;
    w.l=l;
    if(!(l.size()==0 && l[0]==0)) w.z=!z;
return w;
}

inline unlint unlint::operator+(unlint b)
{
    unlint w;
    if(z==b.z)
    {
        w.z=z;
        w.l=l;
        PLUS(w.l, b.l);
    }
    else
    {
        if(ISLARGER(l, b.l))
        {
            w.l=l;
            MINUS(w.l, b.l);w.kas0();
            if(z){w.z=1;}
            else{w.z=0;}
        }
        else
        {
            w=b;
            MINUS(w.l, l);w.kas0();
            if(w.l.size()==1 && w.l[0]==0){w.z=1;}
            else if(z){w.z=0;}
            else{w.z=1;}
        }
    }
return w;
}

inline void unlint::operator+=(unlint b)
{
    if(z==b.z){PLUS(l, b.l);}
    else
    {
        if(ISLARGER(l, b.l))
        {
            MINUS(l, b.l);kas0();
            if(b.z){z=0;}
            else{z=1;}
        }
        else
        {
            MINUS(b.l, l);b.kas0();l=b.l;
            if(l.size()==1 && l[0]==0) z=1;
            else if(z) z=0;
            else z=1;
        }
    }
}

inline unlint unlint::operator-(unlint b)
{
    b.z=!b.z;
    unlint w;
    if(z==b.z)
    {
        w.z=z;
        w.l=l;
        PLUS(w.l, b.l);
    }
    else
    {
        if(ISLARGER(l, b.l))
        {
            w.l=l;
            MINUS(w.l, b.l);w.kas0();
            if(z){w.z=1;}
            else{w.z=0;}
        }
        else
        {
            w=b;
            MINUS(w.l, l);w.kas0();
            if(w.l.size()==1 && w.l[0]==0){w.z=1;}
            else if(z){w.z=0;}
            else{w.z=1;}
        }
    }
return w;
}

inline void unlint::operator-=(unlint b)
{
    b.z=!b.z;
    if(z==b.z){PLUS(l, b.l);}
    else
    {
        if(ISLARGER(l, b.l))
        {
            MINUS(l, b.l);kas0();
            if(b.z){z=0;}
            else{z=1;}
        }
        else
        {
            MINUS(b.l, l);b.kas0();l=b.l;
            if(l.size()==1 && l[0]==0) z=1;
            else if(z) z=0;
            else z=1;
        }
    }
}

inline unlint unlint::operator*(unlint b)
{
    if(z==b.z) b.z=1;
    else b.z=0;
    int al=l.size(), bl=b.l.size(), od=0;
    long long int g, p;
    vector<int> w(1), k;
    for(int i=0; i<bl; i++)
    {
        p=0;
        k.resize(al);
        for(int j=0; j<al; j++)
        {
            g=(long long int)(l[j])*b.l[i]+p;
            p=g/BASE;
            k[j]=g-p*BASE;
        }
        if(p>0){k.push_back(p);}
        int o=0, iy=k.size()-1;
        while(iy>0 && k[iy]==0)
        {
            o++;
            iy--;
        }
        k.erase(k.end()-o, k.end());
        int wl=w.size()-od, kl=k.size(), p=0;
        if(wl<kl){w.insert(w.end(), kl-wl, 0);wl=w.size()-od;}
        for(int j=0; j<kl; j++)
        {
            w[j+od]+=k[j]+p;
            if(w[j+od]>=BASE){w[j+od]-=BASE;p=1;}
            else{p=0;}
        }
        for(int j=kl; j<wl; j++)
        {
            w[j+od]+=p;
            if(w[j+od]>=BASE){w[j+od]-=BASE;p=1;}
            else{p=0;break;}
        }
        if(p>0)
        {
            w.push_back(p);
        }
        od++;
    }
    b.l.swap(w);
    b.kas0();
return b;
}

inline void unlint::operator*=(const unlint& _u)
{
    if(z==_u.z) z=1;
    else z=0;
    int al=l.size(), bl=_u.l.size(), od=0;
	long long int g, p;
	vector<int> w(1), k;
	for(int i=0; i<bl; i++)
	{
		p=0;
		k.resize(al);
		for(int j=0; j<al; j++)
		{
			g=(long long int)(l[j])*_u.l[i]+p;
			p=g/BASE;
			k[j]=g-p*BASE;
		}
		if(p>0){k.push_back(p);}
		int o=0, ik=k.size()-1;
		while(ik>0 && k[ik]==0)
		{
			o++;
			ik--;
		}
		k.erase(k.end()-o, k.end());
		int wl=w.size()-od, kl=k.size(), p=0;
		if(wl<kl){w.insert(w.end(), kl-wl, 0);wl=w.size()-od;}
		for(int j=0; j<kl; j++)
		{
			w[j+od]+=k[j]+p;
			if(w[j+od]>=BASE){w[j+od]-=BASE;p=1;}
			else{p=0;}
		}
		for(int j=kl; j<wl; j++)
		{
			w[j+od]+=p;
			if(w[j+od]>=BASE){w[j+od]-=BASE;p=1;}
			else{p=0;break;}
		}
		if(p>0)
		{
			w.push_back(p);
		}
		od++;
	}
	l.swap(w);
	kas0();
}

inline unlint unlint::operator/(unlint b)
{
    if(z==b.z) b.z=1;
    else b.z=0;
    if(ISLARGER(b.l, l)){b=0;return b;}
    vector<int> a=l;
    int al=a.size(), bl=b.l.size(), iws=al-bl;
    vector<int> w(iws+1), g;
    while(iws>=0)
    {
        bool wr;
        if(al-iws<bl) wr=0;
        else if(al-iws>bl) wr=1;
        else
        {
            int i=bl-1;
            while(i>=0 && a[i+iws]==b.l[i])
            {
                i--;
            }
            if(i<0) wr=1;
            else if(a[i+iws]>b.l[i]) wr=1;
            else wr=0;
        }
        if(wr)
        {
            int p=0, k=999999999, c;
            while(p<k)
            {
                c=(p+k)/2+1;
                g=b.l;
                MUL(g, c);
                int gl=g.size();
                if(al-iws<gl) wr=1;
                else if(al-iws>gl) wr=0;
                else
                {
                    int i=gl-1;
                    while(i>=0 && a[i+iws]==g[i])
                    {
                        i--;
                    }
                    if(i<0) wr=0;
                    else if(g[i]>a[i+iws]) wr=1;
                    else wr=0;
                }
                if(wr) k=c-1;
                else p=c;
            }
            g=b.l;
            MUL(g, p);
            int gl=g.size(), prz=0;
            for(int i=0; i<gl; i++)
            {
                a[i+iws]-=g[i]+prz;
                if(a[i+iws]<0){a[i+iws]+=BASE;prz=1;}
                else{prz=0;}
            }
            for(int i=gl+iws; i<al; i++)
            {
                a[i]-=prz;
                if(a[i]<0){a[i]+=BASE;prz=1;}
                else{break;}
            }
            int o=0, iq=a.size()-1;
            while(iq>0 && a[iq]==0)
            {
                o++;
                iq--;
            }
            a.erase(a.end()-o, a.end());
            al=a.size();
            w[iws]=p;
        }
        iws--;
    }
    b.l.swap(w);
    b.kas0();
return b;
}

inline void unlint::operator/=(unlint b)
{
    if(b.z==z) z=1;
    else z=0;
    if(ISLARGER(b.l, l)){operator=(0);return;}
    int al=l.size(), bl=b.l.size(), iws=al-bl;
    vector<int> w(iws+1), g;
    while(iws>=0)
    {
        bool wr;
        if(al-iws<bl) wr=0;
        else if(al-iws>bl) wr=1;
        else
        {
            int i=bl-1;
            while(i>=0 && l[i+iws]==b.l[i])
            {
                i--;
            }
            if(i<0) wr=1;
            else if(l[i+iws]>b.l[i]) wr=1;
            else wr=0;
        }
        if(wr)
        {
            int p=0, k=999999999, c;
            while(p<k)
            {
                c=(p+k)/2+1;
                g=b.l;
                MUL(g, c);
                int gl=g.size();
                if(al-iws<gl) wr=1;
                else if(al-iws>gl) wr=0;
                else
                {
                    int i=gl-1;
                    while(i>=0 && l[i+iws]==g[i])
                    {
                        i--;
                    }
                    if(i<0) wr=0;
                    else if(g[i]>l[i+iws]) wr=1;
                    else wr=0;
                }
                if(wr) k=c-1;
                else p=c;
            }
            g=b.l;
            MUL(g, p);
            int gl=g.size(), prz=0;
            for(int i=0; i<gl; i++)
            {
                l[i+iws]-=g[i]+prz;
                if(l[i+iws]<0){l[i+iws]+=BASE;prz=1;}
                else{prz=0;}
            }
            for(int i=gl+iws; i<al; i++)
            {
                l[i]-=prz;
                if(l[i]<0){l[i]+=BASE;prz=1;}
                else{break;}
            }
            int o=0, i=l.size()-1;
            while(i>0 && l[i]==0)
            {
                o++;
                i--;
            }
            l.erase(l.end()-o, l.end());
            al=l.size();
            w[iws]=p;
        }
        iws--;
    }
    l.swap(w);
    kas0();
}

inline unlint unlint::operator%(unlint b)
{
    vector<int> a=l;
    if(!ISLARGER(b.l, a))
    {
        int al=a.size(), bl=b.l.size(), iws=al-bl;
        vector<int> g;
        while(iws>=0)
        {
            bool wr;
            if(al-iws<bl) wr=0;
            else if(al-iws>bl) wr=1;
            else
            {
                int i=bl-1;
                while(i>=0 && a[i+iws]==b.l[i])
                {
                    i--;
                }
                if(i<0) wr=1;
                else if(a[i+iws]>b.l[i]) wr=1;
                else wr=0;
            }
            if(wr)
            {
                int p=0, k=999999999, c;
                while(p<k)
                {
                    c=(p+k)/2+1;
                    g=b.l;
                    MUL(g, c);
                    int gl=g.size();
                    if(al-iws<gl) wr=1;
                    else if(al-iws>gl) wr=0;
                    else
                    {
                        int i=gl-1;
                        while(i>=0 && a[i+iws]==g[i])
                        {
                            i--;
                        }
                        if(i<0) wr=0;
                        else if(g[i]>a[i+iws]) wr=1;
                        else wr=0;
                    }
                    if(wr) k=c-1;
                    else p=c;
                }
                g=b.l;
                MUL(g, p);
                int gl=g.size(), prz=0;
                for(int i=0; i<gl; i++)
                {
                    a[i+iws]-=g[i]+prz;
                    if(a[i+iws]<0){a[i+iws]+=BASE;prz=1;}
                    else{prz=0;}
                }
                for(int i=gl+iws; i<al; i++)
                {
                    a[i]-=prz;
                    if(a[i]<0){a[i]+=BASE;prz=1;}
                    else{break;}
                }
                int o=0, iq=a.size()-1;
                while(iq>0 && a[iq]==0)
                {
                    o++;
                    iq--;
                }
                a.erase(a.end()-o, a.end());
                al=a.size();
            }
            iws--;
        }
    }
    unlint t;
    t.l.swap(b.l);
    b.l.swap(a);
    b.kas0();
    if((z==0 && b.z==1) || (z==b.z && b.z==0)){if(!(b.l.size()==1 && b.l[0]==0)){b.z=0;b+=t;}}
    b.z=1;
return b;
}

inline void unlint::operator%=(unlint b)
{
    if(!ISLARGER(b.l, l))
    {
        int al=l.size(), bl=b.l.size(), iws=al-bl;
        vector<int> g;
        while(iws>=0)
        {
            bool wr;
            if(al-iws<bl) wr=0;
            else if(al-iws>bl) wr=1;
            else
            {
                int i=bl-1;
                while(i>=0 && l[i+iws]==b.l[i])
                {
                    i--;
                }
                if(i<0) wr=1;
                else if(l[i+iws]>b.l[i]) wr=1;
                else wr=0;
            }
            if(wr)
            {
                int p=0, k=999999999, c;
                while(p<k)
                {
                    c=(p+k)/2+1;
                    g=b.l;
                    MUL(g, c);
                    int gl=g.size();
                    if(al-iws<gl) wr=1;
                    else if(al-iws>gl) wr=0;
                    else
                    {
                        int i=gl-1;
                        while(i>=0 && l[i+iws]==g[i])
                        {
                            i--;
                        }
                        if(i<0) wr=0;
                        else if(g[i]>l[i+iws]) wr=1;
                        else wr=0;
                    }
                    if(wr) k=c-1;
                    else p=c;
                }
                g=b.l;
                MUL(g, p);
                int gl=g.size(), prz=0;
                for(int i=0; i<gl; i++)
                {
                    l[i+iws]-=g[i]+prz;
                    if(l[i+iws]<0){l[i+iws]+=BASE;prz=1;}
                    else{prz=0;}
                }
                for(int i=gl+iws; i<al; i++)
                {
                    l[i]-=prz;
                    if(l[i]<0){l[i]+=BASE;prz=1;}
                    else{break;}
                }
                int o=0, i=l.size()-1;
                while(i>0 && l[i]==0)
                {
                    o++;
                    i--;
                }
                l.erase(l.end()-o, l.end());
                al=l.size();
            }
            iws--;
        }
    }
    if((z==0 && b.z==1) || (z==b.z && b.z==0)){if(!(l.size()==1 && l[0]==0)){z=0;b.z=1;operator+=(b);}}
    z=1;
}
inline void unlint::pow(unlint b)
{
    bool wz;
    if(!z && b.l[0]%2==1){wz=0;}
    else{wz=1;}
    z=1;
    if(!b.z && !(l.size()==1 && l[0]==1)){operator=(0);return;}
    else if(b.l.size()==1 && b.l[0]==0){operator=(1);}
    else
    {
        unlint wk, d=1;
        wk.l=l;
        vector<bool> bin;
        while(b>d)
        {
            if(b.l[0]%2==1){bin.push_back(1);b.l[0]-=1;}
            else{bin.push_back(0);}
            int r=0, pom;
            for(int i=b.l.size()-1; i>=0; i--)
            {
                pom=b.l[i];
                {
                    b.l[i]+=BASE*r;
                    b.l[i]/=2;
                }
                r=pom-b.l[i]*2;
            }
            if(b.l[b.l.size()-1]==0){b.l.pop_back();}
        }
        int bins=bin.size();
        for(int ir=bins-1; ir>=0; ir--)
        {
            this->operator*=(*this);
            if(bin[ir]) operator*=(wk);
        }
    }
    z=wz;
}

inline void unlint::factorial()
{
    z=1;
    unlint w=1, d=1;
    w.l.swap(l);
    while(d<=w)
    {
        operator*=(d);
        d++;
    }
}

inline bool operator>(unlint a, unlint b)
{
    if(a.z && !b.z) return 1;
    if(!a.z && b.z) return 0;
    if(!a.z && !b.z){return ISLARGER(b.l, a.l);}
return 
    ISLARGER(a.l, b.l);
}

inline bool operator<(unlint a, unlint b)
{
    if(a.z && !b.z) return 0;
    if(!a.z && b.z) return 1;
    if(!a.z && !b.z){return ISLARGER(a.l, b.l);}
return 
    ISLARGER(b.l, a.l);
}

inline bool operator==(unlint a, unlint b)
{
    if(a.z!=b.z) return 0;
    int al=a.l.size(), bl=b.l.size();
    if(al!=bl){return 0;}
    int i=al-1;
    while(i>=0 && a.l[i]==b.l[i])
    {
        i--;
    }
    if(i<0){return 1;}
return 0;
}

inline bool operator>=(unlint a, unlint b)
{
    if(a.z && !b.z) return 1;
    if(!a.z && b.z) return 0;
    if(!a.z && !b.z){return !ISLARGER(a.l, b.l);}
return !
    ISLARGER(b.l, a.l);
}

inline bool operator<=(unlint a, unlint b)
{
    if(a.z && !b.z) return 0;
    if(!a.z && b.z) return 1;
    if(!a.z && !b.z){return !ISLARGER(b.l, a.l);}
return !
    ISLARGER(a.l, b.l);
}

inline bool operator!=(unlint a, unlint b)
{
    if(a.z!=b.z) return 1;
    int al=a.l.size(), bl=b.l.size();
    if(al!=bl){return 1;}
    int i=al-1;
    while(i>=0 && a.l[i]==b.l[i])
    {
        i--;
    }
    if(i<0){return 0;}
return 1;
}

inline unlint nwd(unlint a, unlint b)
{
    a.z=1;
    b.z=1;
    unlint d=0, c;
    while(b!=d)
    {
        c.l.swap(a.l);
        c%=b;
        a.l.swap(b.l);
        b.l.swap(c.l);
    }
return a;
}

inline unlint pow(unlint a, unlint b)
{
    a.pow(b);
return a;
}

inline unlint factorial(unlint a)
{
    a.factorial();
return a;
}

template<typename _CharT, typename _Traits>
inline std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& os, unlint str)
    {return os << str.str();}

template<typename _CharT, typename _Traits>
inline std::basic_istream<_CharT,_Traits>&
    operator>>(std::basic_istream<_CharT,_Traits>& __is, unlint& str)
    {
        string a;
        std::basic_istream<_CharT,_Traits>& __res = __is >> a;
        str=a;
        return __res;
    }

template<typename typ>
inline unlint to_unlint(typ a)
{
    unlint w=a;
return w;
}

#endif

int main()
{
	unlint a, b;
	cin >> a >> b;
    a+=b;
	cout << a << endl;
return 0;
}