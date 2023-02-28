/*************************************************************************
	> File Name: 1139.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 日  2/27 21:34:41 2022
 ************************************************************************/

#include<cmath>
#include<iostream>
using namespace std;
bool ispreme(int n)
{
	if (n < 4) return n>1;
	for (int i = 2; i<= sqrt(n);i++)
	{
		if (n%i==0) return false;
	}
	return true;
}
int main ()
{
	int n;
	cin>> n;
	for (int i = 2; i <= n; i++ )	
	{
		if (ispreme(i))cout << i <<" ";
	}
	return 0;
}
