/*************************************************************************
	> File Name: 1392.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 日  3/ 6 14:07:53 2022
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string add(string a,string b)
{
	int lena = a.size() - 1;
	int lenb = b.size() - 1;
	int sum = 0, flag = 0;
	string str;
	while (lena >= 0 && lenb >= 0)
	{
		sum = ( a[lena--]-'0') + (b[lenb--]-'0') + flag;
		flag = sum/10;
		sum %= 10;
		str += char(sum +'0');
	}
	while (lena >= 0)
	{
		sum = (a[lena--]-'0') + flag;
		flag = sum /10;
		sum %= 10;
		str += char(sum + '0');
	}
	while (lenb >= 0)
	{
		sum = (b[lenb--]-'0')+flag;
		flag = sum /10;
		sum %= 10;
		str += char(sum + '0');
	}
	if (flag) str += char(flag+'0');
	reverse(str.begin(),str.end());
	return str;
}
int main ()
{
	string a,b;
	while (cin >> a >> b)
	{
		cout << add(a,b)<< endl;
	}

	return 0;
}
