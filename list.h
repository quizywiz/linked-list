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
int list_pop(node**);
int list_length(node*);
int list_delete(node**);
#endif
