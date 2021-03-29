#include "list.h"

void add_list(void* v,list* l,int i){
    list *l2 = l;
    list *l3 = malloc(sizeof(list));

    if (i == -1)
        i = -2;
    while((i>=0 || i <= -2) && l2 -> next != NULL){
        i--;
        l2 = l2 -> next;
    }
    l3 -> data = v;
    l3 -> next = l2 -> next;
    l2 -> next = l3;
    int j = *((int *)(l -> data))+1;
    *((int*)(l -> data)) = j; 
}

void remove_list(list* l,int i){
    list *l2 = l;
    list *l3;
    while((i>0 || i == -2)&& l2 -> next -> next != NULL){
        i--;
        l2 = l2 -> next;
    }
    int j = *((int *)(l -> data))-1;
    *((int*)(l -> data)) = j;
    l3 = l2 -> next;
    l2 -> next = l3 -> next;
    free(l3 -> data);
    free(l3);
}

list* newlist(){
    list* l = malloc(sizeof(list));
    int *i = malloc(sizeof(int));
    *i = 0;
    l -> data = i;
    l -> next = NULL;
    return l;
}

void destroy_list(list* l){
    if(l != NULL){
        destroy_list (l -> next);
    }
    free(l -> data);
    free(l);
}

void* get_list(list* l, int i){
    list *l2 = l;
    while(i >= 0 && l2 -> next != NULL){
        i--;
        l2 = l2 -> next;
    }
    return l2 -> data;
}

void main(){
    list *liste = newlist();
    char *b = malloc(8 * sizeof(char));
    b = "bonjour";
    int *j = malloc(sizeof(int));
    *j = 25;
    char *c = malloc(sizeof(char));
    *c = 'w';
    printf("hello\n");
    add_list(j,liste, 0);
    printf("check : 2\n");
    add_list(b,liste,-2);
    printf("check : 1\n");
    add_list(c,liste, 2);
    printf("check : 3\n");
    printf("The first data is : %i\nThe second one is : %s\nAnd the third one is : %c\n", *((int*)(get_list(liste,0))), (char*)(get_list(liste,1)), 
        *((char*)(get_list(liste,2))));
    printf("The number of elements in this list is : %i\n",*((int*)(liste -> data)));

    remove_list(liste,4);
    printf("The first data is : %i\nAnd the second one is : %c\n", *((int*)(get_list(liste,0))), *((char*)(get_list(liste,1))));
    printf("The number of elements in this list is : %i\n",*((int*)(liste -> data)));
}