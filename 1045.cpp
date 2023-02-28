/*************************************************************************
	> File Name: 1045.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  2/18 22:02:20 2022
 ************************************************************************/

#include<iostream>
#include<algorithm>// swap 交换两个数
				   // min_element(cape.begin(),cape.end()) [begin,end)区间找最小值
				   // 返回迭代器 要得到下标 所以要减去数组首地址
using namespace std;
int main ()
{
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
	cin >> arr[i];
	}
	swap(arr[0],arr[min_element(arr,arr+10)-arr]);
	swap(arr[9],arr[max_element(arr,arr+10)-arr]);
	for (int i = 0; i < 10; i++)
	{
	cout << arr[i] << " ";
	}


	return 0;
}
