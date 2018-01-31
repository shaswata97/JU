#include<stdio.h>
#include<stdlib.h>

typedef struct bintree{
	int info;
	struct bintree* right;
	struct bintree* left;
} bin_tree;

bin_tree* init_t();
int empty_t(bin_tree *t);
bin_tree* makeroot(int n);
void makeleft(bin_tree* t,int n);
void makeright(bin_tree* t,int n);
int height(bin_tree* t);
int max(int a,int b);
void pre_order_traverse(bin_tree* t,void (*visit)(bin_tree*));
void in_order_traverse(bin_tree* t,void (*visit)(bin_tree*));
void post_order_traverse(bin_tree* t,void (*visit)(bin_tree*));
int isLeaf(bin_tree* t);
void delete_leaf(bin_tree* t);
void visit(bin_tree* t);

//Main function for testing
int main(){
	bin_tree* tree;
	tree=init_t();
	tree=makeroot(5);
	makeleft(tree,6);
	makeright(tree,8);
	makeright(tree->left,10);
	makeleft(tree->left,9);
	makeleft(tree->right,11);
	makeright(tree->right->left,18);
	printf("Height of tree is %d\n",height(tree));
	printf("Pre order traversal is ");
	pre_order_traverse(tree,visit);
	printf("\nIn order traversal is ");
	in_order_traverse(tree,visit);
	printf("\nPost order traversal is ");
	post_order_traverse(tree,visit);
	return 0;
}

//Function for visiting a node
void visit(bin_tree* t){
	printf("%d  ",t->info);
}

//Function to initialise a binary tree
bin_tree* init_t(){
	return NULL;
}

//Function to check if a binary tree is empty
int empty_t(bin_tree *t){
	return (t==NULL);
}

//Function to make root of a tree
bin_tree* makeroot(int n){
	bin_tree* t;
	if((t = malloc(sizeof(bin_tree))) == NULL)
		perror("malloc error");
	else{
		t->info=n;
		t->left=NULL;
		t->right=NULL;
	}
	return t;
}

//Function to make a node left node
void makeleft(bin_tree* t,int n){
	t->left=makeroot(n);
} 

//Function to make a node right node
void makeright(bin_tree* t,int n){
	t->right=makeroot(n);
}

//Function to find height of a binary tree
int height(bin_tree* t){
	if(t==NULL)
		return 0;
	else
		return 1+max(height(t->left),height(t->right));
}

//Function to find max of two numbers
int max(int a,int b){
	return a>=b?a:b;
}

//Fucntion to traverse in preorder fashion
void pre_order_traverse(bin_tree* t, void (*visit)(bin_tree*)){
	if(!empty_t(t)){
		(*visit)(t);
		pre_order_traverse(t->left,visit);
		pre_order_traverse(t->right,visit);
	}
	
}

//Fucntion to traverse in inorder fashion
void in_order_traverse(bin_tree* t, void (*visit)(bin_tree*)){
	if(!empty_t(t)){		
		in_order_traverse(t->left,visit);
		(*visit)(t);
		in_order_traverse(t->right,visit);
	}
	
}

//Fucntion to traverse in postorder fashion
void post_order_traverse(bin_tree* t,void (*visit)(bin_tree*)){
	if(!empty_t(t)){		
		post_order_traverse(t->left,visit);
		post_order_traverse(t->right,visit);
		(*visit)(t);
	}
	
}

//Function to check if a node is a leaf node
int isLeaf(bin_tree* t){
	return (t->left==NULL && t->right==NULL);
}

//Function to delete a leaf node
void delete_leaf(bin_tree* t){
	if(isLeaf(t))
		free(t);
}