/*************************************************************************
	> File Name: 1017.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 一  2/14 21:15:18 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{

	int N;
	cin >> N;
	int Ns = 0;//因数和
	for (int i = 2; i <	N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (i % j == 0)Ns+=j;
		}
		if (Ns == i){
			cout << i << " its factors are ";
			for ( int j = 1; j < i; j++)
			{
				if (i % j == 0)cout << j << " ";
			}
				cout << endl;
		}
		Ns = 0;
	}
	return 0;

}
