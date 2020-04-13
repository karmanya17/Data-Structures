#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void transverse();
int peek(void);
int p;
struct node
{
	int data;
	struct node *link;
};
struct node *top=NULL;
void main()
{
	int ch;
	while(1)
	{
	printf("stack operations using linked list :\n");
	printf("1.push \n");
	printf("2.pop \n");
	printf("3.transverse \n");
	printf("4.peek \n");
	printf("5.exit \n");
	printf("enter your choice");
	scanf("%d",&ch);
switch (ch)
		{
	case 1:push();
	break;
	case 2:pop();
	break;
	case 3:transverse();
	break;
	case 4:p=peek();
	printf("the value of read %d \n ",p);
	break;
	case 5:exit(1);
	default:printf("invalid choice");
		}
	}	
}
void push()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter the data");
	scanf("%d",&temp->data);
	temp->link=top;
	top=temp;
}
void pop()
{
	struct node* temp;
	if(top==NULL)
              {
		printf("no elements or nodes in the stack to delete \n");
              }
else
       {
	temp=top;
	printf("element %d",temp->data);
	top=top->link;
	temp->link=NULL;
	free(temp);
        }
}
void transverse()
{
	struct node* temp;
	if(top==NULL)
	{
		printf("stack is empty");
	}
else
{
	temp=top;
	while(temp!=NULL)
	{
	printf("%d \n",temp->data);
	temp=temp->link;
	}	
   }
}
int peek()
{
if(top==NULL)
{
printf("no nodes or elements to display");
}
else
{
p=top->data;
return(p);
}
}

