/*************************************************************************
	> File Name: 1010.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  2/10 22:21:50 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	
	int x;
	cin >> x;
	if (x <= 100000 && x > 0) x *= 0.1;
	else if (x > 100000 && x <= 200000) x = 10000 + (x - 100000)*0.075;
	else if (x > 200000 && x <= 400000) x = 10000 + 7500 + (x - 200000)*0.05;
	else if (x > 400000 && x <= 600000) x = 10000 + 7500 + 10000 + (x - 400000)*0.03;
	else if (x > 600000 && x <= 1000000) x = 20000 + 7500 +6000+ (x - 600000)*0.015;
	else x = 27500 + 6000 + (x - 1000000)*0.01+6000;
	 cout << x << endl;
	return 0;

}
