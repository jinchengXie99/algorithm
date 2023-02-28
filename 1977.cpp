/*************************************************************************
	> File Name: 1977.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  3/ 8 14:04:04 2022
 ************************************************************************/

#include<iostream>
#include <algorithm>

using namespace std;
int main ()
{	
	int a[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> a[i];
	}
	sort(a,a+3);
	cout << a[1] <<endl;
	return 0;
}
