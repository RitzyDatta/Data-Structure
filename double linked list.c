#include<stdio.h>
#include<conio.h>

struct node
{
       int info;
       struct node *prev;
       struct node *next;
       };
void insert_any(struct node ** , int,int );
void create_node(struct node **);
void display(struct node **);
void del_any(struct node **, int);

main()
{
      struct node *start, *start1, *q;
      int choice, m,n,pos, i, ch, a=0;
      start=NULL;
      
      

      while(1)
      {
           printf("\n\n1: create node: ");
           printf("\n2: insert at any position: ");
           
           printf("\n3: delete any position: ");
           
           printf("\n4: display ");
          
           printf("\n5: exit:\n\n");
           printf("\nenter your choice");
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
                              q=q->next;
                           insert_any(&q,m,pos);
                           }
                        break;
                        
                        
                        
                       case 3:
                             if(start==NULL)
                             {
                                            printf("\nlist is empty\n");
                                            return;
                                            }
                             q=start;
                             printf("\nenter the position of element you want to delete: ");
                             scanf("%d", &pos);
                             if(pos==1)
                               del_any(&start, pos);
                             else
                             {
                                 for(i=0;i<pos-2 && q!=NULL;i++)
                                    q=q->next;
                                 del_any(&q,pos);
                                 }
                             break; 
                             
                        
                        
                        case 4:
                             display(&start);
                             break;
                             
                    
                        case 5:
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
           tmp->next=NULL;
           
           if(*r==NULL)
           {
                 tmp->prev=NULL;
                 
                 *r=tmp;
                 }
              
           else
           {
               q=*r;
               while(q->next!=NULL)
                  q=q->next;
               
               
               q->next=tmp;
               tmp->prev=q;
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
     printf("\nlist is: \n");
     while(q!=NULL)
     {
                  printf("%d\t", q->info);
                  q=q->next;
                  }
     printf("\n");
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
                    tmp->next=*p;
                    tmp->prev=NULL;
                    (*p)->prev=tmp;
                    *p=tmp;
                    }
                    
          else
          {
              tmp->next=(*p)->next;
              (*p)->next->prev=tmp;
              tmp->prev=*p;
              (*p)->next=tmp;
              }
              }

void del_any(struct node **r, int pos)
{
     
     struct node *temp,*q;
     q=*r;
     
     if(q==NULL)
     {
         printf("\nvoid deletion");
         return;
         }
         
     if(pos==1)
     {
               
               *r=q->next;
               if(*r!=NULL)
               {
               (*r)->prev=NULL;
               }
               free(q);
               
               return;
               }
               
     if(q->next->next==NULL)
     {
                      temp=q->next;
                      q->next=NULL;
                      free(temp);
                      return;
                      }
               
     
               

     else
     {
         
         temp=q->next;
         q->next=temp->next;
         temp->next->prev=q;
         
         free(temp);
         return;
         }
         }
