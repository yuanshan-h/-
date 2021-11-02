#include <stdio.h>/*该文件包含printf()等函数*/
#include <stdlib.h>/*该文件包含exit()等函数*/
#include <malloc.h>/*该文件包含malloc()等函数*/

typedef int DataType;/*定义DataType为int*/


typedef struct Node
{
    DataType data;
    struct Node *next;
} SLNode;

void ListInitiate(SLNode **head)/*初始化*/
{
/*如果有内存空间，申请头结点空间并使头指针head指向头结点*/
    if((*head = (SLNode *)malloc(sizeof(SLNode))) == NULL) 
        exit(1);
    (*head)->next = NULL;/*置链尾标记NULL */
}

int ListLength(SLNode *head)               /* 单链表的长度*/
{
    SLNode *p = head;/*p指向首元结点*/
    int size = 0;/*size初始为0*/

    while(p->next != NULL)/*循环计数*/
    {
        p = p->next;
        size ++;
    }
    return size;
}

int ListInsert(SLNode *head, int i, DataType x)
/*在带头结点的单链表head的数据元素ai（0 ≤ i ≤ size）结点前*/
/*插入一个存放数据元素x的结点*/
{
    SLNode *p, *q;
    int j;

    p = head; /*p指向首元结点*/
    j = -1;/*j初始为-1*/
    while(p->next != NULL && j < i - 1) 
/*最终让指针p指向数据元素ai-1结点*/
    {
        p = p->next;
        j++;
    }

    if(j != i - 1)
    {
        printf("插入位置参数错！");
        return 0;
    }

/*生成新结点由指针q指示*/
    if((q = (SLNode *)malloc(sizeof(SLNode))) == NULL) exit(1);
    q->data = x;

    //此段程序有一处错误
    q->next = p->next;/*给指针q->next赋值*/
    p->next = q;/*给指针p->next重新赋值*/
    return 1;
}

int ListDelete(SLNode *head, int i, DataType *x)
/*删除带头结点的单链表head的数据元素ai（0 ≤ i ≤ size - 1）结点*/
/*删除结点的数据元素域值由x带回。删除成功时返回1；失败返回0*/
{
    SLNode *p, *s;
    int j;

    p = head; /*p指向首元结点*/
    j = -1;/*j初始为-1*/
    while(p->next != NULL && p->next->next!= NULL && j < i - 1) 
/*最终让指针p指向数据元素ai-1结点*/
    {
        p = p->next;
        j++;
    }

    if(j != i - 1)
    {
        printf("删除位置参数错！");
        return 0;
    }   

//此段程序有一处错误
    s = p->next; /*指针s指向数据元素ai结点*/
    *x = s->data;/*把指针s所指结点的数据元素域值赋予x*/
    p->next = s->next;/*把数据元素ai结点从单链表中删除*/
    free(s);/*释放指针s所指结点的内存空间*/
    return 1;
}

int ListGet(SLNode *head, int i, DataType *x)
/*取数据元素ai和删除函数类同，只是不删除数据元素ai结点*/
{
    SLNode *p;
    int j;

    p = head;
    j = -1;
    while(p->next != NULL && j < i)
    {
        p = p->next;j++;
    }   

    if(j != i)
    {
        printf("取元素位置参数错！");
        return 0;
    }

//此段程序有一处错误
    *x = p->data;
    return 1;
}

void Destroy(SLNode **head)
{
    SLNode *p, *p1;

    p = *head;
    while(p != NULL)
    {
    p1 = p;
    p = p->next;
    free(p1);
    }
    *head = NULL;
}

SLNode *Combination(SLNode *head, SLNode *head2)
{
    SLNode *newhead=NULL,*p=NULL,*q=NULL,*end=NULL;
    if(head->next == NULL) 
        return head2;
    else if(head2->next ==NULL)
        return head;
    p=head->next;
    q=head2->next;
    //找到头节点
    if(head->data<head2->data)
    {
        newhead = head;
        p=p->next;
    }
    else
    {
        newhead = head2;
        q=q->next;
    }
    end=newhead->next;
    while(p&&q){
        if(p->data<q->data)
        {
            end->next=p;
            p=p->next;
        }
        else
        {
            end->next=q;
            q=q->next;
        }
        end=end->next;
    }
    if(p)
        end->next=p;
    else
        end->next=q;
    return newhead;
}

void main(void)
{
    SLNode *head,*head2,*head3;
    int i , x,y;
    ListInitiate(&head);/*初始化*/
    ListInitiate(&head2);

    for(i = 0; i < 10; i++)
    {
        if(ListInsert(head, i, i+1) == 0) /*插入10个数据元素*/
        {
            printf("错误! \n");
            return;
        }
    }
    for(i = 0; i < 10; i++)
    {
        if(ListInsert(head2, i, i+11) == 0) /*插入10个数据元素*/
        {
            printf("错误! \n");
            return;
        }
    }

    if(ListDelete(head, 4, &x) == 0) /*删除数据元素5*/
    {
        printf("错误! \n");
        return;
    }
    for(i = 0; i < ListLength(head); i++)
    {
        if(ListGet(head, i, &x) == 0) /*取元素*/
        {
        printf("错误! \n");
        return;
        }
        else printf("%d    ", x);/*显示数据元素*/
    }
    printf("\n");
    head3=Combination(head,head2);
    for(i = 0; i < ListLength(head3); i++)
    {
        if(ListGet(head3, i, &y) == 0) /*取元素*/
        {
        printf("错误! \n");
        return;
        }
        else printf("%d    ", y);/*显示数据元素*/
    }


    Destroy(&head);
    Destroy(&head3);
}