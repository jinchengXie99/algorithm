/*************************************************************************
	> File Name: 1026.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  2/15 21:46:40 2022
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int main ()
{
	vector<int> vec;
	int tmp;
	for (int i = 0; i < 10; i++)
	{
		cin >> tmp;
		vec.push_back(tmp);
	}
	for (int i = 9; i >= 0; i--)cout << vec[i] << " ";
	cout << endl;
	return 0;
}
