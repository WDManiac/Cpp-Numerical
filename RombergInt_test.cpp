#include<iostream>
#include<cmath>

using namespace std;

#define f(x) (pow(x,1.0/3))  //Define function
#define epsilon 0.0001  //Accuracy requirement
#define MAXREPT  10   //Maximum iteration time in case requirement could be hardly met

int main()
{
    double Romberg(double a, double b);
	double a,b;
    cout<<"Please input lower and upper bound for Romberg integration a,b:"<<endl;
    cin>>a>>b;

    cout<<"Result:"<<Romberg(a, b)<<endl;

    return 0;
}

double Romberg(double a, double b)
{ //aa,bb upper and lower bound
    int m, n;//m controls iteration time, while n decide interval number for composite Trapezoidal integration: n=2^m
    double h, x;
    double s, q;
    double ep; 
    double *y = new double[MAXREPT];
    
    double p;

    //Initialize
    h = b - a;
    y[0] = h*(f(a) + f(b))/2.0;
    m = 1;
    n = 1;
    ep = epsilon + 1.0;

    //Iteration start
    while ((ep >= epsilon) && (m < MAXREPT))
    {
        
        p = 0.0;
        for (int i=0; i<n; i++)
        {
            x = a + (i+0.5)*h;
            p = p + f(x);
        }
        p = (y[0] + h*p)/2.0;
        
        s = 1.0;
        for (int k=1; k<=m; k++)
        {
            s = 4.0*s;
            q = (s*p - y[k-1])/(s - 1.0);
            y[k-1] = p;
            p = q;
        }

        ep = fabs(q - y[m-1]);
        m = m + 1;
        y[m-1] = q;
        n = n + n; h = h/2.0;
    }

    return (q);
}


