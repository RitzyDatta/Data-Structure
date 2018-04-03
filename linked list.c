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
void insert_speci(struct node *, int);
void del_any(struct node **, int);
void del_speci(struct node **, int);
void rev(struct node **);
void concat(struct node **, struct node **);

main()
{
      struct node *start, *start1, *q;
      int choice, m,n,pos, i, ch, a=0;
      start=NULL;
      start1=NULL;
      

      while(1)
      {
           printf("\n\n1: create node: ");
           printf("\n2: insert at any position: ");
           printf("\n3: insert after specified element: ");
           printf("\n4: delete any position: ");
           printf("\n5: delete any specified element");
           printf("\n6: display ");
           printf("\n7: count the number of nodes");
           printf("\n8: reverse ");
           printf("\n9: concatenate two linked list");
           printf("\n10: exit:\n\n");
           
           scanf("%d", &choice);
      
      switch(choice)
      {
                case 1:
                     create_node(&start);
                     
                     break;
                case 2:
                       q=start;
                       printf("\nenter the element: ");
                       scanf("%d", &m);
                       printf("\nenter the position: ");
                       scanf("%d", &pos);
                       
                       if(pos==1)
                          insert_any(&start, m,pos);
                       else
                       {
                           for(i=0;i<pos-2 && q!=NULL; i++)
                              q=q->link;
                           insert_any(&q,m,pos);
                           }
                        break;
                        
                        case 3:
                             printf("\nenter the element after which you want to insert:");
                             scanf("%d", &m);
                             
                             
                             insert_speci(start, m);
                             break;
                        
                        case 4:
                             if(start==NULL)
                             {
                                            printf("\nlist is empty\n");
                                            break;
                                            }
                             q=start;
                             printf("\nenter the position of element you want to delete: ");
                             scanf("%d", &pos);
                             if(pos==1)
                               del_any(&start, pos);
                             else
                             {
                                 for(i=0;i<pos-2 && q!=NULL;i++)
                                    q=q->link;
                                 del_any(&q,pos);
                                 }
                             break;
                             
                        case 5:
                             if(start==NULL)
                             {
                                            printf("\nlist is empty\n");
                                            return;
                                            }
                             printf("\nenter the element to be deleted: ");
                             scanf("%d", &m);
                             del_speci(&start,m);
                             break; 
                        
                        case 6:
                             display(&start);
                             break;
                             
                        case 7:
                             m=count_node(start);
                             printf("\n total number of nodes= %d",m);
                             break;
                             
                             
                        case 8:
                             
                             rev(&start);
                             break;
                             
                        case 9:
                             printf("\nenter some nodes to create another linked list");
                             printf("\nhow many nodes you want to insert: ");
                             scanf("%d", &a);
                             for(i=1;i<=a;i++)
                               create_node(&start1);
                             
                             concat(&start, &start1);
                             break;
                        
                        case 10:
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
            
      
           
      void display(struct node **r)
      {
           struct node *q;
           if(*r==NULL)
           {
                      printf("\nlist is empty");
                      return;
                      }

                      
           q=*r;
           printf("\nlist is:\n");
           while(q!=NULL)
           { 
                         printf("%d\t", q->info);
                         q=q->link;
                         }
           printf("\n");
                         }
                         
                                
int count_node(struct node *r)
{
    int count=0;
    
    while(r!=NULL)
    {
                  count++;
                  r=r->link;
                  }
    return(count);
}


 void insert_any(struct node **p, int data, int pos)
      {
           struct node *tmp;
          if(*p==NULL)
          {
                     printf("\nvoid insertion");
                     return;
                     }
           
          tmp=malloc(sizeof(struct node));
          tmp->info=data;
          
          if(pos==1)
          {
                    tmp->link=*p;
                    *p=tmp;
                    }
          else
          {
              tmp->link=(*p)->link;
              (*p)->link=tmp;
              }
              }


void insert_speci(struct node *p,int data)
{
     
     int x;
     while(p->info!=data && p->link!=NULL)
       p=p->link;
       
     if(p->info==data)
     {
                      printf("\nenter the data of the node: ");
                      scanf("%d", &x);
                      struct node *temp;
                      
                      temp=malloc(sizeof(struct node));
                      temp->info=x;
                      temp->link=p->link;
                      p->link=temp;
                      }
                      
     else
        printf("\nelement not found\n");
        }
        
     
void del_any(struct node **r, int pos)
{
     struct node *temp,*p;
     p=*r;
     
     if(p==NULL)
     {
         printf("\nvoid deletion");
         return;
         }
         
     if(pos==1)
     {
               *r=p->link;
               free(p);
               }
               
     else
     {
         temp=p->link;
         p->link=temp->link;
         free(temp);
         }
         }
         
void del_speci(struct node **r, int x)
{
    struct node *p,*q,*temp;
    for(q=NULL, p=*r; p!=NULL && p->info!=x; q=p, p=p->link);
    
    if(p==NULL)
       printf("\n%d not in list", x);
    else
    {
        if(q==NULL)
        {
                   *r=p->link;
                   free(p);
                   }
        else
        {
           temp=q->link;
           q->link=temp->link;
           free(temp);
           }
           }
           }
           
void rev(struct node **r)
{
     struct node *prev, *cur, *next;
     prev=NULL;
     
     for(cur=*r; cur!=NULL; cur=next)
     {
                 next=cur->link;
                 cur->link=prev;
                 prev=cur;
                 }
     *r=prev;
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
     for(p=*p1;p->link!=NULL;p=p->link);
     
     p->link=*p2;
     }
     
                
