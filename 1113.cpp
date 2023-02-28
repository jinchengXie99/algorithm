/*************************************************************************
	> File Name: 1113.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 六  3/ 5 22:33:28 2022
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int main ()
{
	string str;
	getline(cin,str);
	int len = str.size();
	string ss;
	for (int i = 0; i < len; i++)
	{
		if (str[i]>='a'&&str[i]<='z')ss+=str[i];

		if (str[i]>='A'&&str[i]<='Z')ss+=str[i];
	}
	cout << ss << endl;
	return 0;
}
