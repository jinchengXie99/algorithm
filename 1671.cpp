/*************************************************************************
	> File Name: 1671.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  3/ 8 12:07:01 2022
 ************************************************************************/

#include<iostream>
#include<iomanip>
using namespace std;
int main ()
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << j << "*" << i << "=";
			cout << setw(2) << left << i*j;
			cout << " ";
		}
		cout << endl;
	}

	return 0;
}
