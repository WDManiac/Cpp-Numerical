#include <iostream>
#include <cmath>

using namespace std;

//Runge-Kutta Method for IVP
int main()
{
	double a, b, h, *w1, *w2, t, aSol, error, pt1=1000, pt2=500;
	double f1(double x, double yi_1, double yi_2);
	double f2(double x, double yi_1, double yi_2);
	double RK4(double x, double *w1, double *w2, double h);
	int N,i;
	
	w1=&pt1; w2=&pt2;
	
	cout<<"Input the lower and upper bounds of the problem:"<<endl; 
	cin>>a>>b;
	cout<<"Input the width of time interval applied:"<<endl;
	cin>>h;
	
	N=(b-a)/h;
	
	t=a;
	
	for (i=1;i<N;i++)
	{
		RK4(t,&pt1,&pt2,h);
		
		t=t+h;
				
		cout<<"Step: "<<i<<", Time: "<<t<<"s, Function Value: "<<*w1<<", "<<*w2<<endl;
	}	
	
	RK4(t,&pt1,&pt2,h);
	
	t=t+h;	
			
	cout<<"Step: "<<i<<", Time: "<<t<<"s, Function Value: "<<*w1<<", "<<*w2<<endl;
		
	return 0;
}
///////////////////////////////////////////////////////

//Setting up differential equations 
double f1(double x, double yi_1, double yi_2)
{
	double dy1;
	
	dy1=3*yi_1-0.002*yi_1*yi_2;
	
	return dy1;
}
///////////////////////////////////////////////////////
double f2(double x, double yi_1, double yi_2)
{
	double dy2;
	
	dy2=0.0006*yi_1*yi_2-0.5*yi_2;
	
	return dy2;
}
///////////////////////////////////////////////////////

//Runge-Kutta Method of Order 4
void RK4(double x, double *w1, double *w2, double h)
{
	double k11, k12, k21, k22, k31, k32, k41, k42;
	
	k11=h*f1(x,*w1,*w2);
	k12=h*f2(x,*w1,*w2);
	
	k21=h*f1(x+0.5*h,*w1+0.5*k11,*w2+0.5*k12);
	k22=h*f2(x+0.5*h,*w1+0.5*k11,*w2+0.5*k12);
	
	k31=h*f1(x+0.5*h,*w1+0.5*k21,*w2+0.5*k22);
	k32=h*f2(x+0.5*h,*w1+0.5*k21,*w2+0.5*k22);
	
	k41=h*f1(x+h,*w1+k31,*w2+k32);
	k42=h*f2(x+h,*w1+k31,*w2+k32);
	
	*w1=*w1+(k11+2*k21+2*k31+k41)/6;
	*w2=*w2+(k12+2*k22+2*k32+k42)/6;
}
