/*************************************************************************
	> File Name: 1980.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  3/ 8 14:14:57 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	int a;
	cin >> a;
	if (a<=15) cout << a*2 << endl;
	else cout << 15*2 + (a-15)*3 << endl;
	return 0;
}
