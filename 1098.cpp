/*************************************************************************
	> File Name: 1098.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 日  2/27 18:02:18 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	int a[10];
	for (int i = 0; i < 10; i++)
	{
			cin >> a[i];
	}
	int b;
	cin >> b;
	b+=30;
	int sum = 0;
	for (int i = 0; i < 10 ; i++)
	{
		if (a[i]<=b)sum++;
	}
	cout << sum << endl;
}
