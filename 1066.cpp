/*************************************************************************
	> File Name: 1066.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  2/25 13:15:17 2022
 ************************************************************************/

#include<iomanip>
#include<iostream>
using namespace std;
double fact(double  n)
{	double s=n;
	for (double i = n-1; i > 0;i--)
	{
		s*=i;
	}
	return s;
}
double mypow(double x,double n)
{
	double r = x;
	for (double   i = 0; i < n -1; i++)
	{
		r *= x;
	}
	return r;
	
}
int main ()
{
	double sum = 0;
	double x ;
	double n;
	cin >> x >> n;
	 for (int  i = 1; i <=int(n); i++)
	 {
	if (i%2==1)	sum +=  mypow(x,n)/fact(n);
	else	sum -=  mypow(x,n)/fact(n);
	 }
	cout << fixed << setprecision(4) << sum ;
	return 0;
}
