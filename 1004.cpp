/***********************************************************************
	> File Name: 1004.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  2/11 14:55:31 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	int s[56]={0,1,2,3,4};
	for(int i = 5; i < 56; i++){
		s[i] = s[i-1] + s[i-3];
	}
	int n;
	while(cin >> n && n != 0 ){
	
	cout << s[n] << endl;	
	}
	return 0;
}
