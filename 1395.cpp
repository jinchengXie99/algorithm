/*************************************************************************
	> File Name: 1395.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 日  3/ 6 15:56:24 2022
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main ()
{

	int n;
	cin >> n;
	while (n--)
	{
		int  m;
		cin >> m;
		vector<int> vec;
		for (int i = 0; i < m; i++)
		{
				int t;
				cin >> t;
				vec.push_back(t);
		}
		sort(vec.begin(),vec.end());
		cout << vec[1] << endl;
		
	}
	return 0;
}
