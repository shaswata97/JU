#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

void sameOrd();
void revOrd();
int main(){
	int ch;
	printf("Enter 0 to enter files in same order and 1 for reverse order\n");
	scanf("%d",&ch);
	if(ch==0){
		sameOrd();
	}
	else{
		revOrd();
	}
	return 1;
}

//to read integers in same order
void sameOrd(){
	nodetype* head=(nodetype*)malloc(sizeof(nodetype));
	nodetype* prev=(nodetype*)malloc(sizeof(nodetype));
	nodetype* node=(nodetype*)malloc(sizeof(nodetype));
	int n,i=0;
	FILE* file;
	file=fopen("random2.txt","r");
	head=init_l();
	fscanf(file,"%d",&n);
	head=createnode(n);
	prev=head;
	
	while(!(feof(file))){
		fscanf(file,"%d",&n);
		printf("%d %d\n",++i,n);
		node=createnode(n);
		printf("chk1\n");
		insert_after(node,prev);
		prev=node;
		
	}
	printf("End of file\n");
	node=head;
	while(!(node->next==NULL)){
		printf("%d\n",(node->info));
		node=node->next;
	}
	fclose(file);
}

//to read integers in reverse order
void revOrd(){
	nodetype* head=(nodetype*)malloc(sizeof(nodetype));
	nodetype* prev=(nodetype*)malloc(sizeof(nodetype));
	nodetype* node=(nodetype*)malloc(sizeof(nodetype));
	int n,i=0;
	FILE* file;
	file=fopen("random2.txt","r");
	head=init_l();
	fscanf(file,"%d",&n);
	head=createnode(n);
	prev=head;

	while(!(feof(file))){
		fscanf(file,"%d",&n);
		node=createnode(n);
		insert_front(node,&head);
	}
	printf("End of file\n");
	node=head;
	while(!(node==NULL)){
		printf("%d\n",(node->info));
		node=node->next;
	}
	fclose(file);
}