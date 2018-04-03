#include<stdio.h>
#include<conio.h>

void insert(int a[], int);

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
      insert(a,n);
      printf("\n\nafter sorting-> \n");
      for(i=0;i<n;i++)
      {
                      printf("%d ", a[i]);
                      }
      getch();
      }
      
void insert(int a[], int n)
{
     int i,j, k,temp;
     for(i=1;i<n;i++)
     {
                     temp=a[i];
                     for(j=i-1;j>=0 && a[j]>temp; --j)
                        a[j+1]=a[j];
                     a[j+1]=temp;
                     
                     printf("\nafter %dth pass->\n",i);
                     for(k=0;k<n;k++)
                     {
                                     printf("%d ", a[k]);
                      }
                     }
                     }
