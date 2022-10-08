#include<stdio.h>
#include<stdlib.h>

void Merge(int A[],int l,int mid,int h)
{
 int i=l,j=mid+1,k=l,q;
 int B[100];
 
 while(i<=mid && j<=h)
 {
 if(A[i]<A[j])
 B[k++]=A[i++];
 else
 B[k++]=A[j++];
 }

 if(i>mid)
    for(q=j ; q<=h ; q++) B[k++]=A[q] ;
 else 
    for(q=i ; q<=mid ; q++) B[k++]=A[q] ;
    
 for(i=l;i<=h;i++)
 A[i]=B[i];
}

void MergeSort(int A[],int l,int h)
{
 int mid;
 if(l<h)
 {
 mid=(l+h)/2;
 MergeSort(A,l,mid);
 MergeSort(A,mid+1,h);
 Merge(A,l,mid,h);
 }
}

int main()
{
 int n,i;
 printf("Enter size of array : ");
 scanf("%d",&n);
 int A[n];
 printf("Enter array elements : ");
 
 for(i=0;i<n;i++)
 scanf("%d",&A[i]);
 
 MergeSort(A,0,n-1);
 
 for(i=0;i<n;i++)
 printf("%d ",A[i]);
 printf("\n");
 
 return 0;
}
