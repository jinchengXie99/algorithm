/*************************************************************************
	> File Name: 1849.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  3/ 4 14:21:12 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{

	int a;
	while (cin >> a)
	{
		if (a < 0) { cout << "Score is error!" << endl;
		continue;
		}
		a/=10;
		if (a >= 0 && a < 6) cout << "E" << endl;
		else if (a == 6) cout << "D" << endl;
		else if (a == 7) cout << "C" << endl;
		else if (a == 8) cout << "B" << endl;
		else if (a == 9 || a == 10) cout << "A" << endl;
		else if (a > 10 || a < 0 )cout << "Score is error!" << endl;
	}
	return 0;
}
