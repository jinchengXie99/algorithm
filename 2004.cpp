/*************************************************************************
	> File Name: 2004.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  3/29 16:31:15 2022
 ************************************************************************/

#include<iostream>
#include <iomanip>
using namespace std;
int main ()
{
	int n = 10;
	double  sum = 0;
	int min = 0;
	while (n--)
	{
		int n;
		cin >> n;
		if (n < 60) min ++;
		sum += n;
	}
	sum /= 10;
	cout << fixed << setprecision(1) << sum << " " << min << endl;
	return 0;
}
