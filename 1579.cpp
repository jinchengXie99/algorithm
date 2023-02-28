/*************************************************************************
	> File Name: 1579.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  3/ 3 23:48:02 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{

	int a,b;
	cin >> a >> b;
	b+=30;
	int sum = 0;
	for(int i = 0; i < a; i++)
	{
		int t;
		cin >> t ;
		if (t<=b) sum++;
	}
	cout << a-sum;
	return 0;
}
