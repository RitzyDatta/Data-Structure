
#include<stdio.h>
#include<conio.h>
#define MAX 100
struct queue
{
       int front;
       int rear;
       int item[MAX];
       };
       

int serve_frnt(struct queue *, int *);
int serve_rear(struct queue *, int *);
void append_frnt(struct queue *, int );
void append_rear(struct queue *, int );
main()
{
      int flag;
      struct queue q;
      q.front=MAX-1;
      q.rear=MAX-1;
      int choice, x;
      
      while(1)
      {
              printf("\n1:append_rear\n2:serve_frnt\n3:append_frnt\n4:serve_rear\n5:quit\n");
              printf("\nenter your choice:\n");
              scanf("%d", &choice);
              switch(choice)
              {
                            case 1:
                                 {
                                               printf("\nenter the element to be inserted: ");
                                               scanf("%d", &x);
                                               append_rear(&q, x);
                                               break;
                                               }
                           case 2:
                                 {
                                               flag=1;
                                               x=serve_frnt(&q, &flag);
                                               if(flag)
                                               {
                                               printf("\nthe poped item: %d", x);
                                               }
                                               break;
                                               }
                            case 3:
                                 {
                                               printf("\nenter the element to be inserted: ");
                                               scanf("%d", &x);
                                               append_frnt(&q, x);
                                               break;
                                               }
                            case 4:
                                  {
                                               flag=1;
                                               x=serve_rear(&q, &flag);
                                               if(flag)
                                               {
                                               printf("\nthe poped item: %d", x);
                                               }
                                               break;
                                               }
                            case 5:
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

int serve_frnt(struct queue *pq, int *y)
{
    int x;
   if(empty(pq))
    {
                 printf("underflow");
                 return(*y=0);
                 }
    pq->front=(pq->front+1)%MAX;
    return pq->item[pq->front];
}

int serve_rear(struct queue *pq, int *y)
{
    int x;
   if(empty(pq))
    {
                 printf("underflow");
                 return(*y=0);
                 }
   x=pq->item[pq->rear];
   pq->rear=(pq->rear-1)%MAX;
   if(pq->rear==-1)
   {
                   pq->rear=MAX-1;
                   }
   return x;
}


void append_frnt(struct queue *pq, int x)
{
   int newf;
     newf=(pq->front-1)%MAX;
     if(newf==-1)
     {
                 newf=MAX-1;
                 }
     if(pq->rear==newf)
     {
                        printf("overflow");
                        getch();
                        exit(1);
                        }
    pq->item[pq->front]=x;
    pq->front=newf;
    return;
     }
     
   

void append_rear(struct queue *pq, int x)
{
     int newr;
     newr=(pq->rear+1)%MAX;
     if(pq->front==newr)
     {
                        printf("overflow");
                        getch();
                        exit(1);
                        }
     pq->rear=newr;
     pq->item[pq->rear]=x;
     return;
     }
     
  


