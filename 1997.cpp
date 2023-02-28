/*************************************************************************
	> File Name: 1997.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  3/18 22:17:50 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main () {
	
	int m,b;
	cin >> m >> b;
	for (int i = 1; i < m; i++) {
		if (i == 4 || i == 6 || i == 9 || i == 11) b += 30;
		else if (i == 2) b += 28;
		else b += 31;
		
	}

	cout << b << endl;
	return 0;
}
