/*************************************************************************
	> File Name: 1143.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 三  3/ 2 16:14:01 2022
 ************************************************************************/

#include<iostream>
using namespace std;
bool isprime(int n)
{
	if (n < 4) return n>1;

	for (int i = 2; i <= n/2; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}
int main ()
{
	int n;
	cin >> n;
	if (isprime(n)) cout << 1 << endl;
	else cout << 0 << endl;

	return 0;
}
