/*************************************************************************
	> File Name: 1012.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  2/11 16:06:24 2022
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int main ()
{

	int sum[4]={0,0,0,0};
	string str;
	getline(cin,str);
	int len = str.length();
	while((len--) != 0){
	if((str[len] >= 'a' && str[len] <='z')||(str[len]>='A'&&str[len]<='Z'))sum[0]++;
	else if (str[len]>='0'&&str[len]<='9')sum[1]++;
	else if (str[len]==' ')sum[2]++;
	else sum[3]++;
	}
	for(int i=0;i<4;i++)
	{
		cout<< sum[i];
	if (i!=3){cout <<" ";}

	}
	cout << endl;
	return 0;


}
