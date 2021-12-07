#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define Stack_Size 1000

char cmp[7][8]= {">><<<>>",">><<<>>",">>>><>>",">>>><>>","<<<<<=?",">>>>?>>","<<<<<?="};

typedef struct{//����һ�������ջ
    char Elem[Stack_Size];
    int top;
}Opter;

typedef struct{//����һ��������ջ
    double Elem[Stack_Size];
    int top;
}Opnd;



void InitOpter(Opter *S){//��ʼ�������ջ
    S->top=-1;
}
void InitOpnd(Opnd *S){//��ʼ��������ջ
    S->top=-1;
}

int PopOpter(Opter *S)//���������ջ
{
    if(S->top==-1)
    {
        printf("�����ջΪ��\n");
        exit(1);
    }
    S->top--;
    return 1;
}

int PopOpnd(Opnd *S)
{
    if(S->top==-1)
    {
        printf("�����ջΪ��\n");
        exit(1);
    }
    S->top--;
    return 1;
}

int PushOpter(Opter* S,char ch)
{
    if(S->top==Stack_Size-1)
    {
        printf("�����ջ��\n");
        exit(1);
    }
    S->top++;
    S->Elem[S->top]=ch;
    return 1;
}

int PushOpnd(Opnd* S,double ch)//�������ջ
{
    if(S->top==Stack_Size-1)
    {
        printf("�����ջ��\n");
        exit(1);
    }
    S->top++;
    S->Elem[S->top]=ch;
    return 1;
}

char GetOpter(Opter *S)//��ȡ�����ջ��ջ��Ԫ��
{
    if(S->top==-1)
    {
        printf("�����ջΪ��\n");
        exit(1);
    }
    return S->Elem[S->top];
}

double GetOpnd(Opnd *S)
{
    if(S->top==-1)
    {
        printf("������ջΪ��\n");
        exit(1);
    }
    return S->Elem[S->top];
}

double Calc(double a,double b,char opt)//���㺯���������������Լ�һ�������
{
    double T;   //T���ڴ�ż���ó��Ľ��
    if(opt=='+') T=a+b;
    if(opt=='-') T=a-b;
    if(opt=='*') T=a*b;
    if(opt=='/')     //Ҫ��ֹ������0����
    {
        if(fabs(b)<0.00001)
        {
            printf("������0����\n");
            exit(15);
        }
        T=a/b;
    }
    printf(" %.2lf %c %.2lf = %.2lf\n",a,opt,b,T);
    return T;    //���صõ��Ľ��
}

int change(char ch)
{
    switch(ch)
    {
    case '+':
        return 0;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 3;
    case '(':
        return 4;
    case ')':
        return 5;
    case '#':
        return 6;
    }
}

int Compare(char ch1,char ch2)
{
    if(cmp[change(ch1)][change(ch2)]=='?'){
        printf("������ʽ����");
        exit(16);
    }
    return cmp[change(ch1)][change(ch2)];
}

int Check(char *S,int len)//��麯�����ǵÿ��������С��������ֵ����
{
    int i;
    for(i=0;i<len;i++){
        if(S[i]>='0'&&S[i]<='9')continue;
        if(S[i]=='('||S[i]==')'||S[i]=='*'||S[i]=='/'||S[i]=='+'||S[i]=='-'||S[i]=='.'||S[i]=='#')continue;
        return 0;
    }
    return 1;
}

int main()
{
    char a[1000],b[1000];         //�����������飬a������������ı��ʽ�ģ�b���������������

    int len;        //lenΪ������ʽ�ĳ��ȣ�ͨ��strlen���
    Opter S;    //����һ�������ջ
    Opnd N;    //����һ��������ջ
    InitOpnd(&N);   //��ʼ��������ջ
    InitOpter(&S);   //��ʼ�������ջ

    PushOpter(&S,'#');
     //ע��������������������ջ��ѹ��һ��'#'����������ʽ���ڱ��ʽ���������һ��λ��Ҳ��Ϊ'#'��
     //֮�����������ʱ������#��������ȽϺ�������'='��ʹ�����յ��������

    printf("������ʽ��\n");
    scanf("%s",a);    //������ʽ��ע������a����ȡ��ַ��&����Ϊ������ʵ����һ����ַ�����������������һ��Ԫ�ص��׵�ַ��a��ʵ����&a[0]

    len=strlen(a);   //������ı��ʽ�ĳ��ȣ�����ӡ����
    //printf("�ַ�����Ϊ%d\n",len);

    if(Check(a,len)==0)   //����Ƿ��������һЩ����ֵֹĶ���
    {
        printf("�����д��ڶ����ַ�\n");
        exit(1);
    }

    int i,j=0,k=0;
    double x,y;  //x,y�ǴӲ�������ȡ���������������ڼ������
    a[len]='#';  //ע��
    for(i=0;i<=len;i++)  //������������ı��ʽ
    {
        if((a[i]>='0'&&a[i]<='9')||a[i]=='.')//���Ϊ����
        {
            b[k++]=a[i];//�����ִ�������b�У�ע���ʱ������Ϊ�ַ�
            j=1;
            continue;  //�ڸ�ѭ�������ಿ�ֶ������ˣ�ֱ�ӽ�����һ��xunh
        }
        if(j)//�����ɹ��������������ַ�����������ѹ�������ջ��
        {
            //��ʱ����b�Ѿ�����һ�����߼������������棬��Ҫ��һ��'\0'ʹ���Ϊ�ַ���
            //��ͨ��atof����ʹ�����ַ��ͱ�Ϊ˫�����ͣ�Ȼ����������ջ�н�����Ӧ����
            b[k]='\0';
            PushOpnd(&N,atof(b));//atof��������ʹchar��Ϊdouble
            j=0;
            k=0;  //k����Ϊ��һ�μ�����׼��
        }
        switch(Compare(GetOpter(&S),a[i]))//�Ƚ������ջ��ջ�������top�������a[i]�����ȼ�
        { //���µĲ������ǰ���֮ǰ���Ĺ�����д

        case '<'://��top<a[i]����a[i]ֱ����ջOpter
            PushOpter(&S,a[i]);
            break;
        case'=':
            PopOpter(&S);
            break;
        case'>':
        //��Ϊ��>'�����������Ҫ�������㣬��ȡ������ջ�������������Ԫ��
            y=GetOpnd(&N),PopOpnd(&N);
            x=GetOpnd(&N),PopOpnd(&N);
            //Ȼ�󽫼�����ѹ�������ջ��
            PushOpnd(&N,Calc(x,y,GetOpter(&S)));
            //�Ѿ��ù���������ͷϵ��ˣ�����������
            PopOpter(&S);

            i--;//�����Ϊ�����°ѷ�������ջ��ʹ֮����������ԣ��������������Ŷ������
            break;
        }
    }
    double answer=GetOpnd(&N);//���ղ�����ջ�е�������������Ҫ�Ľ��
        printf("���ս��Ϊ%.2lf",answer);
        return 0;

}