#include<stdio.h>
#include<conio.h>



struct node
{
       int info;
       struct node *link;
       };
       
int linear_search(int a[], int);
void create_node(struct node **);
int linear_search_linked(struct node *);

main()
{
      int a[50],i,n, choice,pos;
      struct node *start;
      start=NULL;
      
      while(1)
      {
           printf("\n\n1: linear search on array ");
           printf("\n2: linear search in a singly linked list ");
           printf("\n3: binary search");
           printf("\n4: exit");
           printf("\nenter your choice\n");
           scanf("%d", &choice);
           
            switch(choice)
            {
                case 1:
                     printf("\nenter some data one by one for array");
                     printf("\nhow many data you want to insert");
                     scanf("%d", &n);
                     printf("\nenter data one by one");
                     for(i=0;i<n;i++)
                     {
                                     scanf("%d",&a[i]);
                                     }
                     pos=linear_search(a, n);
                     
                     if(pos==-1)
                     {
                                printf("\ndata not found");
                                }
                     else
                     {
                         printf("\ndata is found. the position is %d", pos+1);
                         }
                     
                     
                     break;
                case 2:
                     printf("\nyou have to enter some nodes before you proceed");
                     printf("\nhow many nodes you want to enter");
                     scanf("%d", &n);
                     for(i=0;i<n;i++)
                     {
                                     create_node(&start);
                                     }
                     pos=linear_search_linked(start);
                     
                     if(pos==-1)
                     {
                                printf("\ndata not found");
                                }
                     else
                     {
                         printf("\ndata is found. the position is %d", pos+1);
                         }
                     
                                               
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
                            pos=binary_search(a, n);
                     
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

void create_node(struct node **r)
      {
           int data;
           printf("\nenter data of the node: ");
           scanf("%d", &data);
           
           struct node *q, *tmp;
           tmp=malloc(sizeof(struct node));
           tmp->info=data;
           tmp->link=NULL;
           
           if(*r==NULL)
              *r=tmp;
           else
           {
               q=*r;
               while(q->link!=NULL)
                  q=q->link;
               
               q->link=tmp;;
                  }
                  }

int linear_search(int a[], int n)
{
     int i,key;
     printf("\nenter the data you want to find: ");
     scanf("%d",&key);
     
     for(i=0;i<n;i++)
     {
                     if(a[i]==key)
                        return i;
                        }
     return -1;
     }
     
int linear_search_linked(struct node *r)
{
    int i=0, key;
    printf("\nenter the element you want to find");
    scanf("%d", &key);
    
      
     while(r!=NULL)
     {
                   if(r->info==key)
                     return i;
                   i++;
                   r=r->link;
                        }
     return -1;
     }

int binary_search(int info[], int n)
{
     int i,key, bottom, mid, top;
     printf("\nenter the data you want to find: ");
     scanf("%d",&key);
     
     bottom=0;
     top=n-1;
     while((bottom<=top))
     {
                         mid=(bottom+top)/2;
                         if(key==info[mid])
                            return mid;
                         else
                         if(key<info[mid])
                              top=mid-1;
                         else
                         bottom=mid+1;
                         }
     return -1;
     }
     
    
