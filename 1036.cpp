/*************************************************************************
	> File Name: 1036.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  2/17 21:55:12 2022
 ************************************************************************/

#include<iostream>
using namespace std;
#define swap(a,b) t=a;a=b;b=t;
int main ()
{	
	int a,b;
	int t;
	cin >> a >> b;
	swap(a,b);
	cout << a << " "<< b << endl;
	return 0;
}
