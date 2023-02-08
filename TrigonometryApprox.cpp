#include <iostream>  
#include <cmath>  
#include <iomanip>  
using namespace std;  
double f(double x,double a0,double a1,double a2,double a3,double b1,double b2) //trigonometric approximation 
{  
   return a0/2+a3*cos(3*x)/2+(a1*cos(x)+b1*sin(x))+(a2*cos(2*x)+b2*sin(2*x));  
}  
double act(double x)//actual function
{
   return pow(x,2)*sin(x);
}
int main()  
{
	int i,j,k,n,o,m=4;
	double x[8],y[8],sol[8],a[4],b[2],E;
	double R1,R2,lower=0.0,upper=1.0,step=0.01;
	double compSimp_S4(double l,double u,double step,double a0,double a1,double a2,double a3,double b1,double b2);
	double compSimp_act(double a,double b,double step);
	x[0]=-3.1415926;
	x[1]=-3.1415926*0.75;
	x[2]=-3.1415926*0.5;
	x[3]=-3.1415926*0.25;
	x[4]=0.0;
	x[5]=3.1415926*0.25;
	x[6]=3.1415926*0.5;
	x[7]=3.1415926*0.75;
	
	for(j=0;j<8;j++){    sol[j]=act(x[j]); cout<<x[j]<<"    "<<sol[j]<<endl;
    }
    
    for(k=0;k<4;k++){    a[k]=0.0;
	    for(o=0;o<8;o++){    a[k]=a[k]+(sol[o]*cos((k)*x[o])); cout<<a[k]<<" ";
		}
		a[k]=a[k]/m;
		cout<<"Coefficients a["<<k+1<<"] = "<<a[k]<<endl; 		
	}
	
	for(n=0;n<2;n++){    b[n]=0.0;
	    for(o=0;o<8;o++){    b[n]=b[n]+(sol[o]*sin((n+1)*x[o])); cout<<b[n]<<" ";
		}
		b[n]=b[n]/m;
		cout<<"Coefficients b["<<n+1<<"]"<<b[n]<<endl; 		
	}
	
	cout<<endl;
	cout<<"Thus the approximation would be: S(x) = ("<<a[0]<<")/2+("<<a[2]<<")cos3x+[("<<a[0]<<")cosx+("<<b[0]<<")sinx]+[("<<a[1]<<")cos2x+("<<b[1]<<")sin2x]"<<endl;
	cout<<endl;
		
	for(i=0;i<8;i++){    y[i]=f(x[i],a[0],a[1],a[2],a[3],b[0],b[1]); 
	E=E+pow(y[i]-sol[i],2);
	cout<<"S["<<i<<"]="<<y[i]<<";  actual soution: "<<sol[i]<<";  relative error: "<<fabs((y[i]-sol[i])/sol[i])<<"."<<endl<<endl;
	}
	
	cout<<"Error for this method: "<<E<<endl;
	
	R1=compSimp_S4(lower,upper,step,a[0],a[1],a[2],a[3],b[0],b[1]);
	cout<<"Integration of S4 approximation: "<<R1<<endl;
	
	R2=compSimp_act(lower,upper,step);
	cout<<"Integration of original function: "<<R2<<endl;
	
    return 0;  
}  

//Integration for S4---Composite Simpson Integration 
double compSimp_S4(double l,double u,double step,double a0,double a1,double a2,double a3,double b1,double b2)
{
	double sum,result;
	int i,N;
	
	N=(u-l)/(2.0*step)-1.0;
	//Calculating iteration time
	
	sum=(f(l,a0,a1,a2,a3,b1,b2)+f(u,a0,a1,a2,a3,b1,b2));
	for(i=1.0;i<=N;i++)
	{
		sum=sum+(2.0*f(l+2.0*i*step,a0,a1,a2,a3,b1,b2)+4.0*f(l+(2.0*i-1.0)*step,a0,a1,a2,a3,b1,b2));
		//iteratie to (n/2-1) term
	}
	result=step*(sum+4.0*f(l+(2.0*N+1.0)*step,a0,a1,a2,a3,b1,b2))/3.0;
	//Add on the single n/2 term 
	return result;
}

//Integration for actual function---Composite Simpson Integration 
double compSimp_act(double l,double u,double step)
{
	double sum,result;
	int i,N;
	
	N=(u-l)/(2.0*step)-1.0;
	//Calculating iteration time
	
	sum=(act(l)+act(u));
	for(i=1.0;i<=N;i++)
	{
		sum=sum+(2.0*act(l+2.0*i*step)+4.0*act(l+(2.0*i-1.0)*step));
		//iteratie to (n/2-1) term
	}
	result=step*(sum+4.0*act(l+(2.0*N+1.0)*step))/3.0;
	//Add on the single n/2 term 
	return result;
}
