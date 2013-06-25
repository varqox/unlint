#include <cstring>
#include <cstdio>
#include <cmath>
#include <complex>
#define REP(i,n) for(int i=0;i<n;++i)
#define MAX 1000010
#define BASE 10000
#define D double
#define LL long long
using namespace std;
 
char tmp1[MAX], tmp2[MAX];
LL res[MAX];
complex <D> *l1, *l2, *l3;
complex <D> w[MAX];
int d;
 
inline int pot2(const int &a){
	for(int i=1;;i*=2) if(i>=a) return i;
}
 
void omega(const int &n, complex<D> w[], const bool &t){
	int to=n/2;
	if(t) REP(i,to){ 
			w[i]=complex<D>(cos(2*M_PI*i/n),sin(2*M_PI*i/n));
			w[i+to]=complex<D>(-w[i].real(),-w[i].imag());
		  }
	else REP(i,to){ 
			w[i]=complex<D>(cos(2*M_PI*i/n),sin(-2*M_PI*i/n));
			w[i+to]=complex<D>(-w[i].real(),-w[i].imag());
		 }
}
 
complex <D> * FFT(complex <D> * A, const int &size){
	if(size==1) return A;
	int to=size/2;
	complex <D> *X = new complex <D> [to];
	complex <D> *Y = new complex <D> [to];
	for(int i=0,j=0;i<size;i+=2,j++) { X[j]=A[i]; Y[j]=A[i+1]; }
	delete[] A;
	X=FFT(X,to);
	Y=FFT(Y,to);
	complex <D> *B = new complex <D> [size];
	int skip=0;
	int pot=(d/size);
	REP(i,to){ 
		B[i]=(X[i]+w[skip]*Y[i]);
		B[i+to]=(X[i]-w[skip]*Y[i]);
		skip+=pot;
	}
	delete[] X;
	delete[] Y;
	return B;
}
 
int main(){
	int z,d1,d2,t1,t2,base=4;
	scanf("%d",&z);
	while(z--){
		scanf("%s %s",tmp1,tmp2);
		t1=strlen(tmp1);
		d1=t1/base;
		if(t1%base!=0) d1++;
		t2=strlen(tmp2);
		d2=t2/base;	
		if(t2%base!=0) d2++;
		d=pot2(d1+d2);
 
		l1 = new complex <D> [d];
		l2 = new complex <D> [d];
 
		REP(i,d) l1[i]=l2[i]=complex <D> (0.0,0.0);
 
		for(int i=t1-1,j=0;i>=0;j++)
			for(int pot=1;i>=0&&pot<BASE;pot*=10,i--) l1[j]+=pot*(tmp1[i]-'0');
		for(int i=t2-1,j=0;i>=0;j++)
			for(int pot=1;i>=0&&pot<BASE;pot*=10,i--) l2[j]+=pot*(tmp2[i]-'0');
 
		omega(d,w,1);
		l1=FFT(l1,d);
		l2=FFT(l2,d);
 
		l3 = new complex <D> [d];
		REP(i,d) l3[i]=l1[i]*l2[i];
 
		delete[] l1;
		delete[] l2;
 
		omega(d,w,0);
		l3=FFT(l3,d);
 
		D s=1.0/d;
		REP(i,d) res[i]=round(l3[i].real()*s);
 
		REP(i,d-1){ 
			res[i+1]+=(res[i]/BASE);
			res[i]%=BASE;
		}
		bool ok=0;
		for(int i=d-1;i>=0;i--){
			if(ok==0){
				if(res[i]!=0){
					ok=1;
					printf("%lld",res[i]);	
				}
			}else printf("%.4lld",res[i]);				
		}
		printf("\n");
 
		delete[] l3;
	}
	return 0;
}
/*
#include <iostream>

using namespace std;

class lol
{
	class k;
};

class lol::k
{
	int a, b;
};

int main()
{
	
return 0;
}
*/