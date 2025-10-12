/* Implement stack using array.
Theory:
A stack is a linear data structure that follows the LIFO (Last In First Out) principle.
This means the element inserted last will be the first one to be removed.
In C, a stack can be implemented using:
Arrays
Structures
or Linked Lists
In this program, we use an array and a structure to represent the stack.
The structure contains:
An integer array data[MAX] to store elements.
An integer variable top that keeps track of the index of the topmost element.
Stack is widely used in recursion, expression evaluation, function calling, and memory management.
*/
#include<stdio.h>
#include<unistd.h>
#define MAX 5		// defining the size of array or size of stack
struct stack		// structure for stack
{
int data[MAX];
int top;
};

// function to initialize the stack
void initialize(struct stack *s)	// accepting address of stack
{
s->top=-1;		// setting the value of top to -1
}

// function to check whether the stack is empty
int isEmpty(struct stack *s)
{
if(s->top==-1)			// efficient code is return s->top==-1?1:0;
	return 1;
else
	return 0;
}

// function to check whether the stack is full
int isFull(struct stack *s)
{ //here I am using Ternary operator 
 return s->top==MAX-1?1:0;
	
}

// function to push given data in given stack
int push(struct stack *s,int d)		// accepting stack address and data
{
if(isFull(s))
	return 0;		// this indicates stack is full & so push cannot be done
else
{
s->top++;					// increase top
s->data[s->top]=d;			// store data at new top
return 1;					// indicate successful push
}
}

// function to pop from given stack
void pop(struct stack *s)
{
if(isEmpty(s))	// call isEmpty to check whether given stack is empty
printf("\n\tStack Underflows->");
else
{
printf("\nPopped element is : %d",s->data[s->top]);	// display popped element
s->top--;			// decrease top
}
}

// function to peek from given stack
void peek(struct stack *s)
{
if(s->top==-1)
printf("\n\tStack Underflows->");
else
{
printf("\nTop element is : %d",s->data[s->top]);	// show top element
}
}

// function to display the given stack
void display(struct stack *s)
{
int i;
if(isEmpty(s))
printf("\n\tStack is Empty->");
else
{
printf("\nStack Contents ->->\n");
// display more information about stack
for(i=s->top;i>=0;i--)
{
printf("%d\n",s->data[i]);
}
}
}

// the main function
int main()
{
int ch,d;
struct stack s,s1[10];	// stack variables
//s.top=-1;
initialize(&s);
while(1)			// indefinite loop to show options
{
printf("\n\t\t\tMENU\n1. Push.\n2. Pop.\n3. Peek.");
printf("\n4. Display.\n5. Exit.");
printf("\n\tEnter your choice :: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\nEnter Data to be Pushed : ");
scanf("%d",&d);
if(push(&s,d))				// <--- completed if statement
printf("\nPushed successfully");
else
printf("\nCannot Push..");
break;
case 2:
pop(&s);					// call the required function
break;
case 3:
peek(&s);					// call the required function and do needful
break;
case 4:
display(&s);				// call the required function and do needful
break;
case 5:
exit(0);
default:
printf("\n\tPlease enter correct choice->->->->");
}
}
}


/*
Conclusion:
From this program, we learned how to:
Implement a stack using arrays and structures in C.
Perform basic stack operations such as Push, Pop, Peek, and Display.
Handle overflow and underflow conditions safely.
Understand the working principle of LIFO (Last In First Out) order.
This experiment helps in understanding how stacks manage data dynamically and how they are used in various applications 
like function call stacks, expression parsing, undo operations, and memory allocation.
*/