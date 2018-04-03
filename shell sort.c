#include<stdio.h>
#include<conio.h>

void shellsort(int a[], int);
void sortInterval(int a[], int ,int, int);

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
      shellsort(a,n);
      printf("\nafter sorting- \n");
      for(i=0;i<n;i++)
      {
                      printf("%d ", a[i]);
                      }
      getch();
      }
      
void shellsort(int a[], int n)
{
     int incre, start;
     incre=n;
     do{
             incre=incre/3 +1;
             for(start=0;start<incre;++start)
                 sortInterval(a,n,start, incre);
                 }
             while(incre>1);
             }
             
void sortInterval(int a[], int n, int start, int incre)
{
     int i, temp, j;
     for(i=start+incre;i<n; i=i+incre)
     {
                            temp=a[i];
                            for(j=i-incre;j>=0 && a[j]>temp; j=j-incre)
                                               a[j+incre]=a[j];
                            a[j+incre]=temp;
                            }
                            }
