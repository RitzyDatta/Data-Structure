#include<stdio.h>
#include<conio.h>

void radix(int a[], int);

main()
{
      int i, n, a[50];
      printf("\nenter array size: ");
      scanf("%d", &n);
      
      printf("\nenter elements one by one(3 digits)\n");
      for(i=0;i<n;i++)
      {
                      scanf("%d", &a[i]);
                      }
      radix(a,n);
      printf("\n\nafter sorting-> \n");
      for(i=0;i<n;i++)
      {
                      printf("%d ", a[i]);
                      }
      getch();
      }
      
void radix(int a[], int n)
{
     int y, b, c, temp, l, x=1, i, j;
     int pocket[10][10];
     for(i=0;i<10;i++)
     {
                      for(j=0;j<10;j++)
                        pocket[i][j]=-9999;
                        }
     int k=3;
     for(k=1;k<=3;k++)
     {
                      for(l=0;l<n;l++)
                      {
                                      temp=(a[l]/x)%10;
                                      pocket[temp][l]=a[l];
                                      }
                      x=x*10;
                      c=0;
                      for(y=0;y<10;y++)
                      {
                                       for(b=0;b<10;b++)
                                       {
                                                        if(pocket[y][b]!=-9999)
                                                        {
                                                                               a[c]=pocket[y][b];
                                                                               c++;
                                                                               }
                                                                               }
                                                                               }
                      printf("\n\nafter %d pass->\n", k);
                      for(i=0;i<n;i++)
                      {
                                      printf("%d ", a[i]);
                      }
                      
                       for(i=0;i<10;i++)
                       {
                                        for(j=0;j<10;j++)
                                        pocket[i][j]=-9999;
                        }
                        }
                        }
