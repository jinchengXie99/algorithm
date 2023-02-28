/*************************************************************************
	> File Name: 1011.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  2/11 15:36:47 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int g(int a,int b);
int main ()
{
	int a,b;
	cin >> a >> b;
	if (a<b){
	int t=a;
	a=b;
	b=t;
	}
	int t = g(a,b);
	cout << t << " "<< a*b/t <<endl;
	return 0;
}

int g(int a, int b){
	return b == 0 ? a : g(b,a%b);
}
