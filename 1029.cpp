/*************************************************************************
	> File Name: 1029.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  2/17 14:01:56 2022
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
bool fun (int n)
{
	if (n < 4)
	{
		return (n > 1);
	}
	for (int i = 2; i <= sqrt(n); i++ )
	{
		if ( n%i == 0)return false;
	}
	return true;

}
int main ()
{


	int n;
	cin >> n;
	bool y = fun(n);
	if (y)cout << "prime" << endl;
	else cout << "not prime" << endl;
	return 0;
}
