/*************************************************************************
	> File Name: 1847.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  3/ 3 23:55:46 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	char a;
	int  b = 0;
	while(cin>> a)
	{
		if (a=='*'&&b==0)
		{
			cout << a;

		}
		else if (a!='*') {

cout << a;
b++;
		}
	}

	return 0;
}
