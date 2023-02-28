/*************************************************************************
	> File Name: 2059.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 日  3/ 6 16:49:52 2022
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;
int main ()
{

	int n,m;
	cin >> n >> m;
	vector<int> a;
	while (n--)
	{
		int t;
		cin >> t;
		a.push_back(t);
	}
	sort(a.begin(),a.end(),greater<int>());
	for (int i = 0; i < m; i++)
	{
		cout << a[i] <<" ";

	}
	return 0;
}
