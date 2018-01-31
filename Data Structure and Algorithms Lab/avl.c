#include<stdio.h>
#include<stdlib.h>

typedef struct avltree{
	int info;
	struct avltree* right;
	struct avltree* left;
	int bf;
} avl;

avl* init_t();
avl* rightRotate(avl* t);
avl* rightRotate(avl* t);
int getBalance(avl* t);
int empty_t(avl *t);
int height(avl* t);
int max(int a,int b);
avl* makeroot(int n);
avl* insert(avl* t,int n);
void visit(avl* t);
avl* search(avl* t, int key);
void in_order_traverse(avl* t, void (*visit)(avl*));
void pre_order_traverse(avl* t, void (*visit)(avl*));
avl* delete(avl* t,int n);
avl* find_max(avl* t);
avl* find_min(avl* t);
void kthmin(avl* t,int k,int* c);
void findkthmin(avl* t,int k);
void kthmax(avl* t,int k,int* c);
void findkthmax(avl* t,int k);


//Main function
//Main function
int main(){
	avl* tree,*srch;
	tree=init_t();
	tree=insert(tree,9);
	insert(tree,5);
	insert(tree,10);
	insert(tree,0);
	insert(tree,6);
	insert(tree,11);
	insert(tree,-1);
	insert(tree,1);
	insert(tree,2);
	//insert(tree,12);
	printf("In order traversal is ");
	in_order_traverse(tree,visit);
	printf("\nPre order traversal is ");
	pre_order_traverse(tree,visit);
	printf("\n");
	// srch=search(tree,5);
	// search(tree,4);
	// search(tree,10);
	avl* del=delete(tree,9);
	printf("In order traversal is ");
	in_order_traverse(tree,visit);
	printf("\nPre order traversal is ");
	pre_order_traverse(tree,visit);
	printf("\nThe max element is %d",find_max(tree)->info);
	printf("\nThe min element is %d",find_min(tree)->info);
	findkthmin(tree,3);
	findkthmin(tree,4);
	findkthmax(tree,3);
	findkthmax(tree,2);
	printf("\n");
	return 0;
}




//Function to initialise a binary tree
avl* init_t(){
	return NULL;
}

//Function to check if a binary tree is empty
int empty_t(avl *t){
	return (t==NULL);
}

//Function to make root of a tree
avl* makeroot(int n){
	avl* t;
	if((t = malloc(sizeof(avl))) == NULL)
		perror("malloc error");
	else{
		t->info=n;
		t->left=NULL;
		t->right=NULL;
		t->bf=1;
	}
	return t;
}

//Function to search for a key in avl
avl* search(avl* t, int key){
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
avl* find_max(avl* t){
	if(!empty_t(t)){
		if(t->right==NULL)
			return t;
		else
			return find_max(t->right); 
	}
}

//Function to find min
avl* find_min(avl* t){
	if(!empty_t(t)){
		if(t->left==NULL)
			return t;
		else
			return find_min(t->left); 
	}
}

//Function to find kth min
void kthmin(avl* t,int k,int* c){
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
void findkthmin(avl* t,int k){
	int c=0;
	kthmin(t,k,&c);
}

//Function to find kth max
void kthmax(avl* t,int k,int* c){
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
void findkthmax(avl* t,int k){
	int c=0;
	kthmax(t,k,&c);
}


//Function for visiting a node
void visit(avl* t){
	printf("%d  ",t->info);
}

//Fucntion to traverse in inorder fashion
void in_order_traverse(avl* t, void (*visit)(avl*)){
	if(!empty_t(t)){		
		in_order_traverse(t->left,visit);
		(*visit)(t);
		in_order_traverse(t->right,visit);
	}
	
}

//Function to find height
int height(avl* t){
	if(t==NULL)
		return 0;
	else
		return t->bf;
}

//Function to find max of two numbers
int max(int a,int b){
	return a>=b?a:b;
}

//Function to right rotate a subtree rooted at t
avl* rightRotate(avl* t){

	//Performing rotation
	avl* temp=t->left;
	t->left=temp->right;
	temp->right=t;

	//Update heights
	t->bf=max(height(t->left),height(t->right))+1;
	temp->bf=max(height(temp->left),height(temp->right))+1;

	return temp;

}

//Function to left rotate a subtree rooted at t
avl* leftRotate(avl* t){

	//Performing rotation
	avl* temp=t->right;
	t->right=temp->left;
	temp->left=t;

	//Update heights
	t->bf=max(height(t->left),height(t->right))+1;
	temp->bf=max(height(temp->left),height(temp->right))+1;

	return temp;

}

//Function to get Balance factor of node N
int getBalance(avl* t)
{
	if (t == NULL)
		return 0;
	return height(t->left) - height(t->right);

}

//Fucntion to insert an element into avl
avl* insert(avl* t,int key){

	//Normal avl insertion
	if(empty_t(t))
		return makeroot(key);
	else{
		if(key < t->info)
			t->left=insert(t->left,key);
		else
			t->right=insert(t->right,key);

	}

	//Update height
	t->bf=1+max(height(t->left),height(t->right));

	//Check whether balanced
	int balance=getBalance(t);


	//If unbalanced rotate
	 // Left Left Case
	if (balance > 1 && key < t->left->info)
		return rightRotate(t);

    // Right Right Case
	if (balance < -1 && key > t->right->info)
		return leftRotate(t);

    // Left Right Case
	if (balance > 1 && key > t->left->info)
	{
		t->left =  leftRotate(t->left);
		return rightRotate(t);
	}

    // Right Left Case
	if (balance < -1 && key < t->right->info)
	{
		t->right = rightRotate(t->right);
		return leftRotate(t);
	}

	return t;
}

//Function to delete a node from avl tree
avl* delete(avl* t,int n){

	//First perform standard bst deletion
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
		if( (t->left == NULL) || (t->right == NULL) )
        {
			avl *temp = t->left ? t->left:t->right;
	 		
	 		//For no child Case
			if(temp==NULL){
				temp=t;
				t=NULL;
			}
			else 
				*t=*temp;
			free(temp);
			
		}
		else{
			//Node with 2 children
			//Get in order successor
			avl* temp=find_min(t->right);
			t->info=temp->info;
			t->right=delete(t->right,temp->info);
		}
	}

	// If the tree had only one node then return
    if (t == NULL)
      return t;

  	//Update height
  	t->bf=1+max(height(t->left),height(t->right));

  	//Check whether balanced
	int balance=getBalance(t);

	//If unbalanced rotate
	// Left Left Case
	if (balance > 1 && getBalance(t->left)>=0)
		return rightRotate(t);

    // Right Right Case
	if (balance < -1 && getBalance(t->right)<=0)
		return leftRotate(t);

    // Left Right Case
	if (balance > 1 && getBalance(t->left)<0)
	{
		t->left =  leftRotate(t->left);
		return rightRotate(t);
	}

    // Right Left Case
	if (balance < -1 && getBalance(t->left)>0)
	{
		t->right = rightRotate(t->right);
		return leftRotate(t);
	}

	return t;


}

//Fucntion to traverse in preorder fashion
void pre_order_traverse(avl* t, void (*visit)(avl*)){
	if(!empty_t(t)){
		(*visit)(t);
		pre_order_traverse(t->left,visit);
		pre_order_traverse(t->right,visit);
	}
	
}
