#include<stdio.h>
#include<conio.h>
#define MAX 100
       

struct tree_node
{
       int data;
       struct tree_node *left;
       struct tree_node *right;
       };
typedef struct tree_node *NODEPTR;

struct queue
{
       int front;
       int rear;
       NODEPTR item[MAX];
       };

int insert_bst(NODEPTR*, int);
NODEPTR maketree(int);
void display1(NODEPTR, int);
int count_node(NODEPTR);
int count_leaf(NODEPTR);
int tree_height(NODEPTR);
void inorder(NODEPTR);
void preorder(NODEPTR);
void postorder(NODEPTR);
int remove_root(NODEPTR *);
NODEPTR search(NODEPTR, int);
void append(struct queue *, NODEPTR);
void display(struct queue *);
NODEPTR serve(struct queue *);
void level_order(NODEPTR);

main()
{
      NODEPTR root, q;
      root=NULL;
      int choice, num, x,y;
      while(1)
      {
              printf("\n1.insert\n2.display the tree\n3.inorder\n4.preorder");
              printf("\n5.postorder\n6.remove root\n7.count node");
              printf("\n8.count_leaf\n9.tree height\n10.search a node");
              printf("\n11.delete a node\n12.level order\n13.exit\n\n");
              printf("\nenter your choice: ");
              scanf("%d", &choice);
              
              switch(choice)
              {
                            case 1:
                                 printf("enter the number to be inserted: ");
                                 scanf("%d", &num);
                                 x=insert_bst(&root, num);
                                 if(x==1)
                                 {
                                         printf("\nnode is already in the tree, no need to insert\n");
                                         }
                                 else
                                    printf("\nnode successfuly inserted\n");
                                 break;
                            case 2:
                                 display1(root,1);
                                 break;
                            case 3:
                                 inorder(root);
                                 break;
                            case 4:
                                 preorder(root);
                                 break;
                            case 5:
                                 postorder(root);
                                 break;
                            case 6:
                                 x=remove_root(&root);
                                 if(x==1)
                                    printf("\ntree is empty");
                                 else
                                    printf("\nremove successfully");
                                 break;
                            case 7:
                                 x=count_node(root);
                                 printf("\ntotal nodes are= %d", x);
                                 break;
                            case 8:
                                 x=count_leaf(root);
                                 printf("\ntotal leaf nodes are %d", x);
                                 break;
                            case 9:
                                 x=tree_height(root);
                                 printf("\the height of the tree is=%d", x);
                                 break;
                                 
                            case 10:
                                 printf("\nenter a number to search: ");
                                 scanf("%d", &x);
                                 q=search(root, x);
                                 if(q==NULL)
                                    printf("\nentered item is not found" );
                                 else
                                     printf("\n%d is in the tree", q->data);
                                 break;
                            case 11:
                                 printf("\nenter the data to delete");
                                 scanf("%d", &y);
                                 x=del_node(&root, y);
                                 if(x==1)
                                    printf("\nnot found");
                                 else
                                    printf("\nremove successfully");
                                 break;
                            case 12:
                                 level_order(root);
                                 break;
                                            
                            case 13:
                                 exit(1);
                            default:
                                    printf("\nwrong choice");
                                    break;
                                    }
                                    }
      getch();
      }
      
NODEPTR maketree(int new_data)
{
        NODEPTR temp;
        temp=malloc(sizeof(struct tree_node));
        temp->data=new_data;
        temp->left=temp->right=NULL;
        return temp;
        }
        
int insert_bst(NODEPTR *proot, int new_data)
{
    NODEPTR new_node, pos;
    int finished;
    new_node=maketree(new_data);
    if(*proot==NULL)
    {
                    *proot=new_node;
                    return 0;
                    }
    else
    {
        finished=0;
        pos=*proot;
        do
        {
                   if(new_node->data<pos->data)
                       if(pos->left!=NULL)
                           pos=pos->left;
                       else
                       {
                           pos->left=new_node;
                           finished=1;
                           }
                   else
                       if(new_node->data>pos->data)
                          if(pos->right!=NULL)
                              pos=pos->right;
                          else
                          {
                              pos->right=new_node;
                              finished=1;
                              }
                       else
                           return 1;
                      }while(!finished);
                      }
        return 0;
        }

void display1(NODEPTR ptr, int level)
{
     int i;
     if(ptr!=NULL)
     {
                  display1(ptr->right,level+1);
                  printf("\n");
                  for(i=0;i<level; i++)
                                   printf("    ");
                  printf("%d", ptr->data);
                  display1(ptr->left, level+1);
                  }
                  }
                  
void inorder(NODEPTR root)
{
     if(root)
     {
             inorder(root->left);
             printf("%d ",root->data);
             inorder(root->right);
             }
             }

void preorder(NODEPTR root)
{
     if(root)
     {
             printf("%d ",root->data);
             preorder(root->left);
             preorder(root->right);
             }
             }
             
void postorder(NODEPTR root)
{
     if(root)
     {
             
             postorder(root->left);
             postorder(root->right);
             printf("%d ",root->data);
             }
             }

int remove_root(NODEPTR *proot)
{
    NODEPTR to_delete, parent;
    if(*proot==NULL)
       return 1;
    to_delete=*proot;
    
    if((*proot)->right==NULL)
       *proot=(*proot)->left;
    else
       if((*proot)->left==NULL)
          *proot=(*proot)->right;
       else
       {
           to_delete=(*proot)->left;
           parent=*proot;
           
           while(to_delete->right !=NULL)
           {
                                  parent=to_delete;
                                  to_delete=to_delete->right;
                                  }
           (*proot)->data=to_delete->data;
           if(parent==*proot)
               parent->left=to_delete->left;
           else
               parent->right=to_delete->left;
               }
           free(to_delete);
           return 0;
           }


int count_node(NODEPTR root)
{
    if(!root)
      return 0;
    else
      return 1+count_node(root->left)+count_node(root->right);
      }
      
    
int count_leaf(NODEPTR root)
{
    if(!root)
      return 0;
    else
      if((!root->left) && (!root->right))
          return 1;
      else
         return count_leaf(root->left) + count_leaf(root->right);
         }
         
int tree_height(NODEPTR root)
{
    if(!root)
       return 0;
    else
       return max(tree_height(root->left), tree_height(root->right))+1;
       }
       
int max(int a, int b)
{
    if(a>b)
      return a;
    else
        return b;
        }

NODEPTR search(NODEPTR root, int target)
{
        while(root!=NULL && root->data!=target)
            if(target < root->data)
                root=root->left;
            else
                root=root->right;
         
        return root;
        }
               
int del_node(NODEPTR *proot, int target)
{
    if(*proot == NULL || (*proot)->data==target)
              return remove_root(proot);
    else
        if(target< (*proot)->data)
                   return del_node(&((*proot)->left), target);
        else
            if(target> (*proot)->data)
                   return del_node(&((*proot)->right), target);
                   
                   }
                   
void level_order(NODEPTR root)
{
     if(root==NULL)
     {
                   printf("\ntree is empty");
                   return;
                   }
     NODEPTR nd;
     struct queue q;
     q.front=q.rear=1;
     append(&q,root);
     
     
     while(!empty(&q))
     {
     
                     nd=serve(&q);
                     printf("%d ", nd->data);
                     if(nd->left!=NULL)
                        append(&q, nd->left);
                     if(nd->right!=NULL)
                         append(&q, nd->right);
                         }
     }
    
int empty(struct queue *pq)
{
    if(pq->front==pq->rear)
    return 1;
    else
    return 0;
}

NODEPTR serve(struct queue *pq)
{
    NODEPTR element;
    
    pq->front=pq->front+1;
    element=pq->item[pq->front];
    return element;
}

void append(struct queue *pq, NODEPTR x)
{
    
     pq->rear=pq->rear+1;
     pq->item[pq->rear]=x;
     }
     
