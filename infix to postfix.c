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

void push (struct stack *, char);
char pop(struct stack *);
int prec(char);
char infix[100];
char postfix[100];
void in_to_po(struct stack *);

main()
{
      struct stack s;
      s.top=-1;
      int choice, x;
      printf("\nenter an infix expression:\n");
      gets(infix);
      in_to_po(&s);
      printf("\nthe postfix expression is: \n");
      puts(postfix);
      getch();
      }
      
int empty(struct stack *ps)
{
    if(ps->top==-1)
        return 1;
    else
        return 0;
}

char pop(struct stack *ps)
{
    char element;
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

void push(struct stack *ps, char x)
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
          
void in_to_po(struct stack *ps)
{
     int i, prcdnc, len, p=0,k;
     char next;
     
     for(i=0; infix[i]!='\0';i++)
     {
              switch(infix[i])
              {
                              case '(':
                                   {
                                   push(ps, infix[i]);
                                   break;
                                   }
                              case ')':
                                   {
                                   while((next=pop(ps)) != '(')
                                      postfix[p++]= next;
                                   break;
                                   }
                              case '+':
                              case '-':
                              case '*':
                              case '/':
                              case '^':
                                   {
                                   prcdnc=prec(infix[i]);
                                   k=prec(ps->item[ps->top]);
                                   
                                   while(prcdnc<k)
                                   {
                                                  k=prec(ps->item[ps->top]);
                                                  if(prcdnc<k)
                                                    postfix[p++]=pop(ps);
                                                    }
                                   while(prcdnc==k && k<3)
                                   {
                                                   k=prec(ps->item[ps->top]);
                                                   if(prcdnc==k && k<3)
                                                     postfix[p++]=pop(ps);
                                                    }
                                    push(ps, infix[i]);
                                     
                                   break;
                                   }
                              default:
                                      {
                                      postfix[p++]=infix[i];
                                      break;
                                      }
                                      }
                                      }
     while(ps->top!=-1)
                       postfix[p++]=pop(ps);
     postfix[p]='\0';
     puts(postfix);
     }
     
int prec(char symbol)
{
    switch(symbol)
    {
                  case'(':
                          return 0;
                          break;
                  case '+':
                  case '-':
                       return 1;
                       break;
                  case '*':
                  case '/':
                       return 2;
                       break;
                  case '^':
                       return 3;
                       break;
                  default:
                          return -999;
                          break;
                          }
                  
                          }
                          
      
      
