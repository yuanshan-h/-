#define true 1
#define false 0

#define MAX_QUEUE_SIZE 100 //队的最大长度

typedef int datatype; //队列的数据类型

/* 静态链的数据结构*/
typedef struct queue{
    datatype sp_queue_array[MAX_QUEUE_SIZE];
    int front;  //对头
    int rear;   //队尾
}sp_queue;

/*静态链的初始化*/
sp_queue queue_init();


/*
 *判断队列是否空
 *若为空返回 true
 *否则返回 false
*/
int queue_empty(sp_queue q);

/*插入元素e为对q的队尾新元素
 *插入成功返回 true
 *插入失败返回 false
*/
int queue_insert(sp_queue *q, datatype e);

/*队头元素出对
 *用e返回出队元素并返回true
 *否则返回false
*/
int queue_remove(sp_queue *q,datatype *e);

/*清空对*/
void queue_clear(sp_queue *q);

/*获得对头元素
 *队列非空，用e返回队头元素，并返回true
 *否则返回false
*/
int get_front(sp_queue *q,datatype *e);

/*获得对长*/
int queue_length(sp_queue *q);

/*遍历对*/
void queue_traverse(sp_queue q,void(*visit)(sp_queue q));
void visit(sp_queue s);