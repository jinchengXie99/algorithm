/*************************************************************************
	> File Name: 1636.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  3/ 4 12:15:59 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	int a,b,c;
	cin >> a >> b >> c;
	for (int i = a; i <= b; i++)
	{
		if (i%c == 0)cout << i <<" ";

	}

	return 0;
}
