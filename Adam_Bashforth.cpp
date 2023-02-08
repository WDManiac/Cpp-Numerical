#include<iostream>
#include<cmath>

using namespace std;

//Adams_Bashforth Method for IVP
int main()
{
	double a, b, h, w, t, aSol, error;
	double t_1,t_2,t_3,t_4;
	double w0,w1,w2,w3,w4;
	double w2_0,w2_1;
	double w3_0,w3_1,w3_2;
	double w4_0,w4_1,w4_2,w4_3;
	double w5_0,w5_1,w5_2,w5_3,w5_4;
	
	double f(double x, double yi);
	double actSolF(double t);
	double Adams_Bashforth_2(double x, double w0, double w1, double h);
	double Adams_Bashforth_3(double x, double w0, double w1, double w2, double h);
	double Adams_Bashforth_4(double x, double w0, double w1, double w2, double w3, double h);
	double Adams_Bashforth_5(double x, double w0, double w1, double w2, double w3, double w4, double h);
	
	int N,i;
	
	cout<<"Input the lower and upper bounds of the problem:"<<endl; 
	cin>>a>>b;
	cout<<"Input the width of time interval applied:"<<endl;
	cin>>h;
	cout<<"Input the initial condition:";
	cin>>w;
	
	N=(b-a)/h;
	
	t_1=a+h;//Initial time position for Step 2 Method
	t_2=a+2*h;//Initial time position for Step 3 Method
	t_3=a+3*h;//Initial time position for Step 4 Method
	t_4=a+4*h;//Initial time position for Step 5 Method
	
	w0=w;	
	w1=actSolF(t_1);
	w2=actSolF(t_2);
	w3=actSolF(t_3);
	w4=actSolF(t_4);
	
	///////////////////////////////////////////////////////
	//Initiation for Step 2 Method
	w2_0=w0; w2_1=w1;
	
	//Iteration for	Adams_Bashforth Method of Order 2
	cout<<"Output the result for Adams-Bashforth 2 Steps Method: "<<endl;
	
	for (i=1;i<(N-1);i++)
	{
		w=Adams_Bashforth_2(t_1,w2_0,w2_1,h);
		
		t_1=t_1+h;
		
		w2_0=w2_1; w2_1=w; 
		
		aSol=actSolF(t_1);
		error=fabs(aSol-w);
		
		cout<<"Step: "<<i<<", Time: "<<t_1<<"s, Function Value: "<<w<<", Actual Solution: "<<aSol<<", Error: "<<error<<endl;
	}	
	
	w=Adams_Bashforth_2(t_1,w2_0,w2_1,h);
		
	t_1=t_1+h;
		
	aSol=actSolF(t_1);
	error=fabs(aSol-w);
		
	cout<<"Step: "<<i<<", Time: "<<t_1<<"s, Function Value: "<<w<<", Actual Solution: "<<aSol<<", Error: "<<error<<endl;
	///////////////////////////////////////////////////////
	
	///////////////////////////////////////////////////////
	//Initiation for Step 3 Method
	w3_0=w0; w3_1=w1; w3_2=w2;
	
	//Iteration for	Adams_Bashforth Method of Order 3
	cout<<"Output the result for Adams-Bashforth 3 Steps Method: "<<endl;
	
	for (i=1;i<(N-2);i++)
	{
		w=Adams_Bashforth_3(t_2,w3_0,w3_1,w3_2,h);
		
		t_2=t_2+h;
		
		w3_0=w3_1; w3_1=w3_2; w3_2=w; 
		
		aSol=actSolF(t_2);
		error=fabs(aSol-w);
		
		cout<<"Step: "<<i<<", Time: "<<t_2<<"s, Function Value: "<<w<<", Actual Solution: "<<aSol<<", Error: "<<error<<endl;
	}	
	
	w=Adams_Bashforth_3(t_2,w3_0,w3_1,w3_2,h);
		
	t_2=t_2+h;
		
	aSol=actSolF(t_2);
	error=fabs(aSol-w);
		
	cout<<"Step: "<<i<<", Time: "<<t_2<<"s, Function Value: "<<w<<", Actual Solution: "<<aSol<<", Error: "<<error<<endl;
	///////////////////////////////////////////////////////
	
	///////////////////////////////////////////////////////
	//Initiation for Step 4 Method
	w4_0=w0; w4_1=w1; w4_2=w2; w4_3=w3;
	
	//Iteration for	Adams_Bashforth Method of Order 4
	cout<<"Output the result for Adams-Bashforth 4 Steps Method: "<<endl;
	
	for (i=1;i<(N-3);i++)
	{
		w=Adams_Bashforth_4(t_3,w4_0,w4_1,w4_2,w4_3,h);
		
		t_3=t_3+h;
		
		w4_0=w4_1; w4_1=w4_2; w4_2=w4_3; w4_3=w; 
		
		aSol=actSolF(t_3);
		error=fabs(aSol-w);
		
		cout<<"Step: "<<i<<", Time: "<<t_3<<"s, Function Value: "<<w<<", Actual Solution: "<<aSol<<", Error: "<<error<<endl;
	}	
	
	w=Adams_Bashforth_4(t_3,w4_0,w4_1,w4_2,w4_3,h);
		
	t_3=t_3+h;
		
	aSol=actSolF(t_3);
	error=fabs(aSol-w);
		
	cout<<"Step: "<<i<<", Time: "<<t_3<<"s, Function Value: "<<w<<", Actual Solution: "<<aSol<<", Error: "<<error<<endl;
	///////////////////////////////////////////////////////
	
	///////////////////////////////////////////////////////
	//Initiation for Step 5 Method
	w5_0=w0; w5_1=w1; w5_2=w2; w5_3=w3; w5_4=w4;
	
	//Iteration for	Adams_Bashforth Method of Order 5
	cout<<"Output the result for Adams-Bashforth 5 Steps Method: "<<endl;
	
	for (i=1;i<(N-4);i++)
	{
		w=Adams_Bashforth_5(t_4,w5_0,w5_1,w5_2,w5_3,w5_4,h);
		
		t_4=t_4+h;
		
		w5_0=w5_1; w5_1=w5_2; w5_2=w5_3; w5_3=w5_4; w5_4=w; 
		
		aSol=actSolF(t_4);
		error=fabs(aSol-w);
		
		cout<<"Step: "<<i<<", Time: "<<t_4<<"s, Function Value: "<<w<<", Actual Solution: "<<aSol<<", Error: "<<error<<endl;
	}	
	
	w=Adams_Bashforth_5(t_4,w5_0,w5_1,w5_2,w5_3,w5_4,h);
		
	t_4=t_4+h;
		
	aSol=actSolF(t_4);
	error=fabs(aSol-w);
		
	cout<<"Step: "<<i<<", Time: "<<t_4<<"s, Function Value: "<<w<<", Actual Solution: "<<aSol<<", Error: "<<error<<endl;
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

//Adams_Bashforth Method of Order 2, 3, 4, 5
double Adams_Bashforth_2(double x, double w0, double w1, double h)
{
	double w;
	
	w=w1+0.5*h*(3*f(x,w1)-f(x-h,w0));
	
	return w;
}
double Adams_Bashforth_3(double x, double w0, double w1, double w2, double h)
{
	double w;
	
	w=w2+h*(23*f(x,w2)-16*f(x-h,w1)+5*f(x-2*h,w0))/12;
	
	return w;
}
double Adams_Bashforth_4(double x, double w0, double w1, double w2, double w3, double h)
{
	double w;
	
	w=w3+h*(55*f(x,w3)-59*f(x-h,w2)+37*f(x-2*h,w1)-9*f(x-3*h,w0))/24;
	
	return w;
}
double Adams_Bashforth_5(double x, double w0, double w1, double w2, double w3, double w4, double h)
{
	double w;
	
	w=w4+h*(1901*f(x,w4)-2774*f(x-h,w3)+2616*f(x-2*h,w2)-1274*f(x-3*h,w1)-251*f(x-4*h,w0))/720;
	
	return w;
}
