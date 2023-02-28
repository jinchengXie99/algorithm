/*************************************************************************
	> File Name: 2060.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  3/ 8 14:28:41 2022
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main ()
{
	int a;
	cin >> a;
	int b;
	long long  sum = 0;
	vector<int> v;
	int n = a;
	while ( n-- )
	{
		cin >> b;
		v.push_back(b);
	}
	sort(v.begin(),v.end());
	for (int i = 0; i <= a/2; i++)
	{
		sum += (v[i]/2 + 1);
	} 
	cout << sum << endl;
	return 0;
}
