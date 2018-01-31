#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

nodetype* sameOrd();
nodetype* revOrd();
/*int main(){
	int ch;
	printf("Enter 0 to enter files in same order and 1 for reverse order\n");
	scanf("%d",&ch);
	nodetype* head=(nodetype*)malloc(sizeof(nodetype));
	if(ch==0){
		head=sameOrd();
	}
	else{
		head=revOrd();
	}
	return 1;
}*/

//to read integers in same order
nodetype* sameOrd(){
	nodetype* head=(nodetype*)malloc(sizeof(nodetype));
	nodetype* prev=(nodetype*)malloc(sizeof(nodetype));
	nodetype* node=(nodetype*)malloc(sizeof(nodetype));
	int n,i=1;
	FILE* file;
	file=fopen("random2.txt","r");
	head=init_l();
	fscanf(file,"%d",&n);
	head=createnode(n);
	prev=head;
	
	do{
		fscanf(file,"%d",&n);
		// if(prev->info == n)
		// break;
		if(feof(file))
			break;
		node=createnode(n);
		insert_after(node,prev);
		prev=node;
		fflush(file);	
		i++;
	}while(!feof(file));
	printf("End of file\n");
	node=head;
	while(!(node==NULL)){
		printf("%d\n",(node->info));
		node=node->next;
	}
	fclose(file);
	return head;
}

//to read integers in reverse order
nodetype* revOrd(){
	nodetype* head=(nodetype*)malloc(sizeof(nodetype));
	nodetype* prev=(nodetype*)malloc(sizeof(nodetype));
	nodetype* node=(nodetype*)malloc(sizeof(nodetype));
	int n,i=0;
	FILE* file;
	file=fopen("random2.txt","r");
	fflush(file);
	head=init_l();
	fscanf(file,"%d",&n);
	head=createnode(n);
	prev=head;

	while(!(feof(file))){
		fscanf(file,"%d",&n);
		if(feof(file))
			break;
		node=createnode(n);
		insert_front(node,&head);
		fflush(file);
	}
	printf("End of file\n");
	node=head;
	i=0;
	while(!(node==NULL)){
		printf("%d\n",(node->info));
		node=node->next;
	}
	fclose(file);
	return head;
}