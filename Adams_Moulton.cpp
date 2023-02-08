#include<iostream>
#include<cmath>

using namespace std;

//Adams_Moulton Method for IVP
int main()
{
	double a, b, h, w, t, aSol, error;
	double t_2,w3_0,w3_1,w3_2;
	double w0,w1,w2;
	
	double f(double x, double yi);
	double actSolF(double t);
	
	
	double Adams_Moulton_3(double x, double w0, double w1, double w2, double h);
		
	int N,i;
	
	cout<<"Input the lower and upper bounds of the problem:"<<endl; 
	cin>>a>>b;
	cout<<"Input the width of time interval applied:"<<endl;
	cin>>h;
	cout<<"Input the initial condition:";
	cin>>w;
	
	N=(b-a)/h;
	
	t_2=a+2*h;//Initial time position for Step 4 Method
	
	w0=w;	
	w1=actSolF(a+h);
	w2=actSolF(t_2);
	
	///////////////////////////////////////////////////////
	//Initiation of Adams_Moulton Method of Order 3
	
	w3_0=w0;w3_1=w1;w3_2=w2;
	
	//Iteration for	Adams_Moulton Method of Order 3
	cout<<"Output the result for Adams-Bashforth 4 Steps Method: "<<endl;
	
	for (i=1;i<(N-2);i++)
	{
		w=Adams_Moulton_3(t_2,w3_0,w3_1,w3_2,h);
		
		t_2=t_2+h;
		
		w3_0=w3_1; w3_1=w3_2; w3_2=w; 
		
		aSol=actSolF(t_2);
		error=fabs(aSol-w);
		
		cout<<"Step: "<<i<<", Time: "<<t_2<<"s, Function Value: "<<w<<", Actual Solution: "<<aSol<<", Error: "<<error<<endl;
	}	
	
	w=Adams_Moulton_3(t_2,w3_0,w3_1,w3_2,h);
		
	t_2=t_2+h;
		
	aSol=actSolF(t_2);
	error=fabs(aSol-w);
		
	cout<<"Step: "<<i<<", Time: "<<t_2<<"s, Function Value: "<<w<<", Actual Solution: "<<aSol<<", Error: "<<error<<endl;
	///////////////////////////////////////////////////////
		
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

//Adams_Moulton 3 Step Method
double Adams_Moulton_3(double x, double w0, double w1, double w2, double h)
{
	double w;
	
	w=4*w2/(3*h+4)+h*(9*(x+h)*exp(3*(x+h))+19*f(x,w2)-5*f(x-h,w1)+f(x-2*h,w0))/(18*h+24);
	
	return w;
}


