/*************************************************************************
	> File Name: 1089.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 三  3/23 17:13:36 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	int n;
	cin >> n;
	while (n--)
	{
		int a;
		cin >> a;
		int sum = 0;
		int t;
		while (a--)
		{
			cin >> t;
			sum += t;
		}
		cout << sum  << endl;
	}


}
