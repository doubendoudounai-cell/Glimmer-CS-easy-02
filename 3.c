# include <stdio.h>
#include <stdlib.h>
#define bool char
#define true 1
#define false 0
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode* next;
}LNode,*LinkList;



//循环链表的初始化
bool InitLinkList(LinkList L)
{
    L = (LNode*)malloc(sizeof(LNode));
    L->data = 1;
    L->next = L;
}
 

//循环链表的打印
 bool PrintLinkList(LinkList L)
 {
    LNode *p;
    p = L;
    while(p->next)
    {
        p = p->next;
        printf("%d-->",p->data);
    }
    printf("NULL\n");

 }


//单链表的尾插法
bool TailInsertLinkList(LinkList L)
{
    LNode *NewNode;
    LNode *TailNode = L;
    ElemType NewNode_data;
    while(TailNode->next != NULL)
    {
        TailNode = TailNode->next;
    }
    printf("T:");
    scanf("%d",&NewNode_data);
    while(NewNode_data!=9999)
    {
        NewNode = (LNode*)malloc(sizeof(LNode));
        NewNode->data = NewNode_data;
        NewNode->next = NULL;
        TailNode->next = NewNode;
        TailNode = NewNode;
        printf("T:");
        scanf("%d",&NewNode_data);
    }

    return 0;
}


//单链表的头插法
bool HeadInsertLinkList(LinkList L)
{
    LNode *NewNode;
    ElemType NewNode_data;
    printf("H:");
    scanf("%d",&NewNode_data);
    while(NewNode_data!=9999)
    {
        NewNode = (LNode*)malloc(sizeof(LNode));
        NewNode->next = L->next;
        L->next = NewNode;
        NewNode->data = NewNode_data;
        printf("H:");
        scanf("%d",&NewNode_data); 
    }


    return 0;
}




//按位查找
LNode* GetElem(LinkList L, int i)
{
LNode *p = L;
for(int j = 0; j<i; j++)
{
    p = p->next;
}
return p;
}
//按位删除
bool LocalDeletElem(LinkList L,int i,ElemType *e)
{
    LNode *p = GetElem(L,i-1);
    LNode *q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return 0;
}

bool CircleELem(LinkList L)
{
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        return p;
    }
    p->next = L;
    return p;
    
}

int josephusProblem(LinkList L)
{
    LNode *p = L;

    while(p->next){
        p = p->next;  
        if (p->data == 3)
        break;    
    }   

     int m = 1;
     int n = 34;

    while (n > 0) {

        for (int i = 0; i < m - 1; i++) {// 找到要删除的节点
            if(p != NULL){
                p = p->next;
            }
            else{
                p = L;
            }   
            
        }
         
         
        printf("删除节点的数据: %d\n", p->data); // 输出数据  
        //LNode* toDelete = p;  
        p = p->next; // 移动到下一个节点    
        n--; // 总节点数减一  
        m++; // 每轮数的增加  
    }
}



 int main()
 {
    LinkList L;
    L = (LNode*)malloc(sizeof(LNode));
    InitLinkList(L);
    TailInsertLinkList(L);
    PrintLinkList(L);
    HeadInsertLinkList(L);
    PrintLinkList(L);
    TailInsertLinkList(L);
    PrintLinkList(L);
    ElemType e;
    LocalDeletElem(L,8,&e);
    PrintLinkList(L);
    HeadInsertLinkList(L);
    PrintLinkList(L);
    TailInsertLinkList(L);
    PrintLinkList(L);
    HeadInsertLinkList(L);
    PrintLinkList(L);
    HeadInsertLinkList(L);
    PrintLinkList(L);
    TailInsertLinkList(L);
    PrintLinkList(L);
    LocalDeletElem(L,23,&e);
    PrintLinkList(L);
    TailInsertLinkList(L);
    PrintLinkList(L);
    HeadInsertLinkList(L);
    PrintLinkList(L);
    printf("C\n");
    CircleELem(L);
    PrintLinkList(L);
    josephusProblem(L);


  
    return 0;


}