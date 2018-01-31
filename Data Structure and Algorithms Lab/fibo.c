#include <stdio.h>
int fib_itr(int);
int fib_rec(int);
int fib_arr(int);
int main(){
	int n;
	printf("Enter n = ");
	scanf("%d",&n);
	printf("%dth Fibonacci term in iterative method = %d\n",n,fib_itr(n));
	printf("%dth Fibonacci term in recursive method = %d\n",n,fib_rec(n));
	printf("%dth Fibonacci term in array method = %d\n",n,fib_arr(n));
}
int fib_itr(int n){
	if(n<3)
		return 1;
	else{
		int i=3,a=1,b=1,c=1;
		for(;i<=n;i++){
			c=a+b;
			a=b;
			b=c;
		}
		return c;
	}
}
int fib_rec(int n){
	if(n<3)
		return 1;
	else
		return fib_rec(n-1)+fib_rec(n-2);
}
int fib_arr(int n){
	int a[n];
	a[0]=1;
	a[1]=1;
	int i=2;
	for(;i<n;i++){
		a[i]=a[i-1]+a[i-2];
	}
	return a[i-1];
}