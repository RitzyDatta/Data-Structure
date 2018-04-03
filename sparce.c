#include<stdio.h>
#include<conio.h>
int** create(int, int);
void input(int**, int, int);
void output(int**,int,int);
int** sparce(int**, int, int, int);
int** trans(int**, int, int, int);
main()
{
     int **mat1, **mat2, **t;
     int row, col,i,j, count=0;
     printf("enter order of matrix:");
     scanf("%d %d", &row, &col);
     mat1=create(row, col);
     input(mat1, row, col);
     for(i=0;i<row; i++)
     {
                    for(j=0;j<col;j++)
                    {
                                      if(mat1[i][j]!=0)
                                      count++;
                                      }
                                      }
     int k=count+1;
     if((row*col)>(count+1)*3)
     {
     mat2=sparce(mat1, row, col, count);
     printf("\ncompressed representation of sparce matrix:\n ");
     output(mat2, k, 3);
     
     t=trans(mat2,row, col, count);
     printf("\ntranspose of that sparce matrix: ");
     output(t, k, 3);
     }
     else
     {
         printf("\nno need to create compressed representation");
         getch();
         exit(1);
         }
     getch();
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
                              
int** sparce(int**mat1,int row, int col, int count)
{
      int** mat2,k=1, i,j;
      int m=count+1;
      mat2=create(m,3);
      mat2[0][0]=row;
      mat2[0][1]=col;
      mat2[0][2]=count;
      for(i=0; i<row; i++)
      {
              for(j=0;j<col;j++)
              {
                                if(mat1[i][j]!=0)
                                {
                                                 mat2[k][0]=i;
                                                 mat2[k][1]=j;
                                                 mat2[k][2]=mat1[i][j];
                                                 k++;
                                                 }
                                                 }
                                                 }
      return(mat2);
      }

int** trans(int** mat2, int row, int col, int count)
{
      int** t,i,j, *temp;
      int m=count+1;
      t=create(m,3);
      t[0][0]=col;
      t[0][1]=row;
      t[0][2]=count;
      for(i=1;i<m;i++)
      {
                      t[i][0]=mat2[i][1];
                      t[i][1]=mat2[i][0];
                      t[i][2]=mat2[i][2];
                      }
      for(i=1;i<m;i++)
      {
                      for(j=i+1;j<m;j++)
                      {
                                        if(t[i][0]>t[j][0] || t[i][0]==t[j][0] && t[i][1]>t[j][1])
                                        {
                                                           temp=t[i];
                                                           t[i]=t[j];
                                                           t[j]=temp;
                                                           }
                                                           }
                                                           }
      return(t);
      }
