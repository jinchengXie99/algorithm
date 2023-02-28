/*************************************************************************
	> File Name: 1020.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 一  2/14 22:29:04 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{

	int N;
	cin >> N;
	int sum = 1;
	for (int i = 1; i < N; i++)
	{
		sum = (sum + 1)*2;
	}
	cout << sum << endl;
	return 0;
}
