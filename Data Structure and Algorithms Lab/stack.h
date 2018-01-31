#include<stdio.h>
#include<stdlib.h>
#define MAXSTK 1024

struct stack_t{
	int top;
	int stk[MAXSTK];
};

typedef struct stack_t * stack;

//Function to initialise stack 
stack init_stack(){
	stack s;
	if ((s = (stack) malloc(sizeof (struct stack_t)))== NULL)
	{
		printf("Memory allocation error\n");
		exit(0);
	}
	s->top=-1;
	return s;
}

//Function to dispose a stack
void s_dispose(stack s){
	if(s!=NULL)
		free(s);
}


//Function to check for empty stack
int s_empty(stack s){
	return (s->top==-1);
} 

//Function to check whether stack is full
int s_full(stack s){
	return (s->top==MAXSTK-1);
}

//Function to push an item into stack
void push(stack s,int e){
	if(!s_full(s))
		s->stk[++s->top]=e;
	else
		printf("Stack overflow\n");
}

//Function to pop item from stack 
int pop(stack s){
	if(!s_empty(s))
		return s->stk[s->top--];
	else{
		printf("Stack underflow\n");
	}
}

void prints(stack s)
{
	int i;
	for(i=0;i<s->top;i++)
	{
		printf("#%d\t",s->stk[i]);
	}
	printf("\n");
}
