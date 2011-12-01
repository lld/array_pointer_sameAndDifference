#include <stdio.h>
#include <stdlib.h>
#define MAX 10;

/*
 *程序运行结果
say_array &ca :        0022FF00
say_array &(ca[0]) :   0022FF16
say_array &*(ca + 1) : 0022FF17
say_array &(ca[1]) :   0022FF17

the value of *ca is a
say_pointer &ca :       0022FF00
say_pointer &(ca[0]) :  0022FF16
say_pointer &(ca + 1]) :0022FF17
say_pointer &(ca[1]) :  0022FF17

main &ca :    0022FF16
main &pca :   0022FF10
main &*pca :  0022FF16
main &ca[0] : 0022FF16
main &ca[1] : 0022FF17

Process returned 0 (0x0)   execution time : 0.016 s
Press any key to continue.
 */

 //程序运行结果说明
 //1.只有在函数参数中数组和指针是等价的
 //2.在不是函数参数中，数组名和指针所指向的值是一样的，代表数组第一个元素的地址
 //数组名是常量，不能作为左值，指针却可以
void say_array(char ca[]);
void say_pointer(char *ca);

int main()
{
    char ca[10] = "abcde";
    char *pca = ca;
    say_array(ca);
    say_pointer(ca);
    printf("main &ca :    %p\n", &ca);
    printf("main &pca :   %p\n", &pca);//pca表示ca数组地址的地址
    printf("main &*pca :  %p\n", &*pca);//*pca 等价与 ca
    printf("main &ca[0] : %p\n", &ca[0]);
    printf("main &ca[1] : %p\n", &ca[1]);
    return 0;

    return 0;
}

void say_array(char ca[])
{
    printf("say_array &ca :        %p\n", &ca);
    printf("say_array &(ca[0]) :   %p\n", &(ca[0]));
    printf("say_array &*(ca + 1) : %p\n", &*(ca + 1));//ca[i]的形式对数组进行访问总是被编译器"改写"或解释为像*(ca+i)这样指针访问的形式
    printf("say_array &(ca[1]) :   %p\n\n", &(ca[1]));
}

void say_pointer(char *ca)
{
    printf("the value of *ca is %c \n", *ca);
    printf("say_pointer &ca :       %p\n", &ca);
    printf("say_pointer &(ca[0]) :  %p\n", &(ca[0]));
    printf("say_pointer &(ca + 1]) :%p\n", &*(ca + 1));//ca[i]的形式对数组进行访问总是被编译器"改写"或解释为像*(ca+i)这样指针访问的形式
    printf("say_pointer &(ca[1]) :  %p\n\n", &(ca[1]));
}
