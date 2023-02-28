/*************************************************************************
	> File Name: 2211.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  2/22 11:16:06 2022
 ************************************************************************/

#include<iostream>
using namespace std;
void swap(int &a, int &b)
{	
	int t = b;
	b = a;
	a = t;
}
int main ()
{
	int a, b;
	cin >> a >> b;
	swap(a, b);
	cout << a <<" "<< b << endl;
	return 0;
}
