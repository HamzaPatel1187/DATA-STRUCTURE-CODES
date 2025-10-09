#include<stdio.h>
#include <stdlib.h>

struct Node {
 int data;
 struct Node *next;
};
// Stack operations
struct Node *top = NULL;
void push(int data){
struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
if(newNode==NULL){
printf("Overflow ");
return;
}
newNode->data=data;
newNode->next=top;
top=newNode;

printf("\n push successfully");

}
void pop(){
if(top==NULL){
printf("Underflow");
return ;
}
struct Node *temp=top;
top =top->next;
free(temp);
printf("\n pop successfully");
} 
void display(){
if(top==NULL){
printf("Underflow");
return ;
}
struct Node *temp=top;
while (temp!=NULL){
printf(" %d ",temp->data);
temp=temp->next;
} 
}

void main(){
int ch,data;
while (1){
printf("\n---- MENU -----");
printf("\n1. Push \n2. Pop\n3. Display");
printf("\nEnter choice eg.1,2,3");
scanf("%d",&ch);
switch(ch){
case 1:
printf("\nEnter element to pish");
scanf("%d",&data);
push(data);
break;
case 2:
pop();
break;
case 3:
display();
break;
default:
printf("\n you entered wrong choice , try again");
}

}


/* sample Testing Ignore this
push(30);
push(20);
push(10);
push(60);

pop();
pop();
display ();*/

}