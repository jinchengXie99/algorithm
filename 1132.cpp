/*************************************************************************
	> File Name: 1132.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 三  3/ 2 13:57:11 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
		
	int n;
	int max;
	int i=1;
	while (cin >> n && n != -1)
	{	
		if (i == 1){
		max=n;
		i++;
		}
		if (n > max) max = n;
	}
	cout << max << endl;
	return 0;
}
