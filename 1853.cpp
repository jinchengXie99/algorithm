/*************************************************************************
	> File Name: 1853.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  3/ 4 15:17:07 2022
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;
void print(int a) {cout << a << " ";}
int main ()
{
	int n;
	int a[200];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
	cin >> a[i];
	}
	sort(a,a+n);
	for_each(a,a+n,print);
	return 0;
}
