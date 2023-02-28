/*************************************************************************
	> File Name: 1058.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  2/24 21:47:58 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	int n;
	cin >> n;
	int sum = 0;
	int t;
	while(n--)
	{
		cin >> t;
	if (t%2==0)	sum+=t;
	}
	cout << sum <<endl;
	return 0;
}
