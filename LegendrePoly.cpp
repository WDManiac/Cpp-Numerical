/*          
* Copyright (c) 2012, ��̨��ѧ�����ѧԺ          
* All rights reserved.          
* �� �ߣ�  ��ͬ��        
* ������ڣ�2012 �� 11 �� 24 ��          
* �� �� �ţ�v1.0                  
* ����������     
* ���������� �õݹ鷽����n�����õ¶���ʽ��ֵ���� 
* ��������� 
* �����������         
* �㷨��ƣ���          
*/   
  
#include<iostream>       
  
using namespace std;  
  
int main()  
{  
    double p(double,double);  
  
    double s,n,x;  
  
    cout<<"������n��x��ֵ��";  
  
    cin>>n>>x;  
  
    s=p(n,x);  
  
    cout<<"�����ʽ��ֵΪ��"<<s<<endl;  
  
    return 0;  
}  
  
double p(double n,double x)  
{  
    double s;   //  �������������������ͬ��  
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
        s=((2*n-1)*x-p((n-1),x)-(n-1)*p((n-2),x))/n;//�ݹ顣�ϻ�ָ����д����s=((2*n-1)*x*p((n-1),x)-(n-1)*p((n-2),x))/n  ������3  4ʱ�������154  
    }  
  
    return s;  
}  
