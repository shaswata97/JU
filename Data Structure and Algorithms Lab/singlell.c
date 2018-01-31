#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arrange.h"

int searchUnOrd(nodetype* head,int n);
int searchOrd(nodetype* head,int n);
int size(nodetype* head);
int equal(nodetype* head1,nodetype* head2);
void printSame(nodetype* head);
void printRev(nodetype* head);
void append(nodetype* head1,nodetype* head2);
int deleteN(nodetype* head, int n);
int deleteLast(nodetype* head);
int deleteFirst(nodetype* head);
int checkSort(nodetype* head);
void mergeSorted(nodetype** head1, nodetype* head2);
void swap(nodetype* head);
void last2front(nodetype** head);
void delAlt(nodetype* head);
void delList(nodetype** head);
void delDuplicateSort(nodetype* head);
void delDuplicateUnsort(nodetype* head);
nodetype* rotate(nodetype* head, int n);
nodetype* reverse(nodetype* head);
void insertBegUnsort(nodetype** head,nodetype* target);
void insertMidUnsort(nodetype* head,nodetype* target,nodetype* prev);
void insertEndUnsort(nodetype* head,nodetype* target);
void insertBegSort(nodetype** head,nodetype* target);
void insertMidSort(nodetype* head,nodetype* target,nodetype* prev);
void insertEndSort(nodetype* head,nodetype* target);

int main(){
	nodetype* head1=(nodetype*)malloc(sizeof(nodetype));
	nodetype* head2=(nodetype*)malloc(sizeof(nodetype));
	head1=sameOrd();
	printf("Input done\n");
	printSame(head1);
	nodetype* temp=createnode(0);
	insert_front(temp,&head1);
	printSame(head1);
	printf("printing done\n reversing\n");
	/*head2=sameOrd();
	printSame(head2);
	printf("Done\n");*/
	/*nodetype* head3=(nodetype*)malloc(sizeof(nodetype));
	printf("Size of list = %d\n",size(head1));
	printf("Size of list = %d\n",size(head2));
	if(equal(head1,head2)==1){
		printf("Lists are same\n");
	}
	else
		printf("Lists are different\n");
	printSame(head1);
	printf("\n");
	printRev(head1);
	append(head1,head2);
	printf("\n");
	printSame(head1);
	printf("size = %d\n",size(head1));*/
	head1=reverse(head1);
	printSame(head1);
	head1=rotate(head1,3);
	printSame(head1);
	last2front(&head1);
	printSame(head1);
	swap(head1);
	printSame(head1);
	mergeSorted(&head1,head2);
	printSame(head1);
	printSame(head2);
	printf("\n\n%d\n",checkSort(head2));
	temp=createnode(10);
	insertEndSort(head2,temp);
	printSame(head2);
	delDuplicateUnsort(head1);
	printSame(head1);
}

//searching and deleting an element in an unordered list
int searchUnOrd(nodetype* head,int n){
	if(head==NULL){
		printf("List empty\n");
		return -999;
	}
	else{
		int i=0;
		nodetype* prev=(nodetype*)malloc(sizeof(nodetype));
		nodetype* temp=(nodetype*)malloc(sizeof(nodetype));
		temp=head;
		prev=createnode(0);
		prev->next=head;
		while(temp->next!=NULL){
			i++;
			if(temp->info==n){
				printf("Search found at %d position\n",i);
				delete_after(prev);
				free(prev);
				free(temp);
				return n;
			}
			prev=temp;
			temp=temp->next;
		}
		free(prev);
		free(temp);
		printf("Search not found\n");
		return -999;
	}
}

//size of list
int size(nodetype* head){
	int count=0;
	nodetype* temp=(nodetype*)malloc(sizeof(nodetype));	
	temp=head;
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	free(temp);
	return count;
}

//to check equality of 2 lists
int equal(nodetype* head1, nodetype* head2){
	int s1=size(head1);
	int s2=size(head2);
	if(s1==s2){
		nodetype* temp1=(nodetype*)malloc(sizeof(nodetype));	
		temp1=head1;
		nodetype* temp2=(nodetype*)malloc(sizeof(nodetype));	
		temp2=head2;
		while(temp1!=NULL){
			if(temp1->info!=temp2->info)
				return 0;
			temp1=temp1->next;
			temp2=temp2->next;
		}
		free(temp1);
		free(temp2);
		return 1;
	}
	else
		return 0;
}

//printing the list in same order
void printSame(nodetype* head){
	nodetype* temp=(nodetype*)malloc(sizeof(nodetype));	
	temp=head;
	while(temp!=NULL){
		printf("%d  ",temp->info);
		temp=temp->next;
	}
	printf("\n");
}

//printing the list in reverse order
void printRev(nodetype* head){
	nodetype* temp=(nodetype*)malloc(sizeof(nodetype));	
	temp=head;
	if(temp==NULL){
		return;
	}
	else{
		printRev(temp->next);
		printf("%d  ",temp->info);
	} 
	printf("\n");
}

void append(nodetype* head1,nodetype* head2){
	nodetype* temp=head1;
	while((temp)->next!=NULL){
		(temp)=(temp)->next;
	}
	(temp)->next=head2;
}

int deleteN(nodetype* head, int n){
	int i=2,res;
	if(n<1 || n>size(head)){
		printf("Invalid index\n");
		return -999;
	}
	else{
		nodetype* prev=(nodetype*)malloc(sizeof(nodetype));	
		prev=head;
		while(i<n){
			prev=prev->next;
			i++;
		}
		res=delete_after(prev);
		free(prev);
		return res;
	}
}

int deleteLast(nodetype* head){
	int n=deleteN(head,size(head));
	return n;
}

int deleteFirst(nodetype* head){
	int n=deleteN(head,1);
	return n;
}

//to check if the list is sorted or not. returns 1 if sorted in ascending order, -1 if descending and 0 otherwise
int checkSort(nodetype* head){
	if(empty_l(head)){
		printf("List empty\n");
		return 0;
	}
	nodetype* temp=head->next;
	nodetype* prev=head;
	while(temp->info == prev->info && temp!=NULL){
		prev=temp;
		temp=temp->next;
	}
	if(temp == NULL)
		return 1;
	else{
		if(prev->info < temp->info){
			while(temp!=NULL){

				if(prev->info > temp->info)
					return 0; 
				prev=temp;
				temp=temp->next;
			}
			return 1;
		}
		else{
			while(temp!=NULL){
				if(prev->info < temp->info)
					return 0; 
				prev=temp;
				temp=temp->next;
			}
			return -1;
		}
	}
}

//to merge 2 sorted lists assuming both are in ascending order
void mergeSorted(nodetype** head1, nodetype* head2){
	if(empty_l(*head1) || empty_l(head2)){
		printf("List empty\n");
		return;
	}
	int i=0;
	nodetype* temp1=*head1;
	nodetype* temp2=head2;
	printSame(temp1);
	printSame(temp2);
	nodetype* head3=(nodetype*)malloc(sizeof(nodetype));
	nodetype* temp3=(nodetype*)malloc(sizeof(nodetype));
	if(temp1->info <= temp2->info){
		head3=createnode((*head1)->info);
		temp1=temp1->next;
	}
	else{
		head3=createnode(head2->info);
		temp2=temp2->next;
	}
	printf("case %d %d\n",++i,head3->info);
	temp3=head3;
	while(temp1!=NULL && temp2!=NULL){
		printf("%d\n",temp3->info);
		printf("%d %d\n",temp1->info,temp2->info);
		//sleep(1);
		if(temp1->info <= temp2->info){
			temp3->next=createnode(temp1->info);
			temp3=temp3->next;
			//temp3->next=NULL;
			temp1=temp1->next;
			printf("case %d %d\n",++i,temp3->info);
		}
		else{
			temp3->next=createnode(temp2->info);
			temp3=temp3->next;
			//temp3->next=NULL;
			temp2=temp2->next;
			printf("case %d %d\n",++i,temp3->info);
		}
		//printf("%d\n",temp3->info);
	}
	while(temp1!=NULL){
		temp3->next=createnode(temp1->info);
		temp3=temp3->next;
		//temp3->next=NULL;
		temp1=temp1->next;
		printf("case %d %d\n",++i,temp3->info);
	}
	while(temp2!=NULL){
		temp3->next=createnode(temp2->info);
		temp3=temp3->next;
		//temp3->next=NULL;
		temp2=temp2->next;
		printf("case %d %d\n",++i,temp3->info);
	}
	printf("Done\n");
	temp3->next=NULL;
	delList(head1);
	*head1=head3;
	printSame(*head1);
	printSame(head2);
}

//pairwise swapping of elements
void swap(nodetype* head){
	if(empty_l(head)){
		printf("List empty\n");
		return;
	}
	nodetype* temp1=head;
	int temp;
	while((temp1->next)!=NULL){
		temp=temp1->info;
		temp1->info=(temp1->next)->info;
		(temp1->next)->info=temp;
		temp1=(temp1->next)->next;
		if(temp1==NULL)
			break;
	}
}

void last2front(nodetype** head){
	if(empty_l(*head)){
		printf("List empty\n");
		return;
	}
	nodetype* prev=*head;
	nodetype* temp=(*head)->next;
	while(temp->next!=NULL){
		prev=temp;
		temp=temp->next;
	}
	temp->next=*head;
	*head=temp;
	prev->next=NULL;
}

void delAlt(nodetype* head){
	if(empty_l(head)){
		printf("List empty\n");
		return;
	}
	nodetype* temp=head;
	while(temp!=NULL && temp->next!=NULL){
		temp->next=(temp->next)->next;
		temp=temp->next;
	}
}

void delList(nodetype** head){
	while(!empty_l(*head)){
		printf("%d deleted\n",delete_front(head));
		printSame(*head);
	}
	printf("Whole list deleted");
	*head=NULL;

}

void delDuplicateSort(nodetype* head){
	nodetype* temp=head;
	while(temp->next!=NULL){
		if(temp->info == (temp->next)->info)
			delete_after(temp);
		else
			temp=temp->next;
	}
}

void delDuplicateUnsort(nodetype* head){
	if(empty_l(head)){
		printf("Empty list\n");
		return;
	}
	printf("Hi\n");
	int res;
	nodetype* prev=head;
	nodetype* temp=head;
	printf("Hi\n");
	while(prev->next!=NULL){
		temp=head;
		res=0;
		while(temp!=prev->next){
			//printf("Hi\n");
			printf("%d  %d\n",temp->info,prev->info);
			//sleep(0.5);
			if(temp->info==(prev->next)->info){
				res=1;
				printf("true\n");
				delete_after(prev);
				break;
			}
			temp=temp->next;
		}
		if(res==0){
			prev=prev->next;
		}
	}
}

nodetype* rotate(nodetype* head, int n){
	if(!empty_l(head)){
		n=n%size(head);
		int i=1;
		nodetype* temp1=(nodetype*)malloc(sizeof(nodetype));
		nodetype* temp2=(nodetype*)malloc(sizeof(nodetype));
		temp1=head;
		while(i<n){
			temp1=temp1->next;
			i++;
		}
		temp2=temp1->next;
		while(temp2->next!=NULL){
			printf("%d  ",temp2->info);
			temp2=temp2->next;
		}
		printf("\n");
		temp2->next=head;
		printf("%d %d\n",temp2->info,(temp2->next)->info);
		head=temp1->next;
		printf("%d\n",head->info);
		temp1->next=NULL;
		printSame(head);
		return head;
	}
}

nodetype* reverse(nodetype* head){
	printf("\n");
	nodetype* head2=(nodetype*)malloc(sizeof(nodetype));
	head2=init_l();
	nodetype* temp=(nodetype*)malloc(sizeof(nodetype));
	int x;
	while(!empty_l(head)){
		x=delete_front(&head);
		temp=createnode(x);
		insert_front(temp,&head2);
		printf("\n%d\n",head2->info);
	}
	head=NULL;
	head=head2;
	//printSame(*head);
	printf("Done\n\n");
	printSame(head);
	return head;
}

void insertBegUnsort(nodetype** head,nodetype* target){
	insert_front(target,head);
}

void insertMidUnsort(nodetype* head,nodetype* target,nodetype* prev){
	nodetype* temp=head;
	while(temp->next!=prev){
		temp=temp->next;
		if(temp==NULL){
			printf("Node not found\n");
			return;
		}
	}
	temp->next=target;
	target->next=prev;	
}

void insertEndUnsort(nodetype* head,nodetype* target){
	nodetype* temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=target;
	target->next=NULL;
}

void insertBegSort(nodetype** head,nodetype* target){
	if((checkSort(*head)==1 && (target->info > (*head)->info)) || (checkSort(*head))==-1 && (target->info < (*head)->info)){
		printf("Sorting order will be disrupted.\n");
		return;
	}
	insert_front(target,head);
}

void insertMidSort(nodetype* head,nodetype* target,nodetype* prev){
	if((checkSort(head)==1 && (target->info > prev->info)) || (checkSort(head)==-1 && (target->info < prev->info))){
		printf("Sorting order will be disrupted.\n");
		return;
	}
	nodetype* temp=head;
	while(temp->next!=prev){
		temp=temp->next;
		if(temp==NULL){
			printf("Node not found\n");
			return;
		}
	}
	temp->next=target;
	target->next=prev;
}

void insertEndSort(nodetype* head,nodetype* target){
	nodetype* temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	if((checkSort(head)==1 && (target->info < temp->info)) || (checkSort(head)==-1 && (target->info > temp->info))){
		printf("Sorting order will be disrupted.\n");
		return;
	}
	temp->next=target;
	target->next=NULL;
}