#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100
struct stack
{
       int top;
       int item[MAX];
       };

void push(struct stack *, int);
void display(struct stack *);
int pop(struct stack *, int *);

main()
{
      int flag;
      struct stack s;
      s.top=-1;
      int choice,x;
      while(1)
      {
              printf("\n1:push\n2:pop\n3:display\n4:quit");
              printf("\nenter your choice:\n");
              scanf("%d", &choice);
              switch(choice)
              {
                            case 1:
                                 {
                                               printf("\nenter the element to be inserted: ");
                                               scanf("%d", &x);
                                               push(&s, x);
                                               break;
                                               }
                            case 2:
                                 {
                                               flag=1;
                                               x=pop(&s, &flag);
                                               if(flag)
                                               {
                                               printf("\nthe poped item: %d", x);
                                               }
                                               break;
                                               }
                            
                            case 3
                                 exit(1);
                            default:
                                    printf("wrong choice:\n");
                                    }
                                    }
              getch();
              }
              
int empty(struct stack *ps)
{
    if(ps->top==-1)
        return 1;
    else
        return 0;
}

int pop(struct stack *ps, int *y)
{
    int element;
    if(empty(ps))
    {
                 printf("stack underflow");
                 return(*y=0);
                 }
    element=ps->item[ps->top];
    ps->top--;
    return element;
}

void push(struct stack *ps, int x)
{
     if(ps->top==(MAX-1))
     {
                         printf("s5tack overflow");
                         getch();
                         exit(1);
                         }
      else
          ps->item[++(ps->top)]=x;
          }
          
/*id display(struct stack *ps)
{
     int i;
     if(ps->top==-1)
                    printf("\nstack is empty\n");
     else
     {
         printf("\nstack elements :\n");
         for(i=ps->top; i>=0;i--)
                        printf("%d\n", ps->item[i]);
                        }
                        } */       
