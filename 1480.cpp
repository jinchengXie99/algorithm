/*************************************************************************
	> File Name: 1480.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 一  2/28 10:36:44 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{

	int a,b;
	cin >> a>> b;
	char f;
	cin >>f;
	switch(f){
	case '+' : cout << a+b << endl;break;
	case '-' : cout << a-b << endl;break;
	case '*' : cout << a*b << endl;break;
	case '/' : cout << a/b << endl;break;
	case '%' : cout << a%b << endl;break;
	default: cout << "err" <<endl;	
	}
}
