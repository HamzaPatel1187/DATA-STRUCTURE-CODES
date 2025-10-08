#include<stdio.h>
#define MAX 10
int stack[MAX];
int top=-1;

void push(int data){
   if(top==MAX -1){
    printf("!! stack overflow ");
    return ;
   }
   top+=1;
   stack[top]=data;
   printf("\n %d push in stack ",stack[top]);
}
int pop(){
if(top==-1){
  printf("!! Underflow Empty ");
  return NULL ;
}
return stack[top--];
}
void display(){
if(top==-1){
  printf("!! Underflow Empty ");
  return ;
}
for(int i=0;i<=top;i++){
    printf("\n | %d |",stack[i]);
}
}
 void main(){
   push(10);
   push(20);
   push(30);
  push(40);
 push(50);
push(60);
printf("\n%d pop ",pop());
printf("\n%d pop ",pop());
display();
 
 }