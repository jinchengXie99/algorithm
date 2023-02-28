/*************************************************************************
	> File Name: 1016.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  2/11 20:04:13 2022
 ************************************************************************/
#include<iostream>
using namespace std;
int main ()
{

		int a,b,c;
	for (int i = 100; i < 1000; i++)
	{
		int d = i;
		a = d/100;
		b = (d%100)/10;
		c = d%10;

		if (a*a*a + b*b*b + c*c*c == i)
			cout << i << " ";
	}
	return 0;
}
