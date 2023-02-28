/*************************************************************************
	> File Name: 1069.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  2/25 16:40:51 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	int n;;
	cin >> n;
	int a[n][n];
	int x = 0 ,y = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j< n; j++)
		{
			cin >> a[i][j];
			if (a[i][j]>a[x][y]){
			x = i;
			y = j;
			}
		}
		
	}

	cout << a[x][y] << " " << (x+1) << " "<< (y+1) << endl;
	return 0;
}
