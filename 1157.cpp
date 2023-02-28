/*************************************************************************
	> File Name: 1157.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 三  3/ 2 17:09:25 2022
 ************************************************************************/

#include<iostream>
using namespace std;
bool is(int a, int b)
{
	int sum = 0;
	for (int i = 1; i <= a/2; i++)
	{
	if (a%i==0)sum+=i;
	if (sum>b) return false;
	}
	if (sum == b ) return true;
	else return false;

}
int main ()
{

int a,b;
int n;
cin >>n;
while(n--){
	cin >> a >> b;
	if (is(a,b)&&is(b,a)) cout << "YES" <<endl;
	else cout << "NO" <<endl;
}
	return 0;
}
