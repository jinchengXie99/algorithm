/*************************************************************************
	> File Name: 1396.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 日  3/ 6 16:11:52 2022
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main ()
{

	int n;
	while (cin >> n && n != 0)
	{
		vector<int> vec;
		for(int i = 0; i < n; i++)
		{
			int t;
			cin >> t;
			vec.push_back(t);
		}
		sort(vec.begin(),vec.end());
		int len = n/2+1;
		int sum = 0;
		for (int i = 0; i < len; i++)
		{
			sum += vec[i]/2 +1;// 关键就是每个州 一半多一人 则可获得支持
		}
		cout << sum <<endl;
	}
	return 0;
}
