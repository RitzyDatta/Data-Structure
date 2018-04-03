#include<stdio.h>
#include<conio.h>

struct node
{
       int info;
       struct node *link;
       };

void insert_any(struct node ** , int,int );
void create_node(struct node **);
void display(struct node **);
int count_node(struct node *);
void del_any(struct node **, int);
void concat(struct node **, struct node **);

main()
{
      struct node *last, *last1, *q;
      int choice, m,n,pos, i, ch, a=0;
      last=NULL;
      last1=NULL;
      

      while(1)
      {
           printf("\n\n1: create node: ");
           printf("\n2: insert at any position: ");
           
           printf("\n3: delete any position: ");
           
           printf("\n4: display ");
           printf("\n5: count the number of nodes");
           
           printf("\n6: concatenate two linked list");
           printf("\n7: exit:\n\n");
           printf("\nenter your choice");
           
           scanf("%d", &choice);
      
      switch(choice)
      {
                case 1:
                     create_node(&last);
                     
                     break;
                case 2:
                       q=last;
                       printf("\nenter the element: ");
                       scanf("%d", &m);
                       printf("\nenter the position: ");
                       scanf("%d", &pos);
                       
                       insert_any(&last,m,pos);
                        break;
                        
                        
                             
                        case 3:
                             if(last==NULL)
                             {
                                            printf("\nlist is empty\n");
                                            break;
                                            }
                             
                             printf("\nenter the position of element you want to delete: ");
                             scanf("%d", &pos);
                            
                                 del_any(&last,pos);
                             break;
                             
                        case 4:
                             display(&last);
                             break;
                             
                        case 5:
                             m=count_node(last);
                             printf("\nthe total nodes are= %d", m);
                             break;
                            
                        case 6:
                             printf("\nenter some nodes to create another linked list:\n");
                             printf("\nhow many nodes you want to insert: ");
                             scanf("%d", &a);
                             for(i=1;i<=a;i++)
                                create_node(&last1);
                             concat(&last, &last1);
                             break;   
                                                    
                        case 7:
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
     
     if(*r==NULL)
     {
                 *r=tmp;
                 tmp->link=*r;
                 }
     else
     {
         q=*r;
         tmp->link=q->link;
         q->link=tmp;
         *r=tmp;
         }
         }
         
void display(struct node **r)
{
     struct node *q;
     
     if(*r==NULL)
     {
                 printf("\nlist is empty\n");
                 return;
                 }
     q=(*r)->link;
     printf("\nlist is:\n");
     
     while(q!=*r)
     {
                 printf("%d\t", q->info);
                 q=q->link;
                 }
     printf("%d\t\n", q->info);
     printf("\n");
     }
     
int count_node(struct node *r)
{
    if(r==NULL)
    {
               printf("\nlist is empt y\n");
               return;
               }
    int count=1;
    struct node *q;
    q=r->link;
    while(q!=r)
    {
               count++;
               q=q->link;
               }
    return(count);
}

void insert_any(struct node **p, int data, int pos)
{
     struct node *temp, *q;
     int i;
     q=(*p)->link;
     if(*p==NULL)
     {
                 printf("\nvoid insertion");
                 return;
                 }
     temp=malloc(sizeof(struct node));
     temp->info=data;
     
     if(pos==1)
     {
               temp->link=(*p)->link;
               (*p)->link=temp;
               }
     else
     {
         for(i=0;i<pos-2;i++)
         {
                             q=q->link;
                             
                             if(q==(*p)->link)
                             {
                                              printf("\nthere are less than %d elements", pos);
                                              return;
                                              }
                                              }
         temp->link=q->link;
         q->link=temp;
         if(q==*p)
           *p=temp;
           }
           }
           
void del_any(struct node **r, int pos)
{
 	 printf("\nin delete func");
     struct node *temp, *p;
     int i;
     
     if((*r)->link==*r && pos==1)
     {
	  				   
                       temp=*r;
                       *r=NULL;
                       
                       free(temp);
                       return;
                       }
     p=(*r)->link;
     
     if(pos==1)
     {
               (*r)->link=p->link;
               free(p);
               }
     else
     {
         for(i=0;i<pos-2;i++)
         {
                             p=p->link;
                             if(p==(*r)->link)
                             {
                                              printf("\nthere are less than %d elements\n", pos);
                                              getch();
                                              return;
                                              }
                                              }
         if(p->link==*r)
         {
                        temp=p->link;
                        p->link=temp->link;
                        *r=p;
                        free(temp);
                        }
         else
         {
             temp=p->link;
             p->link=temp->link;
             free(temp);
             }
             }
             }
             
void concat(struct node **p1, struct node **p2)
{
     struct node *p;
     if(*p2== NULL)
              return;
     if(*p1==NULL)
     {
                  *p1=*p2;
                  return;
                  }
     
     p=(*p2)->link;
     (*p2)->link=(*p1)->link;
     (*p1)->link=p;
     *p1=*p2;
     }
     
