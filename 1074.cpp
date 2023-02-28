/*************************************************************************
	> File Name: 1074.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 日  2/27 15:11:04 2022
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int main ()
{
	string a;
	while (cin >> a && a !="0")
	{
		int len = a.length();
		int x = 0;
	for (int i = 0; i < len; i++)
	{
		x = x*10 +(a[i]-'0');
		x%=17;
	}
	if (x!=0)cout << '0' << endl;
	else cout << '1' << endl;
	}
	return 0;
}
