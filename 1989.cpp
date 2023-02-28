/*************************************************************************
	> File Name: 1989.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  3/10 22:41:52 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	int n;
	cin >> n;
	int sum = 0;
	while(n != 0)
	{
		if ((n%10)%2!=0)sum++;
		n /= 10;
	}
	cout << sum << endl;
	return 0;
}
