/*************************************************************************
	> File Name: 1024.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  2/15 18:36:59 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main()
{
		int mainsum = 0, subsum = 0;
		int t;
		for (int i = 0; i < 3; i++)
		{
				for (int j = 0; j < 3; j++)
				{	
					cin >> t;
					if (i == j)mainsum+=t;
					if (i + j == 2)subsum+=t;
					
				}
		}

		cout << mainsum << " " << subsum << endl;
		return 0;
}
