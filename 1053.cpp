/*************************************************************************
	> File Name: 1053.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 一  2/21 22:34:25 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	int a[10];
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		cin >> a[i];
		sum+=a[i];
	}
	float avr = sum/10;
	int cunt = 0;
	for (int i = 0; i < 10; i++)
	{
		if (a[i] > avr)cunt++;
	}
	cout << cunt << endl;

}
