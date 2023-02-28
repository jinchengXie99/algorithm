/*************************************************************************
	> File Name: 1048.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 六  2/19 16:44:15 2022
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int main ()
{
	int i;
	cin >> i;
	string str;
	cin >> str;
	int n;
	cin >> n;
	str = str.substr(n-1,i-n+1);
	cout << str << endl;
	return 0;
}

