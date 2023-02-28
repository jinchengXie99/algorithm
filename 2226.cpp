/*************************************************************************
	> File Name: 2226.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  2/22 23:00:48 2022
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
void display(int a){cout<< a<<" ";}
int main (){
	int a[3];
	cin >> a[1]>>a[2]>>a[0];
	sort(a,a+3,greater<int>());
	for_each(a,a+3,display);

	
return 0;
}
