/*************************************************************************
	> File Name: 1047.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  2/24 16:32:59 2022
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

int main ()
{
	queue<int> q;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}
	int num = 1;
	while (! q.empty())
	{
		if (num == 3){//数到了
			if (q.size()==1)cout << q.front() <<endl;
			q.pop();
			num = 1; //继续从1开始数
		}else {
		num++;
		q.push(q.front());
		q.pop();
		
		}


	}

	return 0;
}
