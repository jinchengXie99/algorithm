/*************************************************************************
	> File Name: 1118.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 三  3/ 9 11:43:58 2022
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int main()
{
	int sum = 0;
	int len = 0;
	string str;
	while(cin >> str)
	{
		len = str.size();
		for (int i = 0; i < len; i++)
		{
			sum += int ( str[i]-'0');
		}
		cout << sum << endl;
		sum = 0;
		len = 0;

	}
	return 0;
}
