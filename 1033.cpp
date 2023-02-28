/*************************************************************************
	> File Name: 1033.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  2/17 15:07:12 2022
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
string fun(string &str){
	string str2;
	for (int i = 0; i < str.size();i++)
	{
		if (str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
		{
			str2+=str[i];
		}
	}
	return str2;
}
int main ()
{
	string str;
	getline(cin,str);
	cout << fun(str) << endl;
	return 0;
}
