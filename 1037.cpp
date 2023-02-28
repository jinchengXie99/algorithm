/*************************************************************************
	> File Name: 1037.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  2/17 22:00:15 2022
 ************************************************************************/

#include<iostream>
using namespace std;
#define fun(a,b)  a%b;
int main  ()
{
	int a, b;
	cin >> a >> b;
	int x = fun(a,b);
	cout<< x << endl;
	return 0;
}
