/*************************************************************************
	> File Name: 1131.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 三  3/ 2 14:23:52 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	int n;
	cin >> n;
	int a = 1;
	int b = 1;
	for (int i = 0; i < n; i++ )
	{
		if (i == 0 || i ==1) cout << a << " ";
		else {
			cout << a+b << " " ;
			int t = a;
			a = b;
			b = a + t;
		}

	}
	return 0;

}
