/*************************************************************************
	> File Name: 1042.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  2/17 22:07:50 2022
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int main ()
{
	string str;
	getline(cin,str);
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 'a' && str[i] < 'z'){
			str[i]++;
		}else if (str[i] == 'z')str[i] = 'a';
	}
	cout << str << endl;

	return 0;
}
