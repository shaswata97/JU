#include <stdio.h>
#include <math.h>
int a[50];
void sort(int len);
int main(){
	srand(time(NULL));
	int i,n;
	for(i=0;i<50;i++){
		a[i]=rand()%1000;
		printf("%d\n",a[i]);
	}
	printf("Enter number less than 1000 = ");
	scanf("%d",&n);
	printf("Linear search\n");
	for(i=0;i<50;i++){
		if(a[i]==n)
			break;
	}
	if(i==50)
		printf("Search not found\n");
	else
		printf("Search found at %dth position\n",(i+1));
	sleep(0.5);
	printf("Binary Search\nSorted array\n");
	sort(50);
	for(i=0;i<50;i++)
		printf("%d\n",a[i]);
	printf("Sorted\n");
	int low=0,hi=49,mid,flag=0;
	while(low<hi){
		mid=(low+hi)/2;
		if(a[mid]==n){
			printf("Search found at %dth position",(mid+1));
			flag=1;
			break;
		}
		else if(n<a[mid])
			hi=mid-1;
		else
			low=mid+1;
	}
	if(flag==0)
		printf("Search not found");
	return 0;
}
void sort(int len){
	int i,j,min,minpos;
	for(i=0;i<len-1;i++){
		min=a[i];
		minpos=i;
		for(j=i+1;j<len;j++){
			if(a[j]<min){
				min=a[j];
				minpos=j;
			}
		}
		a[minpos]=a[i];
		a[i]=min;
	}
}