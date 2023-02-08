#include<iostream>
#include<cmath>

using namespace std;
double Newton(double err);
double UDF(double err);
void Newton_UDF_Test();

int main()
{	
	Newton_UDF_Test();
	return 0;
}
//Test function
void Newton_UDF_Test()
{
	double err,r1,r2;
	
	cout<<"Input the error bound for the solution"<<endl;
	cin>>err;
	r1=Newton(err);
	cout<<"Solution using Newton method is:"<<r1<<endl; 
	
	r2=UDF(err);
	cout<<"Solution using UDF accelerated method is:"<<r2<<endl; 
}

//Newton method function
double Newton(double err)
{
	double F(double x);
	double dF(double x);
	double p0=0.0;//stand for initial p0=0 and pn
	double p1;//stand for p1 and p(n+1)
	double buffer=-100;//buffer for p in last step
	int i=0;
	
	while(fabs(p0-buffer)>err)
	{
		p1=p0-F(p0)/dF(p0);//Newton iteration process
		buffer=p0;//store last p in buffer
		p0=p1;//give new value to p0 for next iteration
		i++;
	}
	cout<<"Total iteration number:"<<i<<", function value:"<<F(p0)<<endl;
	return p0;
}

//User defined function
double UDF(double err)
{
	double F(double x);
	double dF(double x);
	double ddF(double x);
	double p0=0.0;//stand for initial p0=0 and pn
	double p1;//stand for p1 and p(n+1)
	double buffer=-100;//buffer for p in last step
	int i=0;
	
	while(fabs(p0-buffer)>err)
	{
		p1=p0-F(p0)*dF(p0)/(pow(dF(p0),2)-F(p0)*ddF(p0));//Newton iteration process
		buffer=p0;//store last p in buffer
		p0=p1;//give new value to p0 for next iteration
		i++;
	}
	cout<<"Total iteration number:"<<i<<", function value:"<<F(p0)<<endl;
	return p0;
}

//define function whose zero is to be found
double F(double x)
{
	double F;
	
	F=pow(x,2)-2*x*exp(-x)+exp(-2*x);
	
	return F;
}
//define 1st order derivative of the function
double dF(double x)
{
	double dF;
	
	dF=2*x-2*exp(-x)+2*x*exp(-2*x)-2*exp(-2*x);
	
	return dF;
}
//define 2nd order derivative of the function
double ddF(double x)
{
	double ddF;
	
	ddF=2+2*exp(-x)+2*exp(-2*x)-4*x*exp(-2*x)+2*exp(-2*x);
	
	return ddF;
}
