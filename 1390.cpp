/*************************************************************************
	> File Name: 1390.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 日  2/27 23:14:49 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{

	int n;
	long long  sum=0;
	while(cin >> n)
	{	
		for (int i = 0; i< n; i++)
		{	
			int b;
			cin >> b;
			if (b<0)b=-b;
			sum +=b;
		}
		cout << sum << endl;
		sum =0;
	}
	return 0;
}
