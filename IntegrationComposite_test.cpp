#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	//Preparation for computation
	double lower, upper, step1,step2,step3,result;//Declare parameters
	cout<<"Please input lower, upper bound of the integrating interval:"<<endl;
	cin>>lower>>upper;//Input bound of interval
	cout<<"Please designate integrating steps ht, hs, hm:"<<endl;
	cin>>step1>>step2>>step3;//Input integrating step
	double compTrap(double a, double b, double h);
	//Declare composite Trapezoidal rule
	double compSimp(double a, double b, double h);
	//Declare composite Simpson's rule
	double compMidp(double a, double b, double h);
	//Declare compsoite Midpoint rule
	
	//Trapzoidal	
	result=compTrap(lower,upper,step1);
	cout<<"Result computed using composite trapezoidal rule:"<<result<<endl;
	//Composite Trapezoidal rule solution
	
	//Simpson's
	result=compSimp(lower,upper,step2);
	cout<< "Result computed using composite Simpson's rule:"<<result<<endl;
	//Composite Simpson's rule solution
	
	//Midpoint
	result=compMidp(lower,upper,step3);
	cout<< "Result computed using composite Midpoint rule:"<<result<<endl;
	return 0; 
	//Composite Midpoint rule solution
}

double function(double x)//Define the integrated function f(x)
{
	double z;
	z=exp(2*x)*sin(3*x);// f(x) defination
	return z;
}

double compTrap(double a,double b,double step)
{
	double sum,result;
	int i,n;
	
	n=(b-a)/step;
	//Calculating iteration time
	
	sum=(function(a)+function(b))/2;
	for (i=1;i<n;i++)
	{
		sum=sum+function(a+step*i);
		//iterating step point terms
	}
	result=sum*step;
	return result;
}

double compSimp(double a,double b,double step)
{
	double sum,result;
	int i,N;
	
	N=(b-a)/(2.0*step)-1.0;
	//Calculating iteration time
	
	sum=(function(a)+function(b));
	for(i=1.0;i<=N;i++)
	{
		sum=sum+(2.0*function(a+2.0*i*step)+4.0*function(a+(2.0*i-1.0)*step));
		//iteratie to (n/2-1) term
	}
	result=step*(sum+4.0*function(a+(2.0*N+1.0)*step))/3.0;
	//Add on the single n/2 term 
	return result;
}
double compMidp(double a,double b,double step)
{
	double sum,result;
	int i,N;
	
	N=(b-a)/(2*step);
	//Calculating iteration time
	
	sum=0.0;
	for(i=0;i<=N;i++)
	{
		sum=sum+function(a+2*i*step);
	}
	result=2*step*sum;
	return result; 
}
