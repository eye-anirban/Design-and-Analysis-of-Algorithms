/******************************************************************************

Q. Implement INSERTION SORT on randomly generated arrays . Find running time for 
   5 different input sizes . Implement separately for best case and worst case .
   Draw respective graphs .

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

void Insertion_asc(int A[],int n)
{
 int i,j,x;
 
 for(i=1;i<n;i++)
 {
 j=i-1;
 x=A[i];
 while(j>-1 && A[j]>x)
 {
 A[j+1]=A[j];
 j--;
 }
 A[j+1]=x;
 }
}

void Insertion_desc(int A[],int n)
{
 int i,j,x;
 
 for(i=1;i<n;i++)
 {
 j=i-1;
 x=A[i];
 while(j>-1 && A[j]<x)
 {
 A[j+1]=A[j];
 j--;
 }
 A[j+1]=x;
 }
}

int main()
{
	struct timeval t0,t1,t2,t3 ;
	float elapsed1 , elapsed2 ;
    int n , i ;
    printf("Enter the size of the arrays : ");
    scanf("%d",&n);
    int arr1[n] , arr2[n] ; 
    
    for(i=0;i<n;i++)
    {
        arr1[i]=rand();
        arr2[i]=rand();
    }
    
    Insertion_asc(arr1,n);
    Insertion_desc(arr2,n);
    
    gettimeofday(&t0, 0);
    Insertion_asc(arr1,n);
    gettimeofday(&t1, 0);
    elapsed1 = timedifference_msec(t0, t1);
    printf("\nSorted Array after BEST CASE : ") ;
    for(i=0;i<n;i++)
    printf("%d ",arr1[i]);
    printf("\n");
    
    gettimeofday(&t2, 0);
    Insertion_asc(arr2,n);
    gettimeofday(&t3, 0);
    elapsed2 = timedifference_msec(t2, t3);
    printf("\nSorted Array after WORST CASE : ") ;
    for(i=0;i<n;i++)
    printf("%d ",arr2[i]);
    printf("\n\n");
    
    printf("Code executed in %f milliseconds in BEST CASE .\n", elapsed1);
    printf("Code executed in %f milliseconds in WORST CASE .\n", elapsed2);
    return 0;
}
