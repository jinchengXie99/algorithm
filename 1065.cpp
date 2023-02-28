/*************************************************************************
	> File Name: 1065.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  2/25 12:57:46 2022
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
int main (){
	
	int n = 10;
	int a[10];
	int j = 0;
	for (int i = 0; i < 10; i++)
	{
	cin >> a[i];
	if (abs(a[j])>abs(a[i]))j=i;//绝对值最小的  注意看题
	}
	int  t = a[j];
	a[j] = a[9];
	a[9] = t;
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}cout << endl;
	return 0;
}
