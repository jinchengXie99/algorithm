/*************************************************************************
	> File Name: 1130.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 三  3/ 2 14:18:02 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	string str;
	cin >> str;
	int len = str.length();
	int sum = 0;
	for (int i = 0; i < len; i++ )
	{
		if ((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')) sum++;
	}

	cout << sum << endl;
	return 0;
}
