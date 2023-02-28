/*************************************************************************
	> File Name: 1872.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  3/ 8 13:30:45 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{

	int a;
	cin >> a;
	switch(a)
	{
		case 1: case 2: case 12: cout << "Winter"; break;
		case 4: case 5: case  3: cout << "Spring";break;
		case 7: case 8: case  6: cout << "Summer";break;
		case 10: case 11: case 9: cout << "Autumn";break;
		

	}
	return 0;
}
