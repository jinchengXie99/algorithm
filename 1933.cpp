/*************************************************************************
	> File Name: 1933.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  3/ 4 16:08:17 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n/2; i++)
	{
		if (n%i==0) {sum++;
		}
	}
sum++;
cout << sum << endl;
	return 0;
}
