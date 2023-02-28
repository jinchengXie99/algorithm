/*************************************************************************
	> File Name: 1987.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  3/18 21:39:18 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int  main ()
{
	int n;
	cin >> n;
	n /= 10;
	if (n < 4) cout << "D" << endl;
	else if (n < 6) cout << "C" << endl;
	else if (n < 8) cout << "B" << endl;
	else if (n < 11) cout << "A" << endl;
	return 0;
}
