/*************************************************************************
	> File Name: 1850.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  3/ 4 14:34:13 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	int year,month,day;
	char t;
	while(cin >> year >> t >> month >> t >> day)
	{
	int sum = 0;
		if ((year%4==0&&year%100!=0)||year%400==0)
			{
				for(int i = 1; i < month; i++)
				{
					if (i==4||i==6||i==9||i==11) sum+=30;
					else if (i==2) sum+=29;
					else sum+=31;
				}
			}
		else {

			for(int i = 1; i < month; i++)
				{
					if (i==4||i==6||i==9||i==11) sum+=30;
					else if (i==2) sum+=28;
					else sum+=31;
				}
		}
		sum+=day;
		cout << sum << endl;

	}
	return 0;
}
