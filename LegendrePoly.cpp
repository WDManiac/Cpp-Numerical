/*          
* Copyright (c) 2012, 烟台大学计算机学院          
* All rights reserved.          
* 作 者：  刘同宾        
* 完成日期：2012 年 11 月 24 日          
* 版 本 号：v1.0                  
* 输入描述：     
* 问题描述： 用递归方法求n阶勒让德多项式的值。。 
* 程序输出： 
* 问题分析：略         
* 算法设计：略          
*/   
  
#include<iostream>       
  
using namespace std;  
  
int main()  
{  
    double p(double,double);  
  
    double s,n,x;  
  
    cout<<"请输入n与x的值：";  
  
    cin>>n>>x;  
  
    s=p(n,x);  
  
    cout<<"则多项式的值为："<<s<<endl;  
  
    return 0;  
}  
  
double p(double n,double x)  
{  
    double s;   //  函数名与变量名不能相同。  
    if(n==0)  
    {  
        s=1;  
    }  
    else if(n==1)  
    {  
        s=x;  
    }  
    else   
    {  
        s=((2*n-1)*x-p((n-1),x)-(n-1)*p((n-2),x))/n;//递归。上机指导上写的是s=((2*n-1)*x*p((n-1),x)-(n-1)*p((n-2),x))/n  当输入3  4时，结果是154  
    }  
  
    return s;  
}  
