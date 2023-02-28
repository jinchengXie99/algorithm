/*************************************************************************
	> File Name: 1028.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  2/17 10:58:43 2022
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	float a,b,c;
	cin >> a >> b >> c;
	float z = b*b - 4*a*c;
	if (z > 0){
		z = sqrt(z);
		float x1 = (-b + z)/(2*a);
		float x2 = (-b - z)/(2*a);
		printf ("x1=%.3f x2=%.3f\n",x1,x2);
	}else if (z == 0){
		float x1;
		float x2;
		x1 = x2 = (-b)/(2*a);
		printf("x1=%.3f x2=%.3f\n",x1,x2);
	}else{
		z = sqrt(-z);
		float t = (-b)/(2*a);
		printf ("x1=%.3f+%.3fi x2=%.3f-%.3fi\n",t,z/(2*a),t,z/(2*a));
	}


	return 0;
}
