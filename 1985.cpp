/*************************************************************************
	> File Name: 1985.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  3/18 21:27:12 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	int x;
	cin >> x;
	if (x < 3)	x = 2*x;
	else if (x >= 3 && x < 20) x = 2*x + 1;
	else if (x >= 20 ) x = 3*x - 1;
	cout << x << endl;

	return 0;
}
