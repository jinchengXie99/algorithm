/*************************************************************************
	> File Name: 1088.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 三  3/23 17:10:15 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	int n;
	int t;
	while (cin >> n && n != 0)
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> t;
			sum += t;
		}
		cout << sum << endl;
	}
	return 0;
}
