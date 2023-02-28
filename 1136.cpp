/*************************************************************************
	> File Name: 1136.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 三  3/ 2 15:01:00 2022
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

int main ()
{
	for (int i = 1000; i < 10000; i++)
		{
				int a = i%100;
				int b = i/100;
				if ((a+b)*(a+b)==i)cout << i << " ";
		}
}
