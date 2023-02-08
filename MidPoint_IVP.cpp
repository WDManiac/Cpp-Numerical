#include<iostream>
#include<cmath>

using namespace std;

//Midpoint Method for IVP
int main()
{
	double a, b, h, w, t, aSol, error;
	double f(double x, double yi);
	double actSolF(double t);
	int N,i;
	
	cout<<"Input the lower and upper bounds of the problem:"<<endl; 
	cin>>a>>b;
	cout<<"Input the width of time interval applied:"<<endl;
	cin>>h;
	cout<<"Input the initial condition:";
	cin>>w;
	
	N=(b-a)/h;
	
	t=a;
	
	for (i=1;i<N;i++)
	{
		w=w+h*f(t+0.5*h,w+h*0.5*f(t,w));
		
		t=t+h;
		
		aSol=actSolF(t);
		error=fabs(aSol-w);
		
		cout<<"Step: "<<i<<", Time: "<<t<<"s, Function Value: "<<w<<", Actual Solution: "<<aSol<<", Error: "<<error<<endl;
	}	
	
	w=w+h*f(t+0.5*h,w+h*0.5*f(t,w));
	
	t=t+h;	
	
	aSol=actSolF(t);
	error=fabs(aSol-w);
		
	cout<<"Step: "<<i<<", Time: "<<t<<"s, Function Value: "<<w<<", Actual Solution: "<<aSol<<", Error: "<<error<<endl;
		
	return 0;
}
///////////////////////////////////////////////////////

//Setting up differential equation
double f(double x, double yi)
{
	double yi_1;
	
	yi_1=x*exp(3*x)-2*yi;
	
	return yi_1;
}
///////////////////////////////////////////////////////

//Actual solution
double actSolF(double t)
{
	double sol;
	
	sol=t*exp(3*t)/5-exp(3*t)/25+exp(-2*t)/25;
	
	return sol;
}
///////////////////////////////////////////////////////
