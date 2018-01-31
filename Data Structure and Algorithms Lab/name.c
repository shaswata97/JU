#include <stdio.h>
#include <math.h>
#include <string.h>
int p=1009;
char name[256];
int main(){
	printf("Enter your name without spaces ");
	scanf("%[^\n]",&name);
	int len=0,i=0,ch,sum=0,pos=0,div,rem;
	char nameup[256];
	while(name[i]!='\0'){
		if(name[i]!=' ')
			len++;
		nameup[i]=toupper(name[i]);
		i++;
	}
	int *num=(int *)malloc(sizeof(int)*(len*2));
	printf("%s\n%d\n",nameup,len);
	for(i=0;i<len;i++){
		ch=(int)nameup[i];
		num[2*i]=ch/10;
		num[2*i+1]=ch%10;
	}
	for(i=0;i<2*len;i++)
		printf("%d",num[i]);
	printf("\n");
	int *num_left=(int *)malloc(sizeof(int)*(len));
	int *num_right=(int *)malloc(sizeof(int)*(len));
	for(i=0;i<len;i++){
		num_left[i]=num[i];
		num_right[i]=num[i+len];
	}
	for(i=0;i<len;i++)
		printf("%d",num_left[i]);
	printf("\n");
	for(i=0;i<len;i++)
		printf("%d",num_right[i]);
	printf("\n");
	int *carry=(int *)malloc(sizeof(int)*(len+1));
	carry[len]=0;
	int *numsum=(int *)malloc(sizeof(int)*(len+1));
	for(i=len-1;i>=0;i--){
		sum=num_left[i]+num_right[i]+carry[i+1];
		numsum[i+1]=sum%10;
		carry[i]=sum/10;
	}
	numsum[0]=carry[0];
	for(i=0;i<len;i++)
		printf("%d",num_left[i]);
	printf("\n");
	for(i=0;i<len;i++)
		printf("%d",num_right[i]);
	printf("\n");
	if(numsum[0]==0){
		pos=1;
	}
	for(i=pos;i<len+1;i++)
		printf("%d",numsum[i]);
	div=numsum[0]*1000+numsum[1]*100+numsum[2]*10+numsum[3]*1;
	for(i=3;i<=len;i++){
		rem=div%p;
		div=rem*10+numsum[i+1];
	}
	printf("\n%d",rem);
}
