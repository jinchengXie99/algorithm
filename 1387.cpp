/*************************************************************************
	> File Name: 1387.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 日  2/27 22:58:21 2022
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int main ()
{
	
	int a,b,c;
	while(cin>>a>>b>>c)
	{
		if (a+b>c&&b+c>a&&c+a>b)
			cout <<"YES" << endl;
		else cout << "NO" << endl;
		
	}
	return 0;
}
