/*************************************************************************
	> File Name: 1856.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  3/ 4 16:31:18 2022
 ************************************************************************/

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main ()
{
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		v.push_back(t);
		
	}
	sort(v.begin(),v.end());
	for (int i = 0; i < 3; i++)
	{

		cout << v[i] <<" " ;
	}
	return 0;
}
