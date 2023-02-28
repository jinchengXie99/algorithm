/*************************************************************************
	> File Name: 2080.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  3/ 8 16:42:40 2022
 ************************************************************************/


#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;
int fun(string str)
{
	int a = str.length();
	int sum = 0;
	for (int i = a-1; i >= 0 ; i--)
	{
		if (str[i]>='0'||str[i]<='9')sum += int(str[i]-'0')*pow(16,a-i-1);
		else sum +=  (int (str[i] - 'A') + 10)*pow(16,a-i-1) ;
	}
	return sum;
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;
		printf ("%o\n",fun(str));
	}
	return 0;
}
