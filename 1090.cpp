/*************************************************************************
	> File Name: 1090.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 三  3/23 17:16:32 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{

	int n;
	while (cin >> n )
	{
		int sum = 0;
		int t;
		for (int i = 0; i < n; i++)
		{
			cin >> t;
			sum += t;

		}
		cout << sum << endl;
	}
	return 0;
}
