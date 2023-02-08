#include<iostream>
#include<cmath>

using namespace std;
double Newton(double err);
double Aitken(double err);
void Newton_Aitken_Test();

int main()
{	
	Newton_Aitken_Test();
	return 0;
}
//Test function
void Newton_Aitken_Test()
{
	double err,r1,r2;
	
	cout<<"Input the error bound for the solution"<<endl;
	cin>>err;
	r1=Newton(err);
	cout<<"Solution using Newton method is:"<<r1<<endl; 
	
	r2=Aitken(err);
	cout<<"Solution using Aitken accelerated method is:"<<r2<<endl; 
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

double Aitken(double err)
{
	double Aitken_S(double x);
	double F(double x);
	double p0=0.0;
	double p1;
	double p2;
	double q=0.0;
	int n;
	
	p1=Aitken_S(p0);
	p2=Aitken_S(p1);
	
	double buffer=-100.0;
	
	while(fabs(q-buffer)>err)
	{
		n++;
		buffer=q;		
		q=p0-pow(p1-p0,2)/(p2-2*p1+p0);
		
		p0=p1;
		p1=p2;
		p2=Aitken_S(p2);
	}
	cout<<"Total iteration number:"<<n<<", function value:"<<F(p0)<<endl;
	return q;
}

double Aitken_S(double x)
{
	double G;
	double F(double x);
	double dF(double x);	
	
	G=x-F(x)/dF(x);
	
	return G;
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
	
	dF=2*x-2*exp(-x)+2*x*exp(-x)-exp(-2*x);
	
	return dF;
}
