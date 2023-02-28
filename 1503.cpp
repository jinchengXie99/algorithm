/*************************************************************************
	> File Name: 1503.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  3/ 3 23:09:43 2022
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main ()
{
	int n ;
	cin >> n;
	vector<int> vec;
	while(n--)
	{
		int a;
		cin >> a;
		vec.push_back(a);
		
	}
	sort(vec.begin(),vec.end(),greater<int>());
	for (int i = 0; i < 10; i++)
	{
		cout << vec[i] << " ";
	}

	return 0;
}
