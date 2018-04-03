#include<stdio.h>
#include<conio.h>

void selection(int a[], int);

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
      selection(a,n);
      printf("\n\nafter sorting-> \n");
      for(i=0;i<n;i++)
      {
                      printf("%d ", a[i]);
                      }
      getch();
      }
      
void selection(int a[], int n)

{
     int i,j,k,temp,max;
     for(i=n-1; i>0; --i)
     {
                max=0;
                for(j=1;j<=i;j++)
                   if(a[j]>a[max])
                       max=j;
                temp=a[max];
                a[max]=a[i];
                a[i]=temp;
                
                int c=1;
                printf("\n\nafter %dth pass->\n",c);
                for(k=0;k<n;k++)
                {
                      printf("%d ", a[k]);
                      }
                c++;
                }
                }
                
