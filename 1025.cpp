/*************************************************************************
	> File Name: 1025.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  2/15 18:53:08 2022
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main ()
{
	vector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		int num;
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(),vec.end());
	for (int i = 0; i < 10; i++)
	{
		cout << vec[i] << endl;
	}
	return 0;
}
