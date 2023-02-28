/*************************************************************************
	> File Name: 1137.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 三  3/ 2 15:07:20 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int fun (int n)
{
	if (n == 1) return 10;
	return fun(n-1)+2;

}
int main ()
{
	
	int n;
	cin >> n;
	cout << fun(n);
	return 0;
}
