#include<stdio.h>
#include<conio.h>
int** create(int, int);
void input(int**, int, int);
int** multi(int**, int**, int, int);
void output(int**,int,int);
int main()
{
      int r1,r2,c1,c2, **mat1, **mat2, **pro;
      printf("enter order of first matrix:");
      scanf("%d %d", &r1, &c1);
      
      printf("\nenter order of second matrix:");
      scanf("%d %d", &r2, &c2);
      
      if(c1!=r2)
      {
                printf("\nmultiplication is not possible:");
                getch();
                exit(1);
                }
      mat1= create(r1, c1);
      printf("\nfor first matrix:");
      input(mat1, r1, c1);
      
      mat2= create(r2, c2);
      printf("\nfor second matrix:");
       input(mat2, r2, c2);
      pro=multi(mat1, mat2, r1, c2);
      printf("\n multiplication result:\n");
      output(pro, r1, c2);
      getch();
      return 0;
      }

int** create(int r, int c)
{
      int **mat, i;
      mat=malloc(r*sizeof(int*));
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
            scanf("%d", *(mat+i)+j);
         printf("\n");
         }
      printf("\nthe matrix is:\n");
      output(mat, r, c);
         }

int** multi(int** mat1, int** mat2, int r, int c)
{
     int **temp, i,j,k;
     temp=create(r,c); 
     for(i=0;i<r;i++)
     {
         for(j=0;j<c;j++)
         {
                      temp[i][j]=0;
                      for(k=0;k<c;k++)
                         temp[i][j]+=mat1[i][k]*mat2[k][j];
                         }
                         }
     return(temp);
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
                     
      
                   
