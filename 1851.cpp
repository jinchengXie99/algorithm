/*************************************************************************
	> File Name: 1851.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  3/ 4 15:03:28 2022
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
bool fun(int n)
{	
	int a, b,c;
	a=n%10;
	b=n/10%10;
	c=n/100%10;
	if (pow(a,3)+pow(b,3)+pow(c,3)==n) return true;
	else return  false;
	
}
int main ()
{
	int a,b;
	while(cin >> a >> b)
	{
		int sum = 0;
		for (int i = a; i <= b; i++)
		{
			if (fun(i)){cout << i << " ";
		sum++;	}
			if (i==b&&!fun(i)&&sum==0) cout <<"no" << endl;
		}
		
	}
	return 0;
}
