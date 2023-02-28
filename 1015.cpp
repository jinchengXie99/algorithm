/*************************************************************************
	> File Name: 1015.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  2/11 19:53:09 2022
 ************************************************************************/

#include<iostream>
#include<iomanip>
using namespace std;
int main ()
{
	
	double a,b,c;
	double sum;
	cin >> a >> b >> c;
	for (int i = 1;i <= a;i++)
	{
		sum += i;
	}
	for (int i=1; i <= b; i++)
	{
		sum+=i*i;
	}
	for (double i = 1; i <= c; i++)
	{
		sum+=1/i;
	}

	cout << fixed << setprecision(2) << sum << endl;

	return 0;

}
