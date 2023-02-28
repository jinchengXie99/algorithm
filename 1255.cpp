/*************************************************************************
	> File Name: 1255.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 三  3/ 9 12:03:40 2022
 ************************************************************************/

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main ()
{

	int n;
	int t;
	cin >> n;
	vector<int> v;
	for (int i = 0; i <  n ; i++ )
	{
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(),v.end());
	long long sum = 0;
	for(vector<int>::iterator it = v.begin()+1; it != v.end() ; it++)
	{
		sum += (*it) * (*(it-1));
	}
	sum *= v[n-1];
	cout << sum << endl;
	return 0;
}
