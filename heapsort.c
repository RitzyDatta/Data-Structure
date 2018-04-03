#include<stdio.h>
#include<conio.h>

void heapsort(int a[], int);
void insertheap(int, int, int, int a[]);
void buildheap(int a[], int);

main()
{
      int i, n, a[50];
      printf("\nenter array size: ");
      scanf("%d", &n);
      
      printf("\nenter elements one by one\n");
      for(i=0;i<n;i++)
      {
                      scanf("%d", &a[i]);
                      }
      heapsort(a,n);
      printf("\n\nafter sorting-> \n");
      for(i=0;i<n;i++)
      {
                      printf("%d ", a[i]);
                      }
      getch();
      }

void heapsort(int a[], int n)
{
     int current,k;
     int lu;
     buildheap(a,n);
     
     
     for(lu=n-1;lu>0;--lu)
     {
                          current=a[lu];
                          a[lu]=a[0];
                          insertheap(current, 0, lu-1, a);
                          
                          int c=1;
                          printf("\n\nafter %dth pass->\n",c);
                          for(k=0;k<n;k++)
                          {
                                          printf("%d ", a[k]);
                                          }
                          c++;
                          }
                          }
                          
void buildheap(int a[], int n)
{
     int low;
     for(low=n/2-1; low>=0; --low)
     {
                    insertheap(a[low],low,n-1,a);
                    }
                    }
                          
void insertheap(int current, int low, int high, int a[])
{
     int large;
     large=2*low+1;
     while(large<=high)
     {
                       if(a[large]<a[large+1] && large<high)
                           large=large+1;
                       if(current>=a[large])
                           break;
                       else
                       {
                           a[low]=a[large];
                           low=large;
                           large=2*low+1;
                           }
                           }
    a[low]=current;
     }
     
