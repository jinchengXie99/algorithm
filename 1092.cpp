/*************************************************************************
	> File Name: 1092.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 三  3/23 17:38:25 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		int sum = 0;
		int t;
		while (x--)
		{
			cin >> t;
			sum += t;
		}
		cout << sum  << endl;
		cout << endl;
	}
	return 0;
}
