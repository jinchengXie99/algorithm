/*************************************************************************
	> File Name: 1039.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  2/18 20:48:38 2022
 ************************************************************************/

#include<iostream>
using namespace std;
#define LEAP_YEAR(y) (y%4==0&&y%100!=0)||y%400==0
int main ()
{

	int a;
	cin >> a;
	if (LEAP_YEAR(a))cout << "L" << endl;
	else cout << "N" << endl;
	return 0;
}
