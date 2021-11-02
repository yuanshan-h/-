#include<stdio.h>
#include<stdlib.h>
#include"sp_queue.h"


sp_queue queue_init()
{
    sp_queue q;
    q.front = q.rear =0;
    return q;
}

int queue_empty(sp_queue q)
{
    return q.front == q.rear;
}
int queue_insert(sp_queue *q,datatype e)
{
    if(q->rear == MAX_QUEUE_SIZE)
        return false;
    q->sp_queue_array[q->rear] = e;
    q->rear+=1;
    return true;
}

int queue_remove(sp_queue *q,datatype *e)
{
    if(queue_empty(*q))
        return false;
    *e =q->sp_queue_array[q->front];
    q->front+=1;
    return true;
    /*q -> rear -= 1;
    *e = q -> sp_queue_array[q -> rear];
    return true;*/
}
void queue_clear(sp_queue *q)
{
    q->front=q->rear=0;
}

int get_front(sp_queue *q,datatype *e)
{
    if(queue_empty(*q))
        return false;
    *e=q->sp_queue_array[q->front];
    return true;
}
int queue_length(sp_queue *q)
{
    return (q->rear-q->front);
}

void queue_traverse(sp_queue q,void(*visit)(sp_queue q))
{
    visit(q);
}

void visit(sp_queue q)
{
    if(q.front == q.rear)
        printf("This queue is empty");
    int temp =q.front;
    while(temp != q.rear)
    {
        printf("%d",q.sp_queue_array[temp]);
        temp+=1;
    }
    printf("\n");
}

int main()
{
    sp_queue q = queue_init();
    queue_insert(&q, 1);
    queue_insert(&q, 2);
    printf("length=%d\n", queue_length(&q));
    queue_insert(&q, 3);
    printf("length=%d\n", queue_length(&q));
    queue_insert(&q, 4);
    printf("length=%d\n", queue_length(&q));
    queue_insert(&q, 5);
    printf("length=%d\n", queue_length(&q));
    queue_insert(&q, 6);
    printf("length=%d\n", queue_length(&q));
    queue_traverse(q,visit);
    datatype *e = (datatype *)malloc(sizeof(*e));
    queue_remove(&q,e);
    printf("queue_remove(),e=%d length=%d\n", *e, queue_length(&q));
    queue_traverse(q, visit);
    queue_clear(&q);
    queue_traverse(q, visit);
    printf("length:%d\n", queue_length(&q));
}