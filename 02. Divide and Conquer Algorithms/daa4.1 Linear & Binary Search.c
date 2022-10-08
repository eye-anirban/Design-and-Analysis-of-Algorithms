/******************************************************************************

Q . Implement recursive Binary search . Compare time taken with linear search 
    for different array sizes .

*******************************************************************************/
#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include <sys/time.h>

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

void swap(int *x,int *y)
{
 int temp=*x;
 *x=*y;
 *y=temp;
}
void Bubble(int A[],int n)
{
 int i,j,flag=0;
 
 for(i=0;i<n-1;i++)
 {
    flag=0;
    for(j=0;j<n-i-1;j++)
 {
    if(A[j]>A[j+1])
    {
        swap(&A[j],&A[j+1]);
        flag=1;
    }
 }
 if(flag==0)
 break;
 }
}

int LinearSearch(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int BinarySearch(int arr[], int item , int low , int high)
{
    if(low == high)
    {
        if(arr[low]==item) return low ; 
        else return -1 ;
    }
    else
    {
        int mid = (low+high)/2;
        if (arr[mid] == item) return mid;
        else if(arr[mid] > item ) return BinarySearch(arr, item, low, mid-1);
        else return BinarySearch(arr, item, mid+1, high);
    }
}

int main()
{
    struct timeval t0,t1,t2,t3 ;
	float elapsed1, elapsed2 ;
    int n , i , item , p , q ;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    int arr1[n] , arr2[n] ; 
    
    for(i=0;i<n;i++)
    {
        arr1[i]=rand()%n;
    }
    
    for(i=0;i<n;i++)
    {
       arr2[i]=arr1[i]; 
    }
    
    Bubble(arr2,n);
    
    printf("\nEnter element to be searched : "); 
    scanf("%d",&item);
    
    gettimeofday(&t0, 0);
    p = LinearSearch(arr1,n,item);
    gettimeofday(&t1, 0);
    elapsed1 = timedifference_msec(t0, t1);
    printf("The element is found at index : %d after linear search\n", p);
    printf("\nLinear Search executed in %f milliseconds.\n", elapsed1);
    
    gettimeofday(&t2, 0);
    q = BinarySearch(arr2,item,0,n-1);
    gettimeofday(&t3, 0);
    elapsed2 = timedifference_msec(t2, t3);
    printf("The element is found at index : %d after binary search\n", q);
    printf("\nBinary Search executed in %f milliseconds.\n", elapsed2);
    
    return 0;
}
