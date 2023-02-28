/*************************************************************************
	> File Name: 1022.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  2/15 15:58:34 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{

	int n;
	cin >> n;
	int  t = 0;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j < i;j++)
		{

		if (i % j == 0){
			t = 1;
			break;
		}else t = 0;
		}
		if (t != 1)cout << i << endl;
	}
	return 0;
}
