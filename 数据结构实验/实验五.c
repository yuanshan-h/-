#include <stdlib.h>
#include <stdio.h>

typedef char DataType;

typedef struct Node
{
    DataType data;/*������*/
    struct Node *leftChild;/*������ָ��*/
    struct Node *rightChild;/*������ָ��*/
} BiTreeNode; /*���Ľṹ�嶨��*/

/*��ʼ��������������ͷ���*/
void Initiate(BiTreeNode **root)
{
    *root = (BiTreeNode *)malloc(sizeof(BiTreeNode));
    (*root)->leftChild = NULL;
    (*root)->rightChild = NULL;
}

void Destroy(BiTreeNode **root)
{
    if((*root) != NULL && (*root)->leftChild != NULL)
        Destroy(&(*root)->leftChild);

    if((*root) != NULL && (*root)->rightChild != NULL)
        Destroy(&(*root)->rightChild);

    free(*root);
}

/*����ǰ���curr�ǿգ���curr������������Ԫ��ֵΪx���½��*/
/*ԭcurr��ָ������������Ϊ�²������������*/
/*������ɹ������²������ָ�룬���򷵻ؿ�ָ��*/
BiTreeNode *InsertLeftNode(BiTreeNode *curr, DataType x)
{
    BiTreeNode *s, *t;
    if(curr == NULL) return NULL;

    t = curr->leftChild;/*����ԭcurr��ָ����������ָ��*/
    s = (BiTreeNode *)malloc(sizeof(BiTreeNode));
    s->data = x;
    s->leftChild = t;/*�²������������Ϊԭcurr��������*/
    s->rightChild = NULL;

    curr->leftChild = s;/*�½���Ϊcurr��������*/
    return curr->leftChild;/*�����²������ָ��*/
}

/*����ǰ���curr�ǿգ���curr������������Ԫ��ֵΪx���½��*/
/*ԭcurr��ָ������������Ϊ�²������������*/
/*������ɹ������²������ָ�룬���򷵻ؿ�ָ��*/
BiTreeNode *InsertRightNode(BiTreeNode *curr, DataType x)
{
    BiTreeNode *s, *t;

    if(curr == NULL) return NULL;

    t = curr->rightChild;/*����ԭcurr��ָ����������ָ��*/
    s = (BiTreeNode *)malloc(sizeof(BiTreeNode));
    s->data = x;
    s->rightChild = t;/*�²������������Ϊԭcurr��������*/
    s->leftChild = NULL;

    curr->rightChild = s;/*�½���Ϊcurr��������*/
    return curr->rightChild;/*�����²������ָ��*/
}



void PreOrder(BiTreeNode *t, void visit(DataType item))
//ʹ��visit(item)����ǰ�����������t
{
    if(t != NULL)
    {
        //��С����һ������  �Ѹ�
        visit(t->data);
        PreOrder(t-> leftChild, visit);
        PreOrder(t-> rightChild, visit);
    }
}

void InOrder(BiTreeNode *t, void visit(DataType item))
//ʹ��visit(item)�����������������t
{
    if(t != NULL)
    {
        //��С����һ������ �Ѹ�
        InOrder(t->leftChild, visit);
        visit(t->data);
        InOrder(t->rightChild, visit);
    }
}

void PostOrder(BiTreeNode *t, void visit(DataType item))
//ʹ��visit(item)�����������������t
{
    if(t != NULL)
    {
        //��С����һ������  �Ѹ�
        PostOrder(t->leftChild, visit);
        PostOrder(t->rightChild, visit);
        visit(t->data);
    }
}


void Visit(DataType item)
{
    printf("%c ", item);
}

BiTreeNode *Search(BiTreeNode *root, DataType x)//����Ԫ��x�Ƿ��ڶ�������
{
    BiTreeNode *find=NULL;
    if(root!=NULL)
    {
        if(root->data==x)
            find=root;
        else
        {
            find=Search(root->leftChild,x);
            if(find==NULL)
                find=Search(root->rightChild,x);
        }
    }
    return find;
}

int main()
{
    BiTreeNode *root, *p, *pp,*find;
    char x='E';

    Initiate(&root);
    p = InsertLeftNode(root, 'A');
    p = InsertLeftNode(p, 'B');
    p = InsertLeftNode(p, 'D');
    p = InsertRightNode(p, 'G');
    p = InsertRightNode(root->leftChild, 'C');
    pp = p;
    InsertLeftNode(p, 'E');
    InsertRightNode(pp, 'F');

    printf("ǰ�������");
    PreOrder(root->leftChild, Visit);
    printf("\n���������");
    InOrder(root->leftChild, Visit);
    printf("\n���������");
    PostOrder(root->leftChild, Visit);

    find=Search(root,x);
    if(find!=NULL)
        printf("\n����Ԫ��%c�ڶ������� \n",x);
    else
        printf("\n����Ԫ��%c���ڶ������� \n",x);

    Destroy(&root);

}

