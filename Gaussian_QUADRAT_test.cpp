#include<iostream>
#include<cmath>

using namespace std;

#define f(x) (x*x*log(x))//Define f(x)	
#define t1 0.5773502692
#define t2 -0.5773502692//n=2 thus root of Legendre poly is determined
#define c1 1.0
#define c2 1.0//n=2 thus c1, c2 could be determined

int main()
{
	double a,b,result,x1,x2;
	cout<<"Please input the lower and upper bound of integrating interval:"<<endl;
	cin>>a>>b;
	
	x1=((b-a)*t1+b+a)/2;
	x2=((b-a)*t2+b+a)/2;//Determine x1, x2 using t1, t2
	
	result=(c1*f(x1)+c2*f(x2))*(b-a)/2;
	cout<<"Final result using Gauss quadrature of n=2 :"<<result<<endl;
	
	return 0;
}
