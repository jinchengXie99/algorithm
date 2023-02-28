/*************************************************************************
	> File Name: 1093.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 六  2/26 15:18:54 2022
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main ()
{
	string str;
	getline (cin,str);
	reverse(str.begin(),str.end());
	cout << str << endl;
	return 0;
}
