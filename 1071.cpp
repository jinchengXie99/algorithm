/*************************************************************************
	> File Name: 1071.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  3/ 1 11:19:13 2022
 ************************************************************************/
#include <iomanip>
#include<iostream>
using namespace std;
double fun(int n)
{
	double s=n;
	for (int i = n-1; i > 0; i--)
	{
		s*=i;
	}
	return s;
}
int main ()
{

	int n;
	cin >> n;

	double sum = 0.0;
	for (int i = 1; i <= n; i++)
	{
		sum += 1.0/fun(i);
	}
	cout << "sum=";
	cout<< fixed << setprecision(5) << sum << endl;
	return 0;
}
