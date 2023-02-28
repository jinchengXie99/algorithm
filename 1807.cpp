/*************************************************************************
	> File Name: 1807.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  3/ 8 12:44:50 2022
 ************************************************************************/

#include<iostream>
#include<iomanip>
using namespace std;
int main ()
{

	int a,b,c;
	cin >> a >> b >> c;
	cout << setiosflags(ios::left);
	cout << setw(8) << a ; 
	cout <<	setw(8) << b ;
	cout <<	setw(8) << c << endl;
	return 0;
}
