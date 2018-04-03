#include<stdio.h>
#include<conio.h>

struct node
{
       int info;
       struct node *link;
       };

void append(struct node **, struct node **, int);
void display(struct node *);
int serve(struct node **, int *);

main()
{
 	  struct node *front,*rear, *q;
 	  int choice,x, ch, flag;
      front=NULL;
      rear=NULL;
      
       
      while(1)
      {
              printf("\n1:append\n2:serve\n3:display\n4:quit");
              printf("\nenter your choice:\n");
              scanf("%d", &choice);
              switch(choice)
              {
                            case 1:
                                 {
                                               printf("\nenter the element to be inserted: ");
                                               scanf("%d", &x);
                                               append(&front, &rear, x);
                                               break;
                                               }
                            case 2:
                                 {
                                               flag=1;
                                               x=serve(&front, &flag);
                                               if(flag)
                                               {
                                               printf("\nthe deleted item is %d", x);
                                               }
                                               break;
                                               } 
                            case 3:
                                 {
                                               display(front);
                                               break;
                                               }
                            case 4:
                                 exit(1);
                            default:
                                    printf("wrong choice:\n");
                                    }
                                    }
              getch();
              }
              
              
void append(struct node **f, struct node **r, int x)
{
     struct node *tmp;
     tmp=malloc(sizeof(struct node));
     tmp->info=x;
     tmp->link=NULL;
     
    if(*f==NULL)		 /*If Queue is empty*/
		*f=tmp;
	else
		(*r)->link=tmp;
	*r=tmp;
     }
     
     
int serve(struct node **f, int *y)
{
    struct node *tmp;
    int ele;
    if(*f == NULL)
    {
		printf("Queue Underflow\n");
		 return(*y=0);
                 }
			
		tmp=*f;
		ele=tmp->info;
		*f=(*f)->link;
		free(tmp);
		return ele;
}     
     
     
     
 void display(struct node *f)
      {
           
           if(f==NULL)
           {
                      printf("\nlist is empty");
                      return;
                      }

                      
           printf("\nlist is:\n");
           while(f!=NULL)
           { 
                         printf("%d ", f->info);
                         f=f->link;
                         }
           printf("\n");
                         }
