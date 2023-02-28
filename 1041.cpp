/*************************************************************************
	> File Name: 1041.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  2/18 21:17:42 2022
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
#define defMax(a,b,c)  __typeof(a) x = max (a,b); b = max(x,c);

using namespace std;
int main ()
{
	double a,b,c;
	cin >> a >> b >> c;
	defMax(a,b,c);
	cout << fixed << setprecision(3);
	cout <<b << endl;
	cout <<b << endl;
	return 0;
}
