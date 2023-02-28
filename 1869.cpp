/*************************************************************************
	> File Name: 1869.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  3/ 4 19:04:36 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	int n,m;
	while (cin >> n >> m)
	{
	//	2*x+4*y=m;
	//	x+y =n;
		int x = (4*n - m)/2;
		
		int y = n-x ;	
		if (x >= 0 && y >= 0  && m >= 0 && x+y==n)cout << x << " " << y << endl;
		else cout << "No answer" << endl;
	}
	return 0;
}
