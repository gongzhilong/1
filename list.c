#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#include "list.h"


/*���������б�*/
struct list* create_list()
{
    struct list* l = (struct list*)malloc(sizeof(struct list));
    l->counter = 0;
    return l;
}


/*�������*/
struct list* insert(struct list* l, int i, T e)
{   
    int j;


    if (l->counter == MAX_ELE)
    {
        return NULL;  //�б�ﵽ�洢����
    }
    else
    {
         

        for (j = l->counter; j > i; j--)
        {
            l->ele[j] = l->ele[j - 1];
        } //ͨ��ѭ����λΪҪ��������ݸ���λ��

        l->counter++;
        l->ele[i] = e;
        return l;
    } 
}


/*ɾ������*/
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


/*�������б��������*/
int size(struct list* l)
{
    return l->counter ;
}


/*����ָ��������ֵ*/
T get(struct list* l, int i)
{
    return l->ele[i];
}


/*�滻ָ��������ֵ*/
void replace(struct list* l, int i, T e)
{
    l->ele[i] = e;

}

/*�����б��е�һ������Ϊָ��ֵ������*/
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
