/*************************************************************************
	> File Name: 1135.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 三  3/ 2 14:38:06 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	long long a,n;
	long long sum = 0;
	cin >> a >> n;
	while (n--)
	{
		sum += a;
		long long t = a;
		a *= 10;
		a += t;
	}
	cout << sum << endl;


	return 0;
}
