/*************************************************************************
	> File Name: 1979.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  3/ 8 14:11:00 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	int n;
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		sum += t;
	}
	sum /= n;
	cout << sum << endl;
	return 0;
}
