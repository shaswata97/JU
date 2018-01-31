#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

#define M 32003

struct hashtable{
    int count;   //counts the number of elements in the table.
    int** arr;   //M*2 dimensioned array for M number of entries. First column stores the info. Second column stores whether
    			 //the cell is empty(1), full(0), or a value has been deleted for it(-1) for closed addressing. For open addressing like 
    			 //like coalesced chaining, it denotes the postion where the next synonym is placed. Contains M if empty.
};

struct hashlist{
	int count;
	nodetype** arr;
};

int hash(int k);
int hash2(int k);
struct hashtable* inittable();
int searchLinProb(struct hashtable* h1, int key);
int searchDoubleHash(struct hashtable* h1, int key);
void insert(struct hashtable* h1, int key, int ch);
void delete(struct hashtable* h1, int key, int ch);
void display(struct hashtable* h1);

struct hashlist* initlist();
void insertSepChain(struct hashlist* h1, int key);
void deleteSepChain(struct hashlist* h1, int key);
nodetype* searchSepChain(struct hashlist* h1, int key);
void displaySepChain(struct hashlist* h1);

struct hashtable* initCoa();
int searchCoaChain(struct hashtable* h1, int key);
void insertCoaChain(struct hashtable* h1, int key);
void deleteCoaChain(struct hashtable* h1, int key);
void displayCoaChain(struct hashtable* h1);

int main(){
	printf("\n--------------------checking linear probing-----------------------\n");
	struct hashtable* h;
	h=inittable();
	int x=2,key=96010;
	printf("Table made\n");
	insert(h,1,1);
	display(h);
	sleep(1);
	insert(h,2,1);
	display(h);
	sleep(1);
	insert(h,3,1);
	display(h);
	sleep(1);
	insert(h,5,1);
	display(h);
	sleep(1);
	insert(h,32004,1);
	display(h);
	sleep(1);
	insert(h,64007,1);
	display(h);
	sleep(1);
	insert(h,32005,1);
	display(h);
	sleep(1);
	insert(h,96010,1);
	display(h);
	int pos=searchLinProb(h,key);
	if(h->arr[pos][0]==key && h->arr[pos][1]==0){
		printf("Index of %d = %d\n",key,pos);
	}
	else
		printf("%d not found\n",key);
	sleep(1);
	delete(h,64007,1);
	display(h);
	sleep(1);
	insert(h,21,1);
	display(h);

	printf("\n--------------------checking double hashing-----------------------\n");
	//struct hashtable* h;
	h=inittable();
	//int x=2,key=96010;
	printf("Table made\n");
	insert(h,1,2);
	display(h);
	sleep(1);
	insert(h,2,2);
	display(h);
	sleep(1);
	insert(h,3,2);
	display(h);
	sleep(1);
	insert(h,5,2);
	display(h);
	sleep(1);
	insert(h,32004,2);
	display(h);
	sleep(1);
	insert(h,64007,2);
	display(h);
	sleep(1);
	insert(h,32005,2);
	display(h);
	sleep(1);
	insert(h,96010,2);
	display(h);
	pos=searchDoubleHash(h,key);
	if(h->arr[pos][0]==key && h->arr[pos][1]==0){
		printf("Index of %d = %d\n",key,pos);
	}
	else
		printf("%d not found\n",key);
	sleep(1);
	delete(h,64007,2);
	display(h);
	sleep(1);
	insert(h,21,2);
	display(h);


	printf("\n--------------------checking coalesced chaining-----------------------\n");
	//struct hashtable* h;
	h=initCoa();
	//int x=2,key=96010;
	printf("Table made\n");
	insertCoaChain(h,1);
	displayCoaChain(h);
	sleep(1);
	insertCoaChain(h,2);
	displayCoaChain(h);
	sleep(1);
	insertCoaChain(h,3);
	displayCoaChain(h);
	sleep(1);
	insertCoaChain(h,5);
	displayCoaChain(h);
	sleep(1);
	insertCoaChain(h,32004);
	displayCoaChain(h);
	sleep(1);
	insertCoaChain(h,64007);
	displayCoaChain(h);
	sleep(1);
	insertCoaChain(h,32005);
	displayCoaChain(h);
	sleep(1);
	insertCoaChain(h,96010);
	displayCoaChain(h);
	pos=searchCoaChain(h,key);
	if(h->arr[pos][0]==key && h->arr[pos][1]!=M){
		printf("Index of %d = %d\n",key,pos);
	}
	else
		printf("%d not found\n",key);
	sleep(1);
	deleteCoaChain(h,64007);
	displayCoaChain(h);
	sleep(1);
	insertCoaChain(h,21);
	displayCoaChain(h);

	printf("\n-----------------------checking separate chaining------------------------------------\n");
	struct hashlist* h1;
	h1=initlist();
	//int x=2,key=7;
	printf("Table made\n");
	insertSepChain(h1,1);
	displaySepChain(h1);
	sleep(1);
	insertSepChain(h1,2);
	displaySepChain(h1);
	sleep(1);
	insertSepChain(h1,3);
	displaySepChain(h1);
	sleep(1);
	insertSepChain(h1,5);
	displaySepChain(h1);
	sleep(1);
	insertSepChain(h1,32004);
	displaySepChain(h1);
	sleep(1);
	insertSepChain(h1,64007);
	displaySepChain(h1);
	sleep(1);
	insertSepChain(h1,32005);
	displaySepChain(h1);
	sleep(1);
	insertSepChain(h1,96010);
	displaySepChain(h1);
	nodetype* node=searchSepChain(h1,key);
	if(node!=NULL){
		printf("%d found\n",node->info);
	}
	else
		printf("%d not found\n",key);
	sleep(1);
	deleteSepChain(h1,3);
	displaySepChain(h1);
	sleep(1);
	insertSepChain(h1,21);
	displaySepChain(h1);
	printf("\n---------------All methods checked----------------\n");
}

//the hash function
int hash(int k){  
	return (k%M);
}

//the second hash function for double hashing
int hash2(int k){
	return (1+(k%(M-1)));
}

//structure for linear probing and double hashing
struct hashtable* inittable(){
	struct hashtable* h;
	if((h=malloc(sizeof(struct hashtable*)))==NULL)
		perror("malloc error\n");
	else{
		h->count=0;
		h->arr=(int**)malloc(M*sizeof(int*));
		int i=0;
		for(;i<M;i++)
			h->arr[i]=(int*)malloc(2*sizeof(int));
		for(i=0;i<M;i++){
			h->arr[i][0]=0;
			h->arr[i][1]=1;
		}
	}
	return h;
}

//to search the probable position of an element using linear probing
int searchLinProb(struct hashtable* h1, int key){
	int i=hash(key),j=i;
	while(h1->arr[j][1]==0){    //we continue probing until we get an empty or deleted cell,
								//or until we reach the original cell from where we started.
		if(h1->arr[j][0]==key){
			return j;
		}
		j=(j+1)%M;
		if(i==j)
			break;
	}
	return j;
} 

//to search the probable position of an element using double hashing 
int searchDoubleHash(struct hashtable* h1, int key){
	int i=hash(key),j=i;
	int i2=hash2(key);
	while(h1->arr[j][1]==0){    //we continue probing until we get an empty or deleted cell,
										//or until we reach the original cell from where we started.
		if(h1->arr[j][0]==key)
			return j;
		j=(i+j*i2)%M;
		if(i==j)
			break;
	}
	return j;
}

//to insert an element in the hash table
void insert(struct hashtable* h1, int key, int ch){
	if(h1->count==M){
		printf("Table already full. Exiting\n");
		return;
	}
	int i; //denotes the position at which element is to be placed
	switch(ch){  //checking which method of collision resolution is to be used
		case 1:
			i=searchLinProb(h1,key);
			break;
		case 2:
			i=searchDoubleHash(h1,key);
			break;
		default:
			printf("Invalid choice. Exiting\n");
			return;
	}
	if(h1->arr[i][1]!=0){             //denotes an empty or previously deleted cell
		h1->arr[i][0]=key;
		h1->arr[i][1]=0;                //denotes that cell is full
		h1->count++;
	}
	else if(h1->arr[i][0]==key){
		printf("Element already exists\n");
	}
	else{
		printf("Collision cannot be resolved by this method\n");
	}
}

//to delete an element from the hash table
void delete(struct hashtable* h1, int key, int ch){
	if(h1->count==0){
		printf("Table empty. Nothing to delete. Exiting\n");
		return;
	}
	int pos;     //denotes the position at which element is to be placed
	switch(ch){  //checking which method of collision resolution is to be used
		case 1:
			pos=searchLinProb(h1,key);
			break;
		case 2:
			pos=searchDoubleHash(h1,key);
			break;
		default:
			printf("Invalid choice. Exiting\n");
			return;
	}
	if(h1->arr[pos][1]==0 && h1->arr[pos][0]==key){             //denotes a filled cell
		h1->arr[pos][1]=-1;                                       //denotes that cell is deleted
		h1->count--;
		printf("Deleting %d successful\n",key);
	}
	else if(h1->arr[pos][1]==1 || h1->arr[pos][1]==-1){
		printf("Element does not exist\n");
	}
	else{
		printf("Collision cannot be resolved by this method\n");
	}
}

//displaying the hashtable
void display(struct hashtable* h1){
	printf("\nCount =%d\n",h1->count);
	if(h1->count==0)
		printf("Nothing to display\n");
	else{
		int i=0,ct=0;
		for(;i<M && ct<=h1->count;i++){
			if(h1->arr[i][1]==0){
				ct++;
				printf("%d(%d)\n",h1->arr[i][0],i);
			}
		}
		printf("\n");
	}
}



//structure for separate chaining 
struct hashlist* initlist(){
	struct hashlist* h;
	if((h=malloc(sizeof(struct hashlist*)))==NULL)
		perror("malloc error");
	else{
		h->count=0;
		h->arr=(nodetype**)malloc(M*sizeof(nodetype*));
		int i=0;
		for(;i<M;i++)
			h->arr[i]=NULL;
	}
	return h;
}

//searching an element in a list
nodetype* searchSepChain(struct hashlist* h1, int key){
	if(h1->count==0){
		printf("Empty list.\n");
		return NULL;
	}
	int i=hash(key);
	nodetype* temp=h1->arr[i];
	while(temp!=NULL){
		if(temp->info==key){
			return temp;
		}
		temp=temp->next;
	}
	return temp;
}

//inserting node in the list
void insertSepChain(struct hashlist* h1, int key){
	nodetype* node=(nodetype*)malloc(sizeof(nodetype));
	int i=hash(key);
	node=searchSepChain(h1,key);
	if(node==NULL){
		node=createnode(key);
		insert_front(node,&(h1->arr[i]));
		h1->count++;
	}
	else{
		printf("Entry already exists\n");
	}
}

//deleting node from list
void deleteSepChain(struct hashlist* h1, int key){
	if(h1->count==0){
		printf("Empty list. Nothing to delete.Exiting\n");
		return;
	}
	printf("\nDeleting %d.\n",key);
	int i=hash(key);
	printf("%d\n",i);
	if((h1->arr[i])==NULL){
		printf("Element not found\n");
	}
	else if((h1->arr[i])->info==key){
		delete_front(&(h1->arr[i]));
		printf("Deleting %d successful.\n",key);
		(h1->count)--;
	}
	else{
		nodetype* prev=h1->arr[i];
		nodetype* temp=prev->next;
		while(temp!=NULL){
			if(temp->info==key){
				delete_after(prev);
				printf("Prev count = %d",h1->count);
				h1->count--;
				printf("Deleting %d successful.\n",key);
				return;
			}
			prev=temp;
			temp=temp->next;
		}
		printf("Element not found\n");
	}
}

//displaying the hashlist
void displaySepChain(struct hashlist* h1){
	printf("\nCount =%d\n",h1->count);
	if(h1->count==0)
		printf("Nothing to display\n");
	else{
		int i=0,ct=0,j;
		nodetype* temp=h1->arr[i];
		for(;i<M && ct<=h1->count;i++){
			temp=h1->arr[i];
			j=0;
			while(temp!=NULL){
				printf("%d(%d)(%d)  ",temp->info,i,j++);
				temp=temp->next;
			}		
		}
		printf("\n");
	}
}


struct hashtable* initCoa(){
	struct hashtable* h;
	if((h=malloc(sizeof(struct hashtable*)))==NULL)
		perror("malloc error\n");
	else{
		h->count=0;
		h->arr=(int**)malloc(M*sizeof(int*));
		int i=0;
		for(;i<M;i++)
			h->arr[i]=(int*)malloc(2*sizeof(int));
		for(i=0;i<M;i++){
			h->arr[i][0]=0;
			h->arr[i][1]=M;
		}
	}
	return h;

}

//searching an element in coalesce chaining
int searchCoaChain(struct hashtable* h1, int key){
	int i=hash(key);
	while(h1->arr[i][0]!=key){
		i=h1->arr[i][1];
		if(h1->arr[i][1]==i)
			break;
	}
	return i;
}

//inserting elements using coalesce chaining to resolve collisions
void insertCoaChain(struct hashtable* h1, int key){
	printf("Inserting %d\n",key);
	if(h1->count==M){
		printf("Table already full. Exiting\n");
		return;
	}
	int i=hash(key),j;
	if(h1->arr[i][1]==M){
		h1->arr[i][0]=key;
		h1->arr[i][1]=i;
		h1->count++;
		printf("Insertion successful\n");
	}
	else{
		i=searchCoaChain(h1,key);
		if(h1->arr[i][0]==key)
			printf("Element exists.\n");
		else{
			for(j=M-1;j>=0;j--){
				if(h1->arr[j][1]==M)    //finding a vacant spot.
					break;
			}
			h1->arr[i][1]=j;            //stores the index of current spot in previous spot
			h1->arr[j][0]=key;
			h1->arr[j][1]=j;
			h1->count++;
		}
	}
}

//deleting an element in coalesce chaining
void deleteCoaChain(struct hashtable* h1, int key){
	if(h1->count==0){
		printf("Empty list. Nothing to delete.Exiting\n");
		return;
	}
	int i=hash(key),j;
	if(h1->arr[i][0]==key && h1->arr[i][1]!=M){
		j=h1->arr[i][1];
		if(j==i)               //if it has no synonyms, we are making the cell empty
			h1->arr[i][1]==M;
		else{
			h1->arr[i][0]=h1->arr[j][0];
			h1->arr[i][1]=h1->arr[j][1];
			if(h1->arr[j][1]==j)
				h1->arr[i][1]=i;  //if next index equals current index then it indicates that it is teh last synonym
			h1->arr[j][1]=M;
			h1->count--;
			printf("Deleting %d successful\n",key);
		}
	}
	else{
		j=h1->arr[i][1];
		while(j!=i && h1->arr[j][0]!=key){
			i=j;
			j=h1->arr[i][1];
		}
		if(j==i)
			printf("Element not found\n");
		else{
			h1->arr[i][1]=h1->arr[j][1];
			h1->arr[j][1]=M;
			h1->count--;
			printf("Deleting %d successful\n",key);
		}
	}
}

//to display the hash table using coalesce chaining
void displayCoaChain(struct hashtable* h1){
	printf("\nCount =%d\n",h1->count);
	if(h1->count==0)
		printf("Nothing to display\n");
	else{
		int i=0,ct=0;
		for(;i<M && ct<=h1->count;i++){
			if(h1->arr[i][1]!=M){
				ct++;
				printf("%d(%d)  ",h1->arr[i][0],i);
			}
		}
		printf("\n");
	}
}