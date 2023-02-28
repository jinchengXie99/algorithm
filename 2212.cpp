/*************************************************************************
	> File Name: 2212.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  2/22 11:21:15 2022
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void display(int a){cout << a <<" ";}
int main ()
{
	int n; 
	cin >> n;
	int t;
	vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		vec.push_back(t);
	}
	sort(vec.begin(),vec.end(),greater<int>());
	for_each(vec.begin(),vec.end(),display);

	return 0;
}
