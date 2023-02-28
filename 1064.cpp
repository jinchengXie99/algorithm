/*************************************************************************
	> File Name: 1064.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  2/25 12:47:02 2022
 ************************************************************************/

#include<iostream>
#include <cstdio>
using namespace std;
int main ()
{
	double n = 1.0;
	double sum = 0.0;
	for (int i = 1; i < 31; i++)
	{
		n = n*i;
		sum+=n;
	}
	printf("%.2e\n",sum);
	return 0;
}
