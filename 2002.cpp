/*************************************************************************
	> File Name: 2002.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 一  3/28 00:23:22 2022
 ************************************************************************/

#include<iostream>
#include <string>
using namespace std;
int main ()
{

	string str;
	cin >> str;
	int len = str.size();
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		
		if (str[i] >= '0' && str[i] <= '9') sum ++;

	}
	cout << sum << endl;
	return 0;
}
