/*************************************************************************
	> File Name: 1988.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  3/18 21:45:09 2022
 ************************************************************************/

#include<iostream>
#include <iomanip>
using namespace std;
int main ()
{
	int n;
	cin >> n;
	n -= 2;
    double sum = 30.0, t = 30.0;
	while (n--)
	{
		t = t * 1.05;
		sum = sum + t;
	}
	cout << fixed << setprecision(1)<< sum << endl; 
	return 0;
}
