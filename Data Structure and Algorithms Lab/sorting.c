#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 50000

int* read(int n);
void insSort(int* arr,int n);
void selectSort(int* arr,int n);
void mergeSort(int* arr,int l,int r);
void merge(int arr[], int l, int m, int r);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
void countingSort(int* arr,int n,int max);
int partition (int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void swap(int* a, int* b);
void display(int* a,int n);


//Main function
int main(){
	int* arr=(int*)malloc(MAX*sizeof(int));
	clock_t begin,end;
	double time_spent;

	arr=read(MAX);
	begin= clock();
	quickSort(arr,0,MAX);
	end = clock();
	time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
	printf("Time taken for Selection sort %lf\n",time_spent);
	display(arr,MAX);


	return 0;
}


//Function to read data from file and store in array
int* read(int max){
	int* arr=(int*)malloc(max*sizeof(int));
	int n,i=1;
	FILE* file;
	file=fopen("random.txt","r");
	fscanf(file,"%d",&n);
	arr[0]=n;
	for(i=1;i<max;i++){
		fscanf(file,"%d",&n);
		arr[i]=n;
	}
	fclose(file);
	return arr;
}

//Functions to implement sorting algortihms
//Insertion sort without sentinel
void insSort(int* arr,int n){
	int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

//Selection sort
void selectSort(int* arr,int n){
	int i,j,temp,pos,min;
	for(i=0;i<n;i++){
		min=arr[i];
		pos=i;
		for(j=i+1;j<n;j++){
			if(arr[j]<min){
				min=arr[j];
				pos=j;
			}
		}
		temp=arr[i];
		arr[i]=arr[pos];
		arr[pos]=temp; 
	}
}

//Merge sort
void mergeSort(int* arr,int l,int r){
	if (l<r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 		merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

//Heap sort
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(&arr[0], &arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

//Counting sort
void countingSort(int* arr,int n,int max){
	int* C=(int*)malloc(n*sizeof(int));
	int i,j;
	for(i=0;i<max;i++)
		C[i]=0;

	for(i=0;i<n;i++)
		C[arr[i]-1]++;

	for(i=0;i<n;i++)
		for(j=1;j<=C[i];j++)
			arr[i++]=i+1;
}

//Quick sort
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low-1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}
 
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[pi] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//Function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

//displaying the array
void display(int* arr,int n){
	int i=0;
	for(;i<10;i++)
		printf("%d    ",arr[i]);
	printf("\n");
}