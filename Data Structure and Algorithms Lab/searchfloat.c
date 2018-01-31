#include <stdio.h>
#include <math.h>
#define ACC 0.001
float a[50];
void sort(int len);
int main(){
	srand(time(NULL));
	int i;
	float n;
	for(i=0;i<50;i++){
		a[i]=rand()/10000.0;
		printf("%f\n",a[i]);
	}
	printf("Enter a number");
	scanf("%f",&n);
	printf("Linear search\n");
	for(i=0;i<50;i++){
		if(a[i]-n <= ACC && a[i]-n >= (-1*ACC))
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
		printf("%f\n",a[i]);
	printf("Sorted\n");
	int low=0,hi=49,mid,flag=0;
	while(low<hi){
		mid=(low+hi)/2;
		if(a[mid]-n <= ACC && a[mid]-n >= (-1*ACC)){
			printf("Search found at %dth position\n",(mid+1));
			flag=1;
			break;
		}
		else if(n-a[mid]< -1*ACC)
			hi=mid-1;
		else if(n-a[mid]>ACC)
			low=mid+1;
	}
	if(flag==0)
		printf("Search not found\n");
	return 0;
}
void sort(int len){
	int i,j,minpos;
	float min;
	for(i=0;i<len-1;i++){
		min=a[i];
		minpos=i;
		for(j=i+1;j<len;j++){
			if(a[j]-min<-1*ACC){
				min=a[j];
				minpos=j;
			}
		}
		a[minpos]=a[i];
		a[i]=min;
	}
}