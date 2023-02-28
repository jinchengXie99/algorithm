/*************************************************************************
	> File Name: 1895.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 三  3/16 19:08:16 2022
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
int main ()
{
	int n;
	cin >> n;
	queue<int> q;
	int sum = 0;
	while (n--)
	{
		int c;
		int t;
		cin >> c;
		if (c == 1){
		cin >> t;
		sum++;
		q.push(t);
		}else if (c == 2)
		{
			if (q.empty())
			{
				cout << "no"<< endl;
				exit(0);
			}
			cout << q.front() << endl;
			q.pop();
			sum--;
		}else if (c == 3){
			cout << sum << endl;
		}


	}
	return 0;
	
}
