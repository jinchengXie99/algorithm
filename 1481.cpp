/*************************************************************************
	> File Name: 1481.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  3/ 3 22:38:55 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{

	int a,b;
	cin >> a >> b;
	if (a-b==0||a-b==1) cout << a-b <<endl;
	else if (a- b == -2)
		cout <<"1"<<endl;
	else cout << "-1" <<endl;
	return 0;
}
