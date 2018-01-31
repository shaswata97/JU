#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int arr[30000];
	FILE *fp;
	srand(time(NULL));
	int i=1,x,j;
	arr[0]=rand()%30000;
	printf("%d\n",i);
	while(i<30000){
		x=rand()%30000;
		for(j=0;j<i;j++){
			if(arr[j]==x){
				break;
			}
			
		}
		if(j==i){
			arr[i]=x;
			fp=fopen("random.txt","a+");
			fprintf(fp,"%d\n",arr[i]);
			fclose(fp);
			i++;
		}
	}
	if(i==30000)
		printf("Done!\n");
}