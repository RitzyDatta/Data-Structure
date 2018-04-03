#include<stdio.h>
#include<conio.h>

int fact(int);
int binary_search(int info[],int, int, int);
int findgcd(int, int);

main()
{
      int i, n1,n2, choice, num,f, gcd, a[50],n,key;
      int top, bottom,pos;
      
       while(1)
      {
           printf("\n\n1: factorial of an integer");
           printf("\n2: GCD of two number ");
           printf("\n3: binary search with recursion");
           printf("\n4: exit");
           printf("\nenter your choice\n");
           scanf("%d", &choice);
           
            switch(choice)
            {
                case 1:
                     printf("\nneter a number: ");
                     scanf("%d", &num);
                     f=fact(num);
                     printf("\nfactorial= %d", f);
                     
                     break;
                case 2:
                     printf("\nenter two numbers:");
                     scanf("%d %d", &n1, &n2);
                     gcd=findgcd(n1, n2);
                     printf("\nGCD is %d", gcd);
                     
                                      
                        break;
                        
                       case 3:
                            
                           printf("\nenter some data one by one for array");
                            printf("\nhow many data you want to insert");
                            scanf("%d", &n);
                            printf("\nenter data one by one");
                            for(i=0;i<n;i++)
                            {
                                     scanf("%d",&a[i]);
                                     }
                            top=n-1;
                            bottom=0;
                            
                            printf("\nenter the data you want to find: ");
                            scanf("%d",&key);
                            
                            pos=binary_search(a, key, bottom, top);
                     
                            if(pos==-1)
                            {
                                printf("\ndata not found");
                                }
                            else
                            {
                                printf("\ndata is found. the position is %d", pos+1);
                                }
                     
                             
                             break;
                        
                       case 4:
                             
                             exit(1);
                                   
                                               
                       
                default:
                        printf("\nwrong choice");
                        
                        }
                        }
getch();
}

int fact(int n)
{
    if(n==1 || n==0)
       return 1;
    else
       return(n*fact(n-1));
       }

int findgcd(int x, int y)
{
    while(x!=y)
    {
               if(x>y)
                 return findgcd(x-y,y);
               else
                   return findgcd(x,y-x);
                   }
     return x;
     }
            
int binary_search(int info[], int key, int bottom, int top)
{
     int i, mid;
     
     if(bottom>top)
        return -1;
        
     mid=(bottom+top)/2;
     
     if(key==info[mid])
             return mid;
     else
     if(key<info[mid])
         return binary_search(info, key, bottom, mid-1);
     else
         return binary_search(info, key, mid+1, top);
     

     }
