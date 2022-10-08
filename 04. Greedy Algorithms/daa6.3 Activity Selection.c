#include<stdio.h>

void swap ( int *a , int *b)
{
	int temp = *a ;
	*a = *b ;
	*b = temp ;
}

void Bubble_Sort(int A[],int n, int B[])
{
  int i ,j ;
  for (i=0 ; i<n-1 ; i++)
    {
	 for (j=0 ; j<n-i-1 ; j++)
	 {
	 	if (A[j]>A[j+1])
	 	{
	 		swap(&A[j],&A[j+1]);
	 		swap(&B[j],&B[j+1]);
		}
	 }
    }      
}

void Activity(int s[], int f[], int n)
{
    int i, j=0 , k=1 , sol[n];

    sol[0] = 0;
 
    for (i = 1; i < n; i++)
    {

      if (s[i] >= f[j])
      {
         sol[k++] = i ;
         j = i ;
      }
    }
    
    printf("\nThe selected activities are : \n") ;
    for(i=0 ; i<k ; i++)
    printf("%d ",sol[i]) ;
}
 
int main()
{
    int i,n;
    printf("Enter the number of activities : ");
    scanf("%d",&n);
    
    int s[n] , f[n];
    printf("Enter the Start time of activities : ");
    for(i=0;i<n;i++) scanf("%d",&s[i]) ;
    printf("Enter the Finish time of activities : ");
    for(i=0;i<n;i++) scanf("%d",&f[i]) ;
    
    Bubble_Sort(f,n,s) ;

    Activity(s, f, n);
    return 0;
}
