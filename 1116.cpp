/*************************************************************************
	> File Name: 1116.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  3/ 8 23:25:30 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	int a, b, c,d;
	while (1){
			
		int j = scanf ("%d.%d.%d.%d",&a,&b,&c,&d);
		if (j<4) cout << "N" << endl;
		else if ( a>-1&&a<256&&b>-1&&b<255&&c>-1&&c<256&&d>-1&&d<256 )
			cout << "Y" << endl;
	}
	return 0;
}
