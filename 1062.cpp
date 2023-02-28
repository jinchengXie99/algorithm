/*************************************************************************
	> File Name: 1062.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 一  2/21 23:29:19 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int fun (int a,int b)
{	
	if (a<b){
		int t = a;
		a = b;
		b =t;
	}
	return (a%b==0)?b:fun(b,a%b);
}
int main ()
{
	int a, b;
	cin >> a >> b;
	int c =fun(a,b);
	int d = a*b/c;
	cout << c << endl;
	cout << d << endl;
	return 0;
}
