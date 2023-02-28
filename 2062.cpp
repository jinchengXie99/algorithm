/*************************************************************************
	> File Name: 2062.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  3/ 8 16:29:44 2022
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int main ()
{

	int n;
	cin >> n;
	int arr[101];
	while (n--)
	{
		int a;
		cin >> a;
		for(int i = 0; i < a; i++)
		{
			cin >> arr[i];
		}
		sort(arr,arr+a);
		cout << arr[1] <<endl;
	}
	return 0;
}
