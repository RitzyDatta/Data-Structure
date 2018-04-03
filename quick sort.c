#include<stdio.h>
#include<conio.h>

void quicksort(int a[], int,int);
int partition(int b[], int, int);

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
      quicksort(a,low,n-1);
      printf("\n\nafter sorting-> \n");
      for(i=0;i<n;i++)
      {
                      printf("%d ", a[i]);
                      }
      getch();
      }
void quicksort(int a[], int low, int high)
{
     
     int pivot;
     if(low<high)
     {
                 pivot=partition(a,low,high);
                 quicksort(a, low,pivot-1);
                 quicksort(a,pivot+1,high);
                 }
                 }
     
int partition(int b[], int low, int high)
{
    
     int pivot, i, lastsmall, temp;
     int mid=(low+high)/2;
     temp=b[mid];
     b[mid]=b[low];
     b[low]=temp;
     
     pivot=b[low];
     lastsmall=low;
     
     for(i=(low+1); i<=high;++i)
         if(b[i]<pivot)
         {
                       lastsmall++;
                       temp=b[i];
                       b[i]=b[lastsmall];
                       b[lastsmall]=temp;
                       }
     b[low]=b[lastsmall];
     b[lastsmall]=pivot;
     
     return lastsmall;
     }
