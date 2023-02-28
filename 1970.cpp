/*************************************************************************
	> File Name: 1970.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  3/ 8 13:57:30 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{

	int n;
	cin >> n;
	int i=1;
	while (n--)
	{
		int a;
		cin >> a;
		i*=a;
		i%=10;
	}
	cout << i << endl;
	return 0;
}
