/*************************************************************************
	> File Name: 1023.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  2/15 16:29:54 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{

	int arr[10];
	for (int i = 0; i < 10; i++)
	{
	cin >> arr[i];
	}
	int t = 0; 
	for(int i = 0; i < 10; i++)
	{
	
		for (int j = i; j < 10; j++)
		{
			if (arr[t] > arr[j])t = j;
		}
	int a = arr[i];
	arr[i] = arr[t];
	arr[t] = a;

	t = i+1;
	}	
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
		
	}

	return 0;

}
