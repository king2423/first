#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define initsize 100
//顺序表实现-动态分配
typedef struct
{
    int* data;
    int length;//顺序表当前长度
    int maxsize;//顺序表最大长度
}Sqlist;
//构造一个空的顺序表
void Initsqlist(Sqlist* l)
{
    l->data=(int*)malloc(sizeof(int)*initsize);
    l->length=0;
    l->maxsize=initsize;
}
//输入顺序表元素
void inputsqlist(Sqlist* l)
{
    printf("请输入顺序表的元素个数：");
    scanf("%d",&l->length);
    printf("请输入顺序表的元素大小：");
    for(int i=0;i<l->length;i++)
    {
        scanf("%d",&l->data[i]);
    }
}
//插入操作 在l的第i个位置插入新元素e
bool Insertsqlist(Sqlist* l,int i,int e)
{
    if(l->length>=l->maxsize)
    {
        return false;
    }
    if(i<1||i>l->length+1)//i的合理范围为[1,length+1]
    {
        return false;
    }
    for(int j=l->length;j>=i;j--)
    {
        l->data[j]=l->data[j-1];
    }
    l->data[i-1]=e;
    l->length++;
    return true;
}
//删除操作 删除l的第i个位置元素
bool Deletesqlist(Sqlist* l,int i,int* e)
{
    if(i<1||i>l->length)
    {
        return false;
    }
    if(l->length==0)
    {
        return false;
    }
    *e=l->data[i-1];
    for(int j=i;j<l->length;j++)
    {
        l->data[j-1]=l->data[j];
    }
    l->length--;
    return true;
}
//输出顺序表元素
void outputsqlist(Sqlist* l)
{
    for(int i=0;i<l->length;i++)
    {
        printf("顺序表第%d个元素大小=%d\n",i+1,l->data[i]);
    }
}
int main(void)
{
    Sqlist* l=(Sqlist*)malloc(sizeof(Sqlist));
    Initsqlist(l);
    inputsqlist(l);
    outputsqlist(l);
    Insertsqlist(l,3,100);
    printf("插入后的顺序表为：\n");
    outputsqlist(l);
    int e=-1;
    Deletesqlist(l,1,&e);
    printf("删除的大小为：%d\n",e);
    outputsqlist(l);
    return 0; 
}
hhh
www
