/*************************************************************************
	> File Name: 1180.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 六  3/ 5 23:05:25 2022
 ************************************************************************/

#include<iostream>
using namespace std;
void fun(int n)
{
	int sum = 3;
	for (int i = 0; i < n; i++)
	{
		sum = (sum-1)*2;
	}
	cout << sum << endl;
	
}
int main ()
{
	int n;
	cin >> n;
	while (n--)
	{
		int a;
		cin >> a;
		fun(a);
	}
	return 0;
}
