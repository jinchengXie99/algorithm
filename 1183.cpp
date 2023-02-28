/*************************************************************************
	> File Name: 1183.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  2/24 22:44:39 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	int n;
	cin >> n;
	while (n--)
	{
	int ah,am,as;
	int bh,bm,bs;
	cin >> ah >> am >> as >> bh >>bm >> bs;
	if((as+bs)>=60)am++;
	if((am+bm)>=60)ah++;
	cout << ah+bh <<" "<< (am+bm)%60 << " " << (bs+as)%60 <<endl;

	}

	return 0;
}
