/*************************************************************************
	> File Name: 1095.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  3/ 8 22:16:48 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	
	int a, b;
	int  max=1;
	long long  t ;
	int n;
	while ( cin >> a >> b )
	{
		cout << a << " " << b << " ";
		if (a > b){
		int t = a;
			a = b; 
			b = t;
		}
		for(int i = a; i <= b; i++)
		{
			  t = i;
			  n = 1;
			while (t != 1)
			{
				if (t%2 == 0) t /= 2;
				else t = t*3 + 1;
				n++;
			}
			if (n >  max) max = n;
		}
        	cout <<  max << endl;
	max = 1;	
	}
	return 0;
}
