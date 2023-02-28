/*************************************************************************
	> File Name: 1142.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 三  3/ 2 16:50:16 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{

	int sum = 0;
	int n ;
	cin >> n;
	int i = 0;
	while (sum <= n )
	{
		i++;
		sum += i*i*i;
	}
	cout << i-1 <<endl;
	return 0;
}
