/*************************************************************************
	> File Name: 1388.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 日  2/27 23:04:55 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	
	int n;
	while (cin >> n)
	{
		if (n<0||n>100){cout << "Error!"<< endl;continue;}
		if (n>=90)cout << "A" << endl;
		else if (n>=75) cout << "B" << endl;
		else if (n>=60) cout << "C" << endl;
		else cout << "D" << endl;
	}
	return 0;
}
