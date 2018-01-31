#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int p;
int prime();
int main()
{
	srand(time(NULL));
	do{
		printf("Enter a 4 digit prime no.\n");
		scanf("%lld",&p);
		if(p<1000 || p>9999)
			printf("Number not 4 digit\n");
		else if(prime()==0)
			printf("Number not prime\n");
		else
			break;
	}while(1);
	int i=0;
	long long L,R;
 	printf("Number\tRemainder\n");
	for(i=1;i<=15;i++){
		L=rand();
		R=L%p;
		printf("%lld\t%lld\n",L,R);
	}
}
int prime(){
	int i,c=0;
	for(i=2;i<=sqrt(p);i++){
		if(p%i==0)
			return 0;
	}
	return 1;
}