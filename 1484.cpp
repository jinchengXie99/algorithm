/*************************************************************************
  > File Name: 1484.cpp
  > Author: Jincheng Xie
  > Mail: chengdiy@foxmail.com
  > Created Time: 五  5/ 6 11:36:32 2022
 ************************************************************************/

#include<iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main ()
{
	double a, b,c;
	cin >> a >> b >> c;
	double x1 =( -b + sqrt(b*b-4*a*c) ) / (2*a);
	double x2 =( -b - sqrt(b*b-4*a*c) ) / (2*a);	
	if (x1 != x2) cout << fixed << setprecision(2) << x1 << " " << x2 << endl;
	else cout << fixed << setprecision(2)<< x1<< endl;
}
