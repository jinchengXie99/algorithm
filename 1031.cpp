/*************************************************************************
	> File Name: 1031.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  2/17 14:38:39 2022
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int main ()
{
	string str;
	cin >> str;
	for(int i = 0; i < str.length()/2 ; i++)
	{
		char t = str[i];
		str[i] = str[str.length() - 1 - i];
		str[str.length() - 1 - i] = t;
	}
		cout << str << endl;
	return 0;
}
