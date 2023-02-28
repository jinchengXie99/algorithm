/*************************************************************************
	> File Name: 1008.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  2/ 8 22:51:49 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	int c;
	cin >> c;
	if(c>89)cout<< "A"<< endl;
		else if(c>79&&c<90)cout << "B"<< endl;

		else if(c>69&&c<80)cout << "C"<< endl;

		else if(c>59&&c<70)cout << "D"<< endl;
		else cout<<"E"<< endl;
		
	return 0;
}
