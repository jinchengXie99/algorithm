/*************************************************************************
	> File Name: 1866.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  3/ 4 17:44:47 2022
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <string>
using namespace std;
int main ()
{
	string str;
	while (cin >> str)
	{
		reverse( str.begin(),str.end());
		cout << str <<endl;
	}

	return 0;
}
