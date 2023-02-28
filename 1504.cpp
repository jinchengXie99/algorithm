/*************************************************************************
	> File Name: 1504.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  3/ 3 23:17:46 2022
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
int main ()
{

	for (int i = 1; i < 1000; i++)
	{
		for (int j = i+1; j < 1000; j++)
		{
			int c;
			c = sqrt(i*i+j*j);
			if ( j+i+c <= 1000 && i*i + j*j == c*c)
				cout << i << " " << j << " " << c << endl;

		}

	}
	return 0;
}
