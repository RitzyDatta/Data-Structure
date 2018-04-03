#include<stdio.h>
#include<conio.h>

void mergesort(int a[], int,int);
void merge(int b[], int, int,int);

main()
{
      int i, n, a[50],low;
      low=0;
      printf("\nenter array size: ");
      scanf("%d", &n);
      
      printf("\nenter elements one by one\n");
      for(i=0;i<n;i++)
      {
                      scanf("%d", &a[i]);
                      }
      mergesort(a,low,n-1);
      printf("\n\nafter sorting-> \n");
      for(i=0;i<n;i++)
      {
                      printf("%d ", a[i]);
                      }
      getch();
      }
      
void mergesort(int a[], int low, int high)
{
     int mid;
     if(low<high)
     {
                 mid=low+(high-low)/2;
                 mergesort(a,low,mid);
                 mergesort(a,mid+1, high);
                 merge(a,low, mid, high);
                 }
                 }
                 
void merge(int a[], int low, int mid, int high)
{
     int i,k,j;
     int b[50];
     for(i=low;i<=high;i++)
        b[i]=a[i];
        
     i=low;
     j=mid+1;
     k=low;
     
     while(i<=mid && j<=high)
     {
                  if(b[i]<=b[j])
                  {
                                a[k]=b[i];
                                i++;
                                }
                  else
                  {
                      a[k]=b[j];
                      j++;
                      }
                  k++;
                  }
     while(i<=mid)
     {
                  a[k]=b[i];
                  i++;
                  k++;
                  }
                  }
