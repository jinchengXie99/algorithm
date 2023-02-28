/*************************************************************************
	> File Name: 1981.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  3/ 8 14:19:52 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	if (a >= b) cout << "Error" << endl;
	else {
	for (int i = a+1; i <= b; i++)
	{

		cout <<  i  << " " ;
	}
		
	}
	 cout << endl;
	return 0;
}
