/*************************************************************************
	> File Name: 1099.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 日  2/27 19:37:03 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int a[10005];
int main ()
{
	int m,n;
	cin >> m >>n;
	for (int i = 0; i < n; i++)
	{
		int l,r;
		cin >> l >>r;
		a[l]++;
		a[r]--;
	}
	int sum = 0;
	int flag = 0;
	for (int i = 0; i <=  m; i++)
	{
		
		flag+=a[i];
		if (flag==0&&a[i]==0)
		{
			sum++;
		}
	}
	cout << sum <<endl;
	return 0;
}
