#include<stdio.h>
#include<conio.h>
#include<math.h>
void rpoly(int*, int);
void epoly(int*, int);
void derivative(int *, int);
void mul(int*, int);
main()
{
      int order, *p, row,sum;
      printf("enter order of poly: ");
      scanf("%d", &order);
      row=order+1;
      p=malloc(row*sizeof(int));
      rpoly(p, order);
      /*epoly(p, order);*/
      /*derivative(p, order);*/
      mul(p,order);
      
      
      getch();
      }

void rpoly(int *p, int order)
{
     int i;
     printf("\nenter coefficient(from higher order to lower) ");
     for(i=order; i>=0; i--)
     {
	  			  printf("\nenter coffi for %d th order: ", i);
             scanf("%d", &p[i]);
             }
             
     printf("\nentered poly is: \n");
     for(i=order;i>=0;i--)
     {
             if(p[i]>0 && i>0)
             {
                       printf(" %dx^%d+",p[i],i);
                       }
             if(p[i]<0 && i>0)
             {
                       printf(" (%d)x^%d+",p[i],i);
                       }
             
             if(i==0)
             {
                         printf("%d", p[i]);
                         }
                         }
                         }
                         
void derivative(int *p, int order)
{
 	 int a[50], x, i;
 	 for(i=0; i<=order;i++)
 	 {
	  
	  x=p[i]*i;
	  a[i-1]=x;
	  }
	  printf("\nderivative: ");
	  for(i=order-1;i>=0;i--)
	  {
	   					 if(a[i]>0 && i>0)
             			 {
                       	  		   printf(" %dx^%d+",a[i],i);
                       			   }
  					   if(a[i]<0 && i>0)
             		   {
                       			 printf(" (%d)x^%d+",a[i],i);
                       			 }
             
		                if(i==0)
       					 {
      		  		 	  		printf("%d", a[i]);
                         				 }	 
										 }
										 }
             
void mul(int *p, int order)
{
 	 int *q,*a,order1, n, max,i,j,temp,r1,r2,e;           
     printf("\n\nenter order of 2nd poly: ");
      scanf("%d", &order1);       
      n=order1+1;
	  q=malloc(n*sizeof(int));
	  
	  printf("\nenter data for 2nd poly");
	  
	  rpoly(q, order1);
	  
	  temp=order+order1+1;
	  a=malloc(temp*sizeof(int));
	  for(i=0;i<temp;i++)
	  {
	   					 a[i]=0;
						 }
	  
   for(i=order; i>=0;i--)
   {
   				for(j=order1;j>=0;j--)
   				{
				 		r1=p[i];
						 r2=q[j];
		 				 r1=r1*r2;
				 		e=i+j;
				 		a[e]=a[e]+r1;
						}
						}
		printf("\nafter multiplication:");
		
		for(i=temp-1;i>=0;i--)
	  {
	   					 if(a[i]>0 && i>0)
             			 {
                       	  		   printf(" %dx^%d+",a[i],i);
                       			   }
  					   if(a[i]<0 && i>0)
             		   {
                       			 printf(" (%d)x^%d+",a[i],i);
                       			 }
             
		                if(i==0)
       					 {
      		  		 	  		printf("%d", a[i]);
                         				 }	 
										 }
										 }
		
		
		
   				
void epoly(int *p, int order)
{
     float x,k,sum=0;
     int i;
     printf("\nenter value of x: ");
     scanf("%f", &x);
     for(i=order;i>=0;i--)
     {
                     k=p[i]*pow(x,i);
                     sum=sum+k;
                     }
     printf("\nafter evaluation the result is: %f", sum);
     }
