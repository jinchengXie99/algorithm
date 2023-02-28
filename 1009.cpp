/*************************************************************************
	> File Name: 1009.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  2/10 21:44:57 2022
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int main ()
{
	string str;
	cin>>str;
	int len = str.length();
	cout << len<<endl;
	for(int i = 0; i < len; i++ )
	{
		if(i != len - 1)cout << str[i]<<" ";
		else cout << str[i];
	}
		cout << endl;
	for(int i = len-1; i>=0 ;i--)
	{
		cout<< str[i];
	
	}
	cout << endl;
	return 0;
}
