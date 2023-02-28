/*************************************************************************
	> File Name: 1056.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 一  2/21 23:18:59 2022
 ************************************************************************/

#include<iostream>
#include<iomanip>
using namespace std;
int main ()
{

	double  t,c;
	cin >> t ;
	c = (t - 32)*5/9;
	cout <<fixed << setprecision(2)<< c << endl;
	return 0;
}
