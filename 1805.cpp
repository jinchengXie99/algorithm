/*************************************************************************
	> File Name: 1805.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  3/ 8 12:35:11 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{

	int a,b;
	cin >> a >> b;
	int c = b-a;
	if (c==2||c== -1)cout << 1 ;
	else if (c==0) cout << 0;
	else cout << -1;
	return 0;
}
