/*************************************************************************
	> File Name: 1046.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 六  2/19 15:26:38 2022
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
int main ()
{
	vector<int> a;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{	
		int t;
		cin >> t;
		a.push_back(t);
	}
	int m;
	cin >> m;
	m = m % n;
	vector<int> vec;
	for (int i = n - m  ; i < n; i++)
	{
		vec.push_back(a[i]);
	}
	for (int i = 0; i < n -m; i++)
	{
		vec.push_back(a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
	return 0;
}
