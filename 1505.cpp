/*************************************************************************
	> File Name: 1505.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  3/ 3 23:32:00 2022
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int main ()
{
	string str;
	getline(cin,str);
	int len = str.size();
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i]==' ') sum++;
	}
	cout << sum+1 ;

	return 0;
}
