/*************************************************************************
	> File Name: 1072.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  2/17 11:57:27 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	int n;
	int sum = 0;
	hile (cin >> n && n != 0 )
	{
		while(n != 1){
			sum += n/3;
			n = (int)n/3 + n%3; 
			if (n == 3 || n == 2){ sum++; break;}
		}
		cout << sum << endl;
		sum = 0;
	}

	return 0;
}
