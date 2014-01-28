#ifndef _LIST_H
#define _LIST_H
//typdef node* nodep
struct node
{
    int data;
    struct node* next;
};
typedef struct node node;
node* get_2last(node*);
void list_init(node**);
int list_push(node**,const int*);
int pop(node**);
int length(node*);
#endif
