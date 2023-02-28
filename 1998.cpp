/*************************************************************************
	> File Name: 1998.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  3/29 12:05:31 2022
 ************************************************************************/

#include<iostream>
#include <iomanip>
#include <string>
using namespace std;
int main ()
{

	int n;
	cin >> n;
	double sum = 0;
	if (n <= 100000) sum += n/10;
	else if (n <= 400000) sum += 10000 + (n - 100000)/20;
	else if (n > 400000)sum += 10000 + 15000 + (n - 400000.0) * (0.03);
	cout << fixed << setprecision (1) << sum << endl;
	return 0;
}
