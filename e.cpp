#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	//This program is to calculate nature constant e
	//    e=1+1/1!+1/2!+1/3!+1/4!+......+1/n!=2.718
	//    (u_i)=1/i!=[1/(i-1)!]/i=(u_i-1)/i
	
	double e=1.0,u=1.0;
	int n=1;
	
	while(u>=1.0E-7)
	{
		u=u/n;
		e=e+u;
		n=n+1;
	}
	cout<<"e = "<<e<<"(n = "<<n<<")"<<endl;
	
	return 0;
 } 
