/*************************************************************************
	> File Name: 1084.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 六  2/26 14:53:47 2022
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
bool ispreme(int n )
{
	if (n<4) return n>1;
	for (int i = 2; i <= sqrt(n); i++ )
	{
		if ( n%i==0 ) return false;
	}
	return true;

}
int main ()
{
	int n;
	cin >> n;
	for (int i =2; i <= n; i++)
	{
		if (ispreme(i)) cout << i << endl;
	
	}
	
	return 0;
}
