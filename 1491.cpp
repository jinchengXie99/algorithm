/*************************************************************************
	> File Name: 1491.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  3/ 3 23:01:44 2022
 ************************************************************************/

#include<iostream>
using namespace std;
void swap (int & a,int & b)
{
	int t = a;
	a = b;
	b = t;
}
int main ()
{
	int n,m;
	cin >> n >> m;
	int arr[n];
	for(int i = 0; i < n; i++)
	{
		int t;
		cin >> t ;
		arr[i] = t;
	}
	while (m--)
	{
		int a,b;
		cin >> a >> b;
		swap(arr[a-1],arr[b-1]);
	
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}
