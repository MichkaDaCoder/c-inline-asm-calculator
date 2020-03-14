#include <stdio.h>

/**
* @@date: 14/03/2020
* @@authr: MichkaDaCoder
* @@description:a simple calculator written using inline asm and c.
**/

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int increment(int a);
int decrement(int a);
char hello(char t[]);

int main()
{
    system("title c-inline-asm-calculator");
    printf("\t**************************************************\n");
    printf("\t*             c-inline-asm-calculator            *\n");
    printf("\t**************************************************\n");
    printf("\t*                  MichkaDaCoder                 *\n");
    printf("\t*        https://github.com/MichkaDaCoder        *\n");
    printf("\t**************************************************\n\n");
    int x, y;
    printf("\n x : ");
    scanf ("%d", &x);
    printf("\n y : ");
    scanf ("%d", &y);
    printf("\n[1]- add\n");
    printf("[2]- sub\n");
    printf("[3]- mul \n");
    printf("[4]- div \n");
    printf("[5]- inc \n");
    printf("[6]- dec");
    printf("\n\n please make a choice: ");
    int index;
    scanf("%d",&index);
    system("cls");
    switch(index)
    {
       case 1 : printf("%d + %d = %d",x,y,add(x,y)); break;
       case 2 : printf("%d - %d = %d",x,y,sub(x,y));break;
       case 3 : printf("%d x %d = %d",x,y,mul(x,y));break;
       case 4 :
           if(y==0) {printf("infinity");}
           else {
        printf("%d / %d = %d",x,y,div(x,y));
           }
           break;
           case 5: printf("%d++ = %d",x,increment(x)); break;
           case 6: printf("%d-- = %d ",x,decrement(x));break;
       default: printf("incorrect choice.");
    }
    printf("\n\nThank you! :)\n\n");
    return 0;
}
int add(int a, int b)
{
    int c;
    __asm
    (
        "mov %1, %%eax;"
        "mov %2, %%ecx;"
        "add %%ecx, %%eax;"
        "mov %%eax, %0;"
        :"=r"(c)
        :"r"(a), "r"(b)
        :"%eax", "%ecx"
    );

    return c;
}

int mul(int a, int b)
{
    int c;
    __asm
    (
        "mov %1, %%eax;"
        "mov %2, %%ecx;"
        "mul %%ecx;"
        "mov %%eax, %0;"
        :"=r"(c)
        :"r"(a), "r"(b)
        :"%eax", "%ecx"
    );

    return c;
}

int sub(int a, int b)
{
    int c;
    __asm
    (
        "mov %1, %%eax;"
        "mov %2, %%ecx;"
        "sub %%ecx, %%eax;"
        "mov %%eax, %0;"
        :"=r"(c)
        :"r"(a), "r"(b)
        :"%eax", "%ecx"
    );

    return c;
}

int div(int a, int b)
{
    int c;
    __asm
    (
        "mov %1, %%eax;"
        "mov %2, %%ebx;"
        "xor %%edx,%%edx;"
        "div %%ebx;"
        "mov %%eax, %0;"
        :"=r"(c)
        :"r"(a), "r"(b)
        :"%eax", "%ecx"
    );

    return c;
}

int increment(int a) {
  int c;

  __asm(
        "mov %1, %%eax;"
        "inc %%eax;"
        "mov %%eax, %0;"
        :"=r"(c)
        :"r"(a)
        :"%eax"
        );
        return c;
}

int decrement(int a) {
  int c;

  __asm(
        "mov %1, %%eax;"
        "dec %%eax;"
        "mov %%eax, %0;"
        :"=r"(c)
        :"r"(a)
        :"%eax"
        );
        return c;
}

