#include<stdio.h>
#include<stdlib.h>
#define bool char
#define true 1
#define false 0
#define MaxSize 50
typedef int Elemtype;
typedef struct SqStack
{
    Elemtype data[MaxSize];
    int top;
}SqStack;
//栈的初始化
bool Initstack(SqStack *S)
{
    S->top = -1;
}
//栈的判空
bool StackEmpty(SqStack S)
{
    if(S.top == -1)    return true;
    else               return false;
}
//进栈
bool Push(SqStack *S,Elemtype e)
{
    if(S->top == MaxSize - 1)     return false;
    S->data[++S->top] = e;
    return true;
}
//出栈
bool Pop(SqStack *S,char *e)
{
    if(S->top == MaxSize - 1)     return false;
    *e = S->data[S->top--];
    return true;
}
//读栈顶元素
bool GetTop(SqStack S,char *e)
{
    if(S.top == MaxSize - 1)     return false;
    *e = S.data[S.top];
    return true;
}

int main()
{
    SqStack S;
    Initstack(&S);
    char X;

    const char* text = "kiglnmrmeiahenrteof4ardar";
    int pushcount, popcount;

    //把数字串建立为一个数组
    int a[] = {3, 1, 1, 2, 1, 1, 2, 1, 2, 1, 1, 1, 1, 2, 1, 2, 2, 2, 2, 1, 1, 3, 1, 1, 3, 2, 0, 2, 1, 2, 2, 1, 1, 1};
    int num = sizeof(a) / sizeof(a[0]);

    int b = 0;//用于确定压入第几个密文串
    for(int i = 0;i < num;i++)
    {
        if(i%2 == 0)
        {
            pushcount = a[i];
            for (int j = 0;j<pushcount;j++)
            {
                Push(&S,text[b++]);
            }
        }
        else{
            popcount = a[i];
            for(int j = 0;j < popcount;j++)
            {
                if(!StackEmpty(S)){
                GetTop(S,&X);
                Pop(&S,&X);  
                printf("%c", X);}
            }
        }
    }
    return 0;
}