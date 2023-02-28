/*************************************************************************
	> File Name: 1391.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 日  2/27 23:23:03 2022
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void print(int n)
{
	cout << n <<" ";
}
int main ()
{

	int n;
	while (cin >> n)
	{
			vector<int> vec;
		for (int i = 0; i < n; i++)
		{
			int b;
			cin >> b;
			vec.push_back(b);
			sort(vec.begin(),vec.end(),greater<int>());
		}
		for_each(vec.begin(),vec.end(),print);
		cout << endl;
	}
	return 0;
}
