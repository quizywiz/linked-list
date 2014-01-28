/*
DESCRIPTION:Linked list program for cte assignment. Has initialise, push, pop, and length operations
AUTHOR:Kailash Meiyappan
EMAIL:kailash195@gmail.com
VERSION:1.0
*/
#include "stdlib.h"
#include "list.h"
//returns next to last node, used in pushing and popping, not to be used
//otherwise
node* get_2last(node* temp)
{
    if(temp == NULL) 
        return temp;
    if(temp->next==NULL)
        return temp;
    for(;temp->next->next!=NULL;temp=temp->next)
    {
        ;
    }
    return temp;
}


void list_init(node** p)
{
    *p=NULL;
}

//adds element at end of list, returns 1 if successful, 0 otherwise
int list_push(node** p,const int* elem)
{
    if(*p==NULL)
    {
        *p = (node*)malloc(sizeof(node));
	if (*p==NULL)
	    return 0;
	else
	{
	    (*p)->data = *elem;
	    (*p)->next = NULL;
	    return 1;
	}
    }
    else
    {
        int i = 0;
	node* temp = get_2last(*p);
	if(temp->next!=NULL)
	    temp = temp->next;
	temp->next = (node*)malloc(sizeof(node));
	temp = temp->next;
	temp->data = *elem;
	temp->next = NULL;
    }    
} 

//removes element from list. returns -1 if underflow, returns element popped otherwise
int list_pop(node** p)
{
    if(*p==NULL)
        return -1;
    node* temp = get_2last(*p);
    if((*p)->next==NULL)
    {
        int sav = (*p)->data;
        free(*p);
	*p = NULL;
	return sav;
    }
    else
    {
        int sav = temp->next->data;
        free(temp->next);
	temp->next = NULL;
	return sav;
    }
}

int list_length(node* p)
{
    node* temp = p;
    if(temp==NULL)
        return 0;
    int size=1;
    for(;temp->next!=NULL;temp=temp->next)
    {
      size++;
    }
    return size;
}

int list_delete(node** p)
{
    node* temp = *p;
    while(*p!=NULL)
    {
      temp = (*p)->next;
      free(*p);
      *p = temp;
    }
    return 1;
}
