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
 /*
 数组和指针可交换性的总结

1.用a[i]这样的形式对数组进行访问总是被编译器“改写”或解释为像*(a+i)这样的指针访问。

2.指针始终就是指针。它绝不可以改写成数组。你可以用下标形式访问指针，一般都是作为函数参数时，而且你知道实际传递给函数的是一个数组。

3.在特定的上下文中，也就是它作为函数的参数（也只有这种情况），一个数组的声明可以看做是一个指针。作为函数参数的数组（就是在一个函数调用中）始终会被编译器修改成为指向数组第一个元素的指针。

4.因此，当把一个数组定义为函数的参数时，可以选择把它定义为数组，也可以定义指针。不管选择哪种方法，在函数内部事实上获得的都是指针。

5.在其他所有情况中，定义和声明必须匹配。如果定义了一个数组，在其他文件对他进行声明时也必须把它声明为数组，指针也是如此。

选自《C专家编程》
*/
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
