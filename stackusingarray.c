// stack implementations using array
#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5 //PRE PROCESSOR MACRO
void push(int);
int pop(void);
int isfull(void);
int isempty(void);
void traverse(void);
void peek(void);
int stack[CAPACITY],top=-1;
void main()
{
int ch,item;
while(1)
{
printf("stack operations using array \n \n");
printf("1. push \n");
printf("2. pop \n");
printf("3.peek \n");
printf("4.traverse \n");
printf("5.exit \n");
printf("enter your choice \t");
scanf("%d",&ch);
switch (ch)
{
case 1:printf("enter the element :");
scanf("%d",&item);
push(item);
break;
case 2:item=pop();
if(item==0)
{
printf("stack is underflow \n");
}
else
{
printf("popped item : %d\n",item);
}
break;
case 3:peek();
break;
case 4:traverse();
break;
case 5:exit(1);
default:printf("inalid choice \n");
}
}
}

int isempty()
{
if(top==-1)
{
return 1;
}
else
{
return 0;
}
}

int isfull()
{
if(top==CAPACITY-1)
{
return 1;
}
else
{
return 0;
}
}

void push(int ele)
{
if(isfull())
{
printf("stack is overflow \n ");
}
else
{
top++;
stack[top]=ele;
printf("%d pushed \n ",ele);
}
}
 

int pop()
{
if(isempty())
{
return 0;
}
else
{
return stack[top--];
}
}

void peek()
{
if(isempty())
{
printf("stack is empty \n ");
}
else
{
printf("peek element : %d \n ",stack[top]);
}
}


void traverse()
{
if(isempty())
{
printf("stack is empty \n");
}
else
{
int i;
printf("stack elements : \n");
for(i=0;i<=top;i++)
{
printf("%d \n ",stack[i]);
}
}
}

