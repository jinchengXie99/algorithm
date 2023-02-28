#include <stdio.h>  //fopen
#include <errno.h>  //errno
#include <string.h> //strerror(errno)
​
int main()
{
    FILE *fp = fopen("xxxx", "r");
    if (NULL == fp)
    {
        printf("%d\n", errno);  //打印错误码
        printf("%s\n", strerror(errno)); //把errno的数字转换成相应的文字
        perror("fopen err");    //打印错误原因的字符串
    }
​
    return 0;
}