/*************************************************************************
	> File Name: 1477.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 一  2/28 10:21:27 2022
 ************************************************************************/

#include<iostream>
#include<string>
#include <iomanip>
using namespace std;
void Getreal(float &n)
{
	cout << "please input a number:" << endl;
	cin >> n;
	return ;
}
void Getstring(string &str)
{
	cout <<"please input a string:"<< endl;
	cin >> str;
	return ;
}
int main()
{
	float n;
	string str;
	Getreal(n);
	Getstring(str);
	cout <<fixed<< setprecision(2)<< n<< endl;
	cout << str << endl;

	return 0;
}
