/*************************************************************************
	> File Name: 1070.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  2/25 17:10:02 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	int n;
	int a = 0,b = 0,c = 0;
	while (cin >> n && n != 0)
	{
		if (n<60)c++;
		else if (n>=85)a++;
		else b++;

	}
	cout << ">=85:" << a << endl << "60-84:" << b << endl << "<60:" << c << endl; 
	return 0;
}
