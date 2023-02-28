/*************************************************************************
	> File Name: 1068.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  2/25 16:34:23 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int ctof(int n)
{
	return 32+ (n*9)/5;
}
int main ()
{
	for (int i = -100; i <= 150; i+=5)
	{
		cout << "c=" << i << "->f=" << ctof(i) << endl;
		
	}


	return 0;
}
