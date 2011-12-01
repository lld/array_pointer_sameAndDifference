#include <stdio.h>
#include <stdlib.h>
#define MAX 10;

/*
 *�������н��
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

 //�������н��˵��
 /*
 �����ָ��ɽ����Ե��ܽ�

1.��a[i]��������ʽ��������з������Ǳ�����������д�������Ϊ��*(a+i)������ָ����ʡ�

2.ָ��ʼ�վ���ָ�롣���������Ը�д�����顣��������±���ʽ����ָ�룬һ�㶼����Ϊ��������ʱ��������֪��ʵ�ʴ��ݸ���������һ�����顣

3.���ض����������У�Ҳ��������Ϊ�����Ĳ�����Ҳֻ�������������һ��������������Կ�����һ��ָ�롣��Ϊ�������������飨������һ�����������У�ʼ�ջᱻ�������޸ĳ�Ϊָ�������һ��Ԫ�ص�ָ�롣

4.��ˣ�����һ�����鶨��Ϊ�����Ĳ���ʱ������ѡ���������Ϊ���飬Ҳ���Զ���ָ�롣����ѡ�����ַ������ں����ڲ���ʵ�ϻ�õĶ���ָ�롣

5.��������������У��������������ƥ�䡣���������һ�����飬�������ļ�������������ʱҲ�����������Ϊ���飬ָ��Ҳ����ˡ�

ѡ�ԡ�Cר�ұ�̡�
*/
 //�������ǳ�����������Ϊ��ֵ��ָ��ȴ����
void say_array(char ca[]);
void say_pointer(char *ca);

int main()
{
    char ca[10] = "abcde";
    char *pca = ca;
    say_array(ca);
    say_pointer(ca);
    printf("main &ca :    %p\n", &ca);
    printf("main &pca :   %p\n", &pca);//pca��ʾca�����ַ�ĵ�ַ
    printf("main &*pca :  %p\n", &*pca);//*pca �ȼ��� ca
    printf("main &ca[0] : %p\n", &ca[0]);
    printf("main &ca[1] : %p\n", &ca[1]);

    return 0;
}

void say_array(char ca[])
{
    printf("say_array &ca :        %p\n", &ca);
    printf("say_array &(ca[0]) :   %p\n", &(ca[0]));
    printf("say_array &*(ca + 1) : %p\n", &*(ca + 1));//ca[i]����ʽ��������з������Ǳ�������"��д"�����Ϊ��*(ca+i)����ָ����ʵ���ʽ
    printf("say_array &(ca[1]) :   %p\n\n", &(ca[1]));
}

void say_pointer(char *ca)
{
    printf("the value of *ca is %c \n", *ca);
    printf("say_pointer &ca :       %p\n", &ca);
    printf("say_pointer &(ca[0]) :  %p\n", &(ca[0]));
    printf("say_pointer &(ca + 1]) :%p\n", &*(ca + 1));//ca[i]����ʽ��������з������Ǳ�������"��д"�����Ϊ��*(ca+i)����ָ����ʵ���ʽ
    printf("say_pointer &(ca[1]) :  %p\n\n", &(ca[1]));
}
