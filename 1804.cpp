/*************************************************************************
	> File Name: 1804.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 日  3/ 6 16:37:51 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{

	int a,b;
	char c;
	cin >> a >> b >> c;
	switch(c){
		case '+': cout << a + b << endl;break;
		case '-': cout << a - b << endl;break;
		case '*': cout << a * b << endl;break;
		case '/': cout << a / b << endl;break;
		case '%': cout << a % b << endl;break;
		default:break;
	}
	return 0;
}
