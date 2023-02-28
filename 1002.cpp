/*************************************************************************
	> File Name: 1002.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  2/ 8 21:03:27 2022
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;
int main ()
{
	int a,b,c;
	cin >> a >> b >> c;
	int x=max(a,b);
	x=max(c,x);
	cout<< x <<endl; 

	return 0;
}
