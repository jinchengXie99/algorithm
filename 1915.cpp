/*************************************************************************
	> File Name: 1915.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  3/ 4 15:42:01 2022
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main ()
{
	vector<int> vec;
	for (int i = 0; i < 3; i++)
	{
		int a; 
		cin >> a;
		vec.push_back(a);
	}
	sort(vec.begin(),vec.end(),greater<int>());
	for(int i = 0; i < 3; i++)
	{
	cout << vec[i] << " ";

	}
	return 0;
}
