/*************************************************************************
	> File Name: 1054.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 一  2/21 22:41:36 2022
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
bool isprime(int n){	
	if (n <= 3 ) return n > 1;

	for (int i = 2; i <= sqrt(n); i++ )
	{
		if (n%i==0)return false;
	}
	return true;

}
int main ()
{
	int a,b;
	cin >> a >> b;
	int sum = 0;
	for (int i = a; i <= b;i++)
	{
		if (isprime(i))sum+=i;
	}
	cout << sum << endl;
	return 0;
}
