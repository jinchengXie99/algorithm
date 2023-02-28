/*************************************************************************
	> File Name: 1042.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  2/17 22:07:50 2022
 ************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int  a ;
	vector<int> vec;
	for (int i = 0; i < 3; i++)
	{
		cin >> a;
		vec.push_back(a);
	}
	sort(vec.begin() , vec.end());
	for (int i = 0; i < 3; i++)
	{

		cout << vec[i] << " ";
	}

	cout << endl;
	return 0;
}
