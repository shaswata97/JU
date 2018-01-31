#include<stdio.h>
#include<stdlib.h>

typedef struct bstree{
	int info;
	struct bstree* right;
	struct bstree* left;
} bst;

bst* init_t();
int empty_t(bst *t);
bst* makeroot(int n);
void makeleft(bst* t,int n);
void makeright(bst* t,int n);
bst* insert(bst* t,int n);
int isLeaf(bst* t);
void visit(bst* t);
bst* search(bst* t, int key);
void in_order_traverse(bst* t, void (*visit)(bst*));
bst* delete(bst* t,int n);
bst* find_max(bst* t);
bst* find_min(bst* t);
void kthmin(bst* t,int k,int* c);
void findkthmin(bst* t,int k);
void kthmax(bst* t,int k,int* c);
void findkthmax(bst* t,int k);

//Main function
int main(){
	bst* tree,*srch;
	tree=init_t();
	tree=insert(tree,5);
	insert(tree,6);
	insert(tree,4);
	insert(tree,-55);
	insert(tree,3);
	insert(tree,9);
	insert(tree,10);
	insert(tree,8);
	printf("In order traversal is ");
	in_order_traverse(tree,visit);
	printf("\n");
	srch=search(tree,5);
	search(tree,4);
	search(tree,100);
	bst* del=delete(tree,3);
	delete(tree,9);
	printf("In order traversal is ");
	in_order_traverse(tree,visit);
	printf("\nThe max element is %d",find_max(tree)->info);
	printf("\nThe min element is %d",find_min(tree)->info);
	findkthmin(tree,3);
	findkthmin(tree,4);
	findkthmax(tree,3);
	findkthmax(tree,2);
	return 0;
}

//Function to initialise a binary tree
bst* init_t(){
	return NULL;
}

//Function to check if a binary tree is empty
int empty_t(bst *t){
	return (t==NULL);
}

//Function to make root of a tree
bst* makeroot(int n){
	bst* t;
	if((t = malloc(sizeof(bst))) == NULL)
		perror("malloc error");
	else{
		t->info=n;
		t->left=NULL;
		t->right=NULL;
	}
	return t;
}

//Function to make a node left node
void makeleft(bst* t,int n){
	t->left=makeroot(n);
} 

//Function to make a node right node
void makeright(bst* t,int n){
	t->right=makeroot(n);
}

//Fucntion to insert an element into bst
bst* insert(bst* t,int n){
	if(empty_t(t))
		t=makeroot(n);
	else{
		if(n < t->info)
			t->left=insert(t->left,n);
		else
			t->right=insert(t->right,n);

	}
	return t;

}

//Function to search for a key in bst
bst* search(bst* t, int key){
	if(empty_t(t)){
		printf("%d not found\n",key);
		return NULL;
	}
	else if(t->info==key){
		printf("%d found\n",key);
		return t;
	}
	else if(key<t->info)
		return search(t->left,key);
	else
		return search(t->right,key);
}

//Function to find max
bst* find_max(bst* t){
	if(!empty_t(t)){
		if(t->right==NULL)
			return t;
		else
			return find_max(t->right); 
	}
}

//Function to find min
bst* find_min(bst* t){
	if(!empty_t(t)){
		if(t->left==NULL)
			return t;
		else
			return find_min(t->left); 
	}
}

//Function to delete a node from bst
bst* delete(bst* t,int n){
	//Base case
	if(t==NULL)
		return t;
	else if(n>t->info)
		t->right=delete(t->right,n);
	else if(n<t->info)
		t->left=delete(t->left,n);
	else{
		//If this is the node to be deleted
		//If the root has only one child or no child
		if(t->left==NULL){
			bst* temp=t->left;
			free(t);
			return temp;
		}
		else if(t->right==NULL){
			bst* temp=t->right;
			free(t);
			return temp;
		}

		//Node with 2 children
		//Get in order successor
		bst* temp=find_min(t->right);
		t->info=temp->info;
		t->right=delete(t->right,temp->info);
	}
	return t;
}

//Function to find kth min
void kthmin(bst* t,int k,int* c){
	//Base case
	if(t==NULL || *c>=k)
		return;
	//Traverse inorder
	kthmin(t->left,k,c);
	(*c)++;
	if(*c==k){
		printf("\nThe %d-th smallest element is %d",k,t->info);
		return;
	}
	kthmin(t->right,k,c);
}

//Function to run kthmin
void findkthmin(bst* t,int k){
	int c=0;
	kthmin(t,k,&c);
}

//Function to find kth max
void kthmax(bst* t,int k,int* c){
	//Base case
	if(t==NULL || *c>=k)
		return;
	//Traverse reverse inorder
	kthmax(t->right,k,c);
	(*c)++;
	if(*c==k){
		printf("\nThe %d-th largest element is %d",k,t->info);
		return;
	}
	kthmax(t->left,k,c);
}

//Function to run kthmax
void findkthmax(bst* t,int k){
	int c=0;
	kthmax(t,k,&c);
}

//Function to check if a node is a leaf node
int isLeaf(bst* t){
	return (t->left==NULL && t->right==NULL);
}

//Function for visiting a node
void visit(bst* t){
	printf("%d  ",t->info);
}

//Fucntion to traverse in inorder fashion
void in_order_traverse(bst* t, void (*visit)(bst*)){
	if(!empty_t(t)){		
		in_order_traverse(t->left,visit);
		(*visit)(t);
		in_order_traverse(t->right,visit);
	}
	
}