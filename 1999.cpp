/*************************************************************************
	> File Name: 1999.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  3/18 22:01:43 2022
 ************************************************************************/

#include<iostream>
#include <string>
#include <algorithm>
using namespace std;
int main () {
	string str;
	cin >> str;
	string b = str;
	reverse(b.begin(),b.end());
	if (b == str) cout << "YES" << endl;
	else  cout << "NO" << endl;
	return 0;
}
