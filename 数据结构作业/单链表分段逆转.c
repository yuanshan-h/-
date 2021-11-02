#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;


typedef struct Node {
    ElementType Data; /* 存储结点数据 */
    struct Node *  Next; /* 指向下一个结点的指针 */
}node,*List; /* 定义单链表类型 */

List ReadInput(List L); /* 裁判实现，细节不表 */
void PrintList( List L ); /* 裁判实现，细节不表 */
List K_Reverse( List L, int K );

int main()
{
    int K;
    List L;
    L = ReadInput(L);
    PrintList( L );
    printf("\n");
    scanf("%d", &K);
    L = K_Reverse( L, K );
    PrintList( L );

    return 0;
}
List ReadInput(List L)
{   List p;
    int n;
    L=(node *)malloc(sizeof(node));
    L->Next=NULL;
    printf("please input the list's length:\n");
    scanf("%d",&n );
    
    while(n!=0){
        int a;
        printf("please input data:");
        scanf("%d",&a);
        List p=(node*)malloc(sizeof(node));
        p->Data=a;
        p->Next = L->Next;
        L->Next = p;
        n--;
    }
    return L;
}
void PrintList(List L )
{   List pr;
    pr=L->Next;
    while(pr!=NULL){
        printf("%d ",pr->Data);
        pr=pr->Next;
    }
}

/* 你的代码将被嵌在这里 */
List K_Reverse( List L, int K )
{
    int len = 0,cnt = 0;
    List  p,r,pr;
    p = L;
    pr= L->Next;
    while(K!=0)
    {
        p->Next = pr->Next;
        pr->Next = L;
        L = pr;
        pr = p->Next;
        K--;
    }
    return L;
}