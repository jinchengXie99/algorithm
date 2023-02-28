/*************************************************************************
	> File Name: 1133.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 三  3/ 2 14:04:18 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	long long n;
	long long sum = 0;
	long long  a = 1;
	cin >> n;
	for (int i= 1; i <= n; i++)
	{
		a *= i;
		sum += a;
	}
	cout << sum << endl; 
return 0;
}
