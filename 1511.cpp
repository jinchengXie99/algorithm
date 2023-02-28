/*************************************************************************
	> File Name: 1511.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  3/ 3 23:37:29 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{

	int n;
	cin >> n;
	int a = 0;
	int b = 0;
	while(n--)
	{
		int t;
		cin >> t ;
		a+=t;
		cin >> t ;
		b+=t;
	}
	cout << a << "+" << b << "i" << endl;
	return 0;

}
