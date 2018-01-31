#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
char a[50][21];
void linear(char a[][21], char* s);
void sort(int len);
int compare(char c[],char b[]);
int main(){
	srand(time(NULL));
	int i,j,len=0;
	char s[21];
	for(i=0;i<50;i++){
		for(j=0;j<20;j++)
		a[i][j]=(char)(65+rand()%26);
		a[i][20]='\n';
		printf("%s\n",a[i]);
	}
	int k;
	printf("Enter string of 20 characters = ");
	scanf("%s",&s);
	while(s[len++]!='\0');
	len--;
	if(len<20)
		printf("Length less. So no match found\n");
	else{
		s[20]='\n';
		printf("Linear search\n");
		linear(a,s);
		printf("Binary Search\n");
		printf("Sorted array\n");
		sort(50);
		for(i=0;i<50;i++)
			printf("%d\n",a[i]);
		printf("Sorted\n");
		int low=0,hi=49,mid,flag=0,res;
		while(low<hi){
			mid=(low+hi)/2;
			res=compare(s,a[mid]);
			if(res==0){
				printf("Search found at %dth position",(mid+1));
				flag=1;
				break;
			}
			else if(res==-1)
				hi=mid-1;
			else
				low=mid+1;
		}
		if(flag==0)
			printf("Search not found");
		return 0;
	}
}
void sort(int len){
	int i,j,minpos;
	printf("Hi1");
	char min[21];
	min[20]='\n';
	printf("Hi2");
	for(i=0;i<len-1;i++){
		printf("1 %d",i);
		strcpy(min,a[i]);
		printf("2 %d",i);
		minpos=i;
		for(j=i+1;j<len;j++){
			if(compare(a[j],min)==-1){
				strcpy(min,a[j]);
				minpos=j;
			}
		}
		strcpy(a[minpos],a[i]);
		strcpy(a[i],min);
	}
}
int compare(char c[],char b[]){
	int i;
	for(i=0;i<20;i++){
		if(c[i]<b[i])
			return -1;
		else if(c[i]>b[i])
			return 1;
	}
	if(i==20)
		return 0;
}
void linear(char a[][21], char* s){
	int i;
	for(i=0;i<50;i++){
			if(compare(a[i],s)==0)
				break;
		}
	if(i==50)
		printf("Search not found\n");
	else
		printf("Search found at %dth position\n",(i+1));
}