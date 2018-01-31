#include <stdio.h>
#include <stdlib.h> 


typedef struct nodetag{
    int info;
    struct nodetag *next;
} nodetype;

//some useful variables
//nodetype *head, *cur, *prev, *next, *target;

//create new node
nodetype* createnode(int val){
    //printf("%d\n",val);
    nodetype* head=NULL;
    //printf("Hi\n");

    if((head=(nodetype*)malloc(sizeof(nodetype)))==NULL)
        perror("Malloc error\n");
    else{
        head->info=val;
        head->next=NULL;
    }
    return head;
}

//initialize a list
nodetype* init_l(){
    return NULL;
}

//checks if list is empty
int empty_l(nodetype* head){
    return (head==NULL);
}

//checks if node cur is at the end of list
int atend_l(nodetype* cur) {
    if(cur==NULL)
        return 0;
    else
        return ((cur->next)==NULL);
}

//inserting node target at the front of the list
void insert_front(nodetype* target,nodetype** head){
    target->next=*head;
    *head = target;
}

//inserting a node after prev
void insert_after(nodetype* target, nodetype* prev){
    target->next=prev->next;
    prev->next=target;
}

//deleting the first node of the list
int delete_front(nodetype** head) {
    int retval = -1;
    nodetype* next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->info;
    free(*head);
    *head = next_node;

    return retval;
}


//deleting the node after prev
int delete_after(nodetype* prev){
    int retval = 0;
    //if no element after prev
    if(prev->next==NULL){
        printf("No element after %d\n",(prev->info));
    }
    else{
        nodetype* temp;
        temp=prev->next;
        prev->next=temp->next;
        retval=temp->info;
        free(temp);
    }
    return retval;
}


