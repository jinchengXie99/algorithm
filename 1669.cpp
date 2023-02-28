/*************************************************************************
	> File Name: 1669.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  3/ 8 11:33:43 2022
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
#define pi acos(-1)
int main()
{
	double r;
	cin >> r;
	double s;
	s = pi*r*r;
	cout << fixed << setprecision(2) << s <<endl;
	return 0;
}
