/*************************************************************************
	> File Name: 1470.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 一  2/28 09:46:57 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	
	int t;
	cin >> t;
	int h,m,s;
	h = t / 3600;
	int a = t%3600;
	m = a/60;
	s=t%60;
	cout << h << ":" << m << ":" <<s <<endl;
	return 0;
}
