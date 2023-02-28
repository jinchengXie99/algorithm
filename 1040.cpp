/*************************************************************************
	> File Name: 1040.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  2/18 21:07:59 2022
 ************************************************************************/

#include<iostream>
#include<iomanip>
using namespace std;
int main ()
{
	float t;
	cin >> t;
	for (int i = 1; i < 4; i++)
	{
		for (int j = 0; j < i; j++)
		{

			cout << fixed << setprecision(2)  << setw(6)<< t << " ";
		}
		cout << endl;
	}

	return 0;
}
