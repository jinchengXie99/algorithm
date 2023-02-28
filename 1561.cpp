;/*************************************************************************
	> File Name: 1561.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  2/22 10:44:00 2022
 ************************************************************************/

#include<iostream>
using namespace std;
bool isprime(int n)
{
	if (n<4) return n>1;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0) return false;
		
	}
	return true;
	
}
int main ()
{
	int n;
	cin >> n;
	for (int i = 2; i < n; i++ )
	{
	if (n % i == 0 && isprime(i))cout << i << " ";

	} 


	return 0;
}
