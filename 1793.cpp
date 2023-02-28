/*************************************************************************
	> File Name: 1793.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  2/22 10:36:17 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{	
	int n;
	cin >> n;
	long long sum = 0;
	long long a = 1;
	for (int i = 0; i < n; i++)
	{
		sum += a;
		a = 2*a + 1;
	
	}
	cout << sum << endl;
	return 0;
}
