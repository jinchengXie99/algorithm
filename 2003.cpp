/*************************************************************************
	> File Name: 2003.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  3/29 12:17:18 2022
 ************************************************************************/

#include<iostream>
#include <string>
using namespace std;
int main ()
{	
	string str;
	getline(cin,str);
	int a, b ,c;
	 a=b=c=0;
	for (int i = 0; i < 10; i++)
	{
		if ((str[i] <= 'Z' && str[i] >= 'A' ) || (str[i] >='a' && str[i] <= 'z'))
		{
			a++;
		}
		else if (str[i] >= '0' && str[i] <= '9') b++;
		else c++;
	}

		cout << a << " " << b <<  " " << c ;
	
	return 0;
}
