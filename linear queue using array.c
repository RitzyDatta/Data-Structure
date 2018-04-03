#include<stdio.h>
#include<conio.h>
#define MAX 100
struct queue
{
       int front;
       int rear;
       int item[MAX];
       };
       
void append(struct queue *, int);
void display(struct queue *);
int serve(struct queue *, int *);
main()
{
      int flag;
      struct queue q;
      q.front=-1;
      q.rear=-1;
      int choice, x;
      
      while(1)
      {
              printf("\n1:append\n2:serve\n3:display\n4:quit");
              printf("\nenter your choice:\n");
              scanf("%D", &choice);
              switch(choice)
              {
                            case 1:
                                 {
                                               printf("\nenter the element to be inserted: ");
                                               scanf("%d", &x);
                                               append(&q, x);
                                               break;
                                               }
                            case 2:
                                 {
                                               flag=1;
                                               x=serve(&q, &flag);
                                               if(flag)
                                               {
                                               printf("\nthe poped item: %d", x);
                                               }
                                               break;
                                               }
                            case 3:
                                 {
                                               display(&q);
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
              
int empty(struct queue *pq)
{
    if(pq->front==pq->rear)
    return 1;
    else
    return 0;
}

int serve(struct queue *pq, int *y)
{
    int element;
    if(empty(pq))
    {
                 printf("underflow");
                 return(*y=0);
                 }
    pq->front=pq->front+1;
    element=pq->item[pq->front];
    return element;
}

void append(struct queue *pq, int x)
{
     if(pq->rear==(MAX-1))
     {
                          printf("overflow");
                          getch();
                          exit(1);
                          }
     pq->rear=pq->rear+1;
     pq->item[pq->rear]=x;
     return;
     }
     
void display(struct queue *pq)
{
     int i;
     if(empty(pq))
                  printf("\nqueue is empty");
     else
     {
         printf("\nqueue elements:\n");
         for(i=pq->front+1;i<=pq->rear;i++)
             printf("%d ", pq->item[i]);
         printf("\n");
         }
         
         }
         
