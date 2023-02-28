/*************************************************************************
	> File Name: 2001.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 一  3/28 00:12:07 2022
 ************************************************************************/

#include<iostream>
#include <cmath>
using namespace std;
int main ()
{
	int a, b ,c;
	cin >> a >> b >> c;
	int d , e, f;
	d = min (min(a,b),c);
	f = max (max(a,b),c);
	if (a != d && a != f) e = a;
	else if (b != d && b != f) e = b;
	else e = c;

if (f < e + d && e < f + d && d < f + e && d*d + e*e == f*f) cout << "YES" << endl;
else cout << "NO" << endl;
	return 0;
}
