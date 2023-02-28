/*************************************************************************
	> File Name: 1049.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  2/24 17:04:41 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int sum_day(int years,int month,int day){
	int sum = 0;
	for (int  i = 1; i < month; i++)
	{
		if (i == 4|| i==6||i==9||i==11)sum+=30;
		else if (i == 2){
			sum+=28;
			if ((years%4==0&&years%100!=0)||years%400==0)sum++;
		}
		else sum+=31;
	}

	return sum+day;
}
int main()
{
	int y,r,n; 
	cin >> n >> y >> r;
	cout << sum_day(n,y,r)<< endl;
	return 0;
}
