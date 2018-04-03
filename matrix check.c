#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int upper(int**, int, int);
int lower(int**,int,int);
int tri_diagonal(int**,int,int);
int diagonal(int**, int, int);
int identity(int** , int, int);
int** create(int, int);
void input(int**, int, int);
void output(int**,int,int);
int main()
{
    int **a,i,j,row, col,opt;
    printf("\nenter row and column:\n");
    scanf("%d %d", &row, &col);
    a= create(row, col);
    printf("\nenter inputs:");
    input(a, row, col);
    
    if(upper(a,row, col)==1)
    {
                    printf("\nit is upper triangilar");
                    }
    if(lower(a,row,col)==1)
    {
                           printf("\nit is lower triangular");
                           }
    if (tri_diagonal(a,row, col)==1)
    {
                            printf("\nit is tri-diagonal");
                            }
    if (diagonal(a,row,col)==1)
    {
                               printf("\nit is diagonal");
                               }
     if (identity(a,row,col)==1)
    {
                               printf("\nit is identity matrix");
                               }
                               
   getch();
   return 0;
}
int** create(int r, int c)
{
      int** mat, i;
      mat= malloc(r*sizeof(int*));
      for(i=0;i<r;i++)
         mat[i]=malloc(c*sizeof(int));
      return(mat);
      }

void input(int** mat, int r, int c)
{
      int i,j;
      printf("\nenter the value one by one:");
      for(i=0;i<r;i++)
      {
         for(j=0;j<c;j++)
            scanf("%d",mat[i]+j);
         printf("\n");
         }
      printf("\nthe matrix is:\n");
      output(mat, r, c);
         }
void output(int** res, int r, int c)
{
     int i,j;
     printf("matrix:\n");
     for(i=0; i<r; i++)
     {
              for(j=0;j<c;j++)
              {
                              printf("%d\t", *(*(res+i)+j));
                              }
              printf("\n");
                              }
                              }
                     
     
int upper(int** b, int r, int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(i>j && b[i][j]!=0)
            {
                    return (0);
                    }
                    }
                    }
    return (1);
}

int lower(int** b, int r, int c)
{
    int i, j;
     for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
                        if(i<j && b[i][j]!=0)
                        {
                               return (0);
                               }
                               }
                               }
        return(1);
        }
    
int tri_diagonal(int** b, int r, int c)
{
     int i, j;
     for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
                        if(abs(i-j)>1 && b[i][j]!=0)
                        {
                                      return (0);
                                      }
                                      }
                                      }
    return(1);
}

int diagonal(int** b, int r, int c)
{
     int i, j;
     for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
                        if(i!=j && b[i][j]!=0)
                        {
                                return 0;
                                }
                                }
                                }
        return (1);
        }

int identity(int** b, int r, int c)
{
 	int i, j;
     for(i=0;i<r;i++)
     {
        for(j=0;j<c;j++)
        {
                        if((i==j && b[i][j]!=1) || (i<j && b[i][j]!=0) || (i>j && b[i][j]!=0))
                        {
                                return 0;
                                }
                                }
                                }
        return (1);
        }
 	
