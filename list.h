#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
#include <stdio.h>

typedef struct list list;
struct list
{
    list *next;
    void *data;
};

void add_list(void *, list*,int);
void remove_list(list *, int);
list* newlist();
void destroy_list(list*);
void* get_list(list*, int);

#endif