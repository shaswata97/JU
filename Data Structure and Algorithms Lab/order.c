#include <stdio.h>

int main(void) 
{
	int N=15;
    int a[N];
    int i, n;

    printf( "Enter number of elements in the array not greater than %d: ", N );
    scanf( "%d", &n );
	if ( N < n ) 
		n = N;
    printf( "Enter %d elements of the array: ", n );
	for ( i = 0; i < n; i++ ) 
		scanf( "%d", &a[i] );
	i = 0;
	while ( i++ < n &&  a[i-1] >= a[i]  );
	if ( i == n ) 
	printf( "The array is sorted in the descending order\n" );
	else{
	    while ( i++ < n && ( a[i-1] <= a[i] ) );
		printf( "The array is sorted in ascending order\n" );
	}
    return 0;
}
