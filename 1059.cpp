/*************************************************************************
	> File Name: 1059.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  2/24 21:52:21 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	
	int n;
	cin >> n;
	int i=2;
	int sum = 0;
	while(n--)
	{
		sum+=i;
		i+=3;
	}
	cout << sum << endl;
	return  0;

}
