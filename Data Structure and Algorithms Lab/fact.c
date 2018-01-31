#include <stdio.h>
long long int fact_itr(int);
long long int fact_rec(int);
long long int fact_arr(int);
int main(){
	int n;
	printf("Enter n = ");
	scanf("%d",&n);
	printf("Factorial of %d in iterative method = %lld\n",n,fact_itr(n));
	printf("Factorial of %d in recursive method = %lld\n",n,fact_rec(n));
	printf("Factorial of %d in array method = %lld\n",n,fact_arr(n));
}
long long int fact_itr(int n){
	long long int fact=1;
	int i=1;
	for(;i<=n;i++){
		fact*=i;
	}
	return fact;
}
long long int fact_rec(int n){
	if(n==1)
		return 1;
	else
		return (n*fact_rec(n-1));
}
long long int fact_arr(int n){
	long long int a[n];
	a[0]=1;
	int i=1;
	for(;i<n;i++){
		a[i]=(i+1)*a[i-1];
	}
	return a[n-1];
}