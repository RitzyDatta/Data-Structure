#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
struct stack
{
       int top;
       char item[MAX];
       };

void push (struct stack *, int);
int pop(struct stack *);
char postfix[100];
char postfix1[100];
int evolution(struct stack *);

main()
{
      
      struct stack s;
      s.top=-1;
      int choice, x, result;
      printf("\nenter an postfix expression:\n");
      gets(postfix);
      result=evolution(&s);
      printf("\n the result of evolution: %d", result); 
      getch();
      }
      
int evolution(struct stack *ps)
{
    int a,b,temp, result, len, i;
    char g='0';
    
    for(i=0; postfix[i]!='\0';i++)
    {
             if(postfix[i]<='9' && postfix[i]>='0')
                                 push(ps,postfix[i]-g);
             
             else
             {
             a=pop(ps);
             b=pop(ps);
             
             
             switch(postfix[i])
             {
                               case '+':
                                    temp=b+a;
                                    break;
                               
                               case '-':
                                    temp=b-a;
                                    break;
                               case '*':
                                    temp=b*a;
                                    break;
                               case '/':
                                    temp=b/a;
                                    break;
                               case '^':
                                    temp=pow(b,a);
                                    break;
                                    }
                                    
                                    
                               push(ps,temp);
                               }
                               }
             result=pop(ps);
             return result;
             }
             
             
int empty(struct stack *ps)
{
    if(ps->top==-1)
        return 1;
    else
        return 0;
}

int pop(struct stack *ps)
{
    int element;
    if(empty(ps))
    {
                 printf("stack underflow");
                 getch();
                 exit(1);
                 }
    element=ps->item[ps->top];
    ps->top--;
    return element;
}

void push(struct stack *ps, int x)
{
     if(ps->top==(MAX-1))
     {
                         printf("stack overflow");
                         getch();
                         exit(1);
                         }
      else
          ps->item[++(ps->top)]=x;
          }
