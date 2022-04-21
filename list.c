#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#include "list.h"


/*创建线性列表*/
struct list* create_list()
{
    struct list* l = (struct list*)malloc(sizeof(struct list));
    l->counter = 0;
    return l;
}


/*插入操作*/
struct list* insert(struct list* l, int i, T e)
{   
    int j;


    if (l->counter == MAX_ELE)
    {
        return NULL;  //列表达到存储上限
    }
    else
    {
         

        for (j = l->counter; j > i; j--)
        {
            l->ele[j] = l->ele[j - 1];
        } //通过循环移位为要插入的数据给出位置

        l->counter++;
        l->ele[i] = e;
        return l;
    } 
}


/*删除操作*/
struct list* delete_at(struct list* l, int i)
{
    int j;
   
    for (j = i; j < l->counter-1; j++)
    {
        l->ele[j] = l->ele[j + 1];
    }
  
    l->counter--;
    return l;
}


/*求线性列表的数据数*/
int size(struct list* l)
{
    return l->counter ;
}


/*返回指定索引的值*/
T get(struct list* l, int i)
{
    return l->ele[i];
}


/*替换指定索引的值*/
void replace(struct list* l, int i, T e)
{
    l->ele[i] = e;

}

/*返回列表中第一个数据为指定值的索引*/
int index(struct list* l, T e)
{
    int nofind = -1;
    int i;
    for (i = 0; i < l->counter; i++)
    {
        if (l->ele[i] == e) {
            nofind = i;
            break;
        }
    }
    return nofind;
}
