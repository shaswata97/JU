#include<stdio.h>
int merge(int arr1[], int arr2[], int m, int n)
{
  int i = 0, j = 0;
  while (i < m && j < n)
  {
    if (arr1[i] < arr2[j])
      printf(" %d ", arr1[i++]);
    else if (arr2[j] < arr1[i])
      printf(" %d ", arr2[j++]);
    else
    {
      printf(" %d ", arr2[j++]);
      i++;
    }
  }
 
  while(i < m)
   printf(" %d ", arr1[i++]);
  while(j < n)
   printf(" %d ", arr2[j++]);
}
int main()
{
  int n1,n2,N,i;
  N=15;
  int arr1[N];
  int arr2[N];
  printf( "Enter number of elements in the array not greater than %d: ", N );
    scanf( "%d", &n1 );
  if ( N < n1 ) 
    n1 = N;
  printf( "Enter %d elements of the 1st array: ", n1 );
  for ( i = 0; i < n1; i++ ) 
    scanf( "%d", &arr1[i] );
    printf( "Enter number of elements in the array not greater than %d: ", N );
    scanf( "%d", &n2 );
  if ( N < n2 ) 
    n2 = N;
  printf( "Enter %d elements of the 1st array: ", n2 );
  for ( i = 0; i < n2; i++ ) 
    scanf( "%d", &arr2[i] );
  merge(arr1, arr2, n1, n2);
  getchar();
  return 0;
}
