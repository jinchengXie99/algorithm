/*************************************************************************
	> File Name: 1955.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  3/ 8 13:52:49 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	int a,c;
	float b;
	cin >> a >> b >> c;
	a = a*10000;
	int sum = a/c + (a)*b;
	cout << sum << endl;
	return 0;
}
