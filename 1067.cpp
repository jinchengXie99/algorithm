/*************************************************************************
	> File Name: 1067.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  2/25 16:55:03 2022
 ************************************************************************/

#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;
int main ()
{	
	double	x;
	cin >> x;
	cout << fixed << setprecision(2);
	if (x < 0)cout<< (-x) <<endl;
	else if (x >= 0 && x < 2)cout << sqrt(x+1) << endl;
	else if (x >= 2 && x < 4)cout << pow(x+2,5) << endl;
	else cout << 2*x+5 << endl;
	return 0;
}
