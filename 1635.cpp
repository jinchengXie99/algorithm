/*************************************************************************
	> File Name: 1635.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  3/ 4 12:19:35 2022
 ************************************************************************/

#include<iostream>
using namespace std;
void ave(int *a,int n)
{
	int sum = 0;
	for (int i = 0; i < n; i ++)
	{
		cin >> a[i];
		sum += a[i];
	}
	cout << sum/n << endl;
}
int main ()
{
	int n;
	cin >> n;
	int arr[n];
	ave(arr,n);
	return 0;
}
