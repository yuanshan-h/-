/*给定一段程序代码，程序代码所完成的功能为：（1）建立一个线性表；（2）依次输入数据元素1,2,3,4,5,6,7,8,9,10；（3）删除数据元素5；（4）依次显示当前线性表中的数据元素。假设该线性表的数据元素个数在最坏情况下不会超过100个，要求使用顺序表。
程序中有3处错误的地方，有标识，属于逻辑错误，对照书中的代码仔细分析后，要求同学们修改错误的代码，修改后上机调试得到正确的运行结果。
实验任务
1.改正上述程序中的错误。
2.编写合并函数，将两个有序线性表合并为一个有序表并在主函数中加以测试。*/


#include <stdio.h>
#define MaxSize  10010
typedef int DataType;

typedef struct
{
    DataType list[MaxSize];
    int size;
} SeqList;

void ListInitiate(SeqList *L)/*初始化顺序表L*/
{
    L->size = 0;/*定义初始数据元素个数*/
}
 
int ListLength(SeqList L)/*返回顺序表L的当前数据元素个数*/
{
    return L.size;
}
int ListInsert(SeqList *L, int i, DataType x) 
/*在顺序表L的位置i（0 ≤ i ≤ size）前插入数据元素值x*/ 
/*插入成功返回1，插入失败返回0*/
{
    int j;
    if(L->size >= MaxSize)
    {
        printf("顺序表已满无法插入! \n");
        return 0;
    }
    else if(i < 0 || i > L->size )
    {
        printf("参数i不合法! \n");
        return 0;
    }
    else
    { //此段程序有一处错误
        for(j = L->size; j >= i; j--) 
            L->list[j+1] = L->list[j];/*为插入做准备*/
        L->list[i] = x;/*插入*/
        L->size ++;/*元素个数加1*/
        return 1;
    }
}
int ListDelete(SeqList *L, int i, DataType *x)
/*删除顺序表L中位置i（0 ≤ i ≤ size - 1）的数据元素值并存放到参数x中*/
/*删除成功返回1，删除失败返回0*/
{
    int j;
    if(L->size <= 0)
    {
        printf("顺序表已空无数据元素可删! \n");
        return 0;
    }
    else if(i < 0 || i > L->size-1)
    {
        printf("参数i不合法");
        return 0;
    }
    else
    {//此段程序有一处错误

        *x = L->list[i];/*保存删除的元素到参数x中*/
        for(j = i +1; j <= L->size-1; j++) 
            L->list[j-1] = L->list[j];/*依次前移*/
        L->size--;/*数据元素个数减1*/
        return 1;
    }
}
int ListGet(SeqList L, int i, DataType *x)
/*取顺序表L中第i个数据元素的值存于x中，成功则返回1，失败返回0*/
{
    if(i < 0 || i > L.size-1)
    {
        printf("参数i不合法! \n");
        return 0;
    }
    else
    {
    *x = L.list[i];
    return 1;
    }
}
void Combination(SeqList *L1, SeqList *L2,SeqList *L3)  //将两个有序表连接成一个有序表
{
    int i=0,j=0,k=0;
    while((i!=L1->size)&&j!=L2->size)   
    {
        if(L1->list[i]>L2->list[j])   //比较两个顺序表中元素的大小，将值较小的元素先放入
        {
            L3->list[k]=L2->list[j];
            k++;
            j++;
        }
        else{
            L3->list[k]=L1->list[i];
            k++;
            i++;
        }
        L3->size ++;
    }
    //第一个while结束后两个顺序表中必有一个有剩余，在将其按顺序放入L3中即可
    while(i<L1->size)
    {
        L3->list[k] = L1->list[i];
        k++;
        i++;
        L3->size ++;
    }
    while(j<L2->size)
    {
        L3->list[k] = L2->list[j];
        k++;
        j++;
        L3->size ++;
    }
}
void main(void)
{ 
    SeqList L1,L2,L3;
    int i ,j , x,y;
    ListInitiate(&L1);
    ListInitiate(&L2);
    ListInitiate(&L3);
    for(i = 0; i < 10; i++) 
        ListInsert(&L1, i, i+1); 
    for(j = 0; j < 10; j++) 
        ListInsert(&L2, j, j+11); 
    ListDelete(&L1, 4, &x);
    Combination(&L1,&L2,&L3);
    for(i = 0; i < ListLength(L1); i++)
    {
        ListGet(L1,i,&x); //此段程序有一处错误        
        printf("%d ", x);
    }
    printf("\n");
      for(i = 0; i < ListLength(L2); i++)
    {
        ListGet(L2,i,&x);        
        printf("%d ", x);
    }
    printf("\n");
    for(j = 0;j< ListLength(L3);j++){
        ListGet(L3,j,&y);
        printf("%d ", y);
    }
}