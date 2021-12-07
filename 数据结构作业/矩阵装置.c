#define SMAX 1000
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//三元组方法

typedef struct{
    int i,j,v;
}SPNode;
typedef struct
{
    int col,row,num;
    SPNode data[SMAX];
}SPMatrix;


SPMatrix *create(int a[4][3])
{
    SPMatrix *A;
    A=malloc(sizeof(SPMatrix));
    int i,j;
    
    A->col=4,A->row=3,A->num=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            if(a[i][j]!=0)
            {
                A->data[A->num].i=i;
                A->data[A->num].j=j;
                A->data[A->num].v=a[i][j];
                A->num++;
            }
        }
    }
    return A;
}
SPMatrix *transform(SPMatrix *A)
{
    SPMatrix *B;
    int p,q,col;
    B=malloc(sizeof(SPMatrix));
    B->col = A->row;
    B->row = A->col;
    B->num = A->num;
    if(B->num !=0)
    {
        q=0;
        for(col = 1; col<=(A->num);col++)
        {
            for(p=1;p<=(A->num);p++)
            {
                B->data[q].i=A->data[q].j;
                B->data[q].j=A->data[q].i;
                B->data[q].v=A->data[q].v;
                q++;
            }
        }
    }
    return B;
}
void show(SPMatrix *B) {
	int i;
	if (B->num <= 0) {
		printf("is null\n");
		return;
	}
    printf("row col value\n");
	for ( i = 0; i < B->num; i++) {
		printf("%3d%3d%3d\n", B->data[i].i, B->data[i].j, B->data[i].v);
	}
}
int main()
{   clock_t t1,t2;
    t1=clock();
	int a[4][3] = { {1,0,0},{0,0,4},{3,0,0},{5,0,0}};
    SPMatrix *t,*B;
    t=create(a);
    B=transform(t);
    printf("Before transform:\n");
    show(t);
    printf("After transform:\n");
    show(B);
    t2= clock();
    printf("\n%f",(t2-t1));
}
/*
//二维数组方法
int main()
{
	int a[4][3] = { {1,0,0},{0,0,4},{3,0,0},{5,0,0}};
    int b[3][4];
    int i,j;
    for (i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            b[j][i]=a[i][j];
        }
    }
    printf("Before transform:\n");
    for (i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%3d",b[i][j]);
        }
        printf("\n");
    }
    printf("After transform:\n");
    for (i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%3d",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}*/