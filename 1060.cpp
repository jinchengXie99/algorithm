/*************************************************************************
	> File Name: 1060.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  2/24 21:57:44 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	int i = 10;
	while (i<1000)
	{
		if (i%2==0&&i%3==0&&i%7==0)
		{
			cout << i  << endl;
		}
		i++;
	}
	return 0;
}
