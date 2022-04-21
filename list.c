#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#include "list.h"

struct list *create_list()
{
    struct list *l = (struct list *)malloc( sizeof(struct list) );
    l->counter = 0; 
    return l;	
}
struct list *insert( struct list *l, int i, T e ) {	
	int j;

    if( l->count == MAX_ELE ) return NULL;
	assert( i >= 0 && i <= l->count );

	for( j=l->count; j>i; j-- ) {
		l->ele[j] = l->ele[j-1];
	}

	l->count ++;
	
	l->ele[i] = e;
	
	return l;
}
