/*************************************************************************
	> File Name: 1034.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  2/17 15:18:00 2022
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int main ()
{
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		if (i != str.size()-1)cout<< str[i] << " ";
		else cout <<  str[i] << endl;
	}
	return 0;
}
