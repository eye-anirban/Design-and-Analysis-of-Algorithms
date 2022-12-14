#include <stdio.h>

void insertionSortRecursive(int arr[], int n)
{
	if (n <= 1) return;

	insertionSortRecursive(arr, n - 1);

	int last = arr[n - 1];
	int j = n - 2;

	while (j >= 0 && arr[j] > last) 
	{
		arr[j + 1] = arr[j];
		j--;
	}
	arr[j + 1] = last;
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
    int n , i ;
    printf("Enter the size of the array : ") ;
    scanf("%d", &n) ;
    int arr[n] ;
    printf("\nEnter the array elements : ") ;
    for( i=0 ; i<n ; i++ )
    {
        scanf("%d", &arr[i]) ;
    }
    
	insertionSortRecursive(arr, n);
	printArray(arr, n);
	
	return 0;
}
