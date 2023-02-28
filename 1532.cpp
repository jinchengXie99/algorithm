/*************************************************************************
	> File Name: 1532.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  3/ 4 10:18:03 2022
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
int main ()
{
	int arr[3][4];
	int x=0,y=0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j	++)
		{
			cin >> arr[i][j];
			if ( abs( arr[i][j] ) > abs( arr[x][y] ) ){
					 x=i;
					 y=j;
			}

		}

	}
	cout << abs(arr[x][y]) << " " << x+1 << " " << y+1 <<endl;
	return 0;
}
