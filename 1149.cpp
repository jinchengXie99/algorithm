/*************************************************************************
	> File Name: 1149.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 日  2/27 21:30:46 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	int n;
	cin >> n;
	int sum =0;
	for (int i = 1; i <=n; i++)
	{
	if(i%2!=0)sum +=i;
	}
	cout << sum <<endl;
	return 0;
}
