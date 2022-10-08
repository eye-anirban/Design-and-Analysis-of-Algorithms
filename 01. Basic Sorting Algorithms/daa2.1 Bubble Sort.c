/*

 Q . Implement bubble sort on an array with random inputs . Find the running 
     time for different input sizes (10k .... 50k)

*/
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

int main()
{
	struct timeval t0,t1 ;
	float elapsed ;
    int n , i ;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    int arr[n] ; 
    
    for(i=0;i<n;i++)
    arr[i]=rand();
    
    gettimeofday(&t0, 0);
    Bubble(arr,n);
    gettimeofday(&t1, 0);
    elapsed = timedifference_msec(t0, t1);
    printf("\nSorted Array : ") ;
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
    printf("\n");
    
    printf("Code executed in %f milliseconds.\n", elapsed);
    
    return 0;
}
