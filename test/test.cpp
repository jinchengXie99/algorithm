/*************************************************************************
	> File Name: test.cpp
	> Author: Jincheng Xie
	> Mail: chengdiy@foxmail.com
	> Created Time: 一  8/22 23:10:28 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	
	int i = 1000;
	int b = 0;
	for (;i > 0; i--)
	{
		while (i % 2 != 1){
			
			b += i;
			
			i--;
		}
	}

	cout << "hello world" << endl;

	return 0;
}
