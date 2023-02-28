/*************************************************************************
	> File Name: 1134.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 三  3/ 2 15:15:07 2022
 ************************************************************************/

#include<iostream>
#include <iomanip>
using namespace std;
int main ()
{
	double sum = 0;
	double i = 1;
	int t = 1;
	while (1/i>= 1E-6)
	{
		sum += 1.0/i*t;
		t=-t;
		i=i+2;
	}
	sum *= 4;
	cout << fixed << setprecision (6) << sum << endl;
	return 0;
}
