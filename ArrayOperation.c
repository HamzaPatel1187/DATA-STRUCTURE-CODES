#include<stdio.h>
int main()
{
    int n,add,del,ser;
    printf("Hello !");
    printf("\nEnter No. of elements in array : ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter elements : ");
    for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    }
    
    
    
    printf("\nYour Array :");
    for(int i=0;i<n;i++){
    printf(" [%d] ",arr[i]);
    }
    printf("Enter element to delete in array : ");
    scanf("%d",&del);
    for(int i=0;i<n;i++){
    if(arr[i]==del){
       for(int j=i;j<n-1;j++){
       arr[j]=arr[j+1];   
    }
    }
    }
    n-=1;
    
   printf("\nYour Array :");
    for(int i=0;i<n;i++){
    printf(" [%d] ",arr[i]);
    }
    
    printf("Enter element to search in array : ");
    scanf("%d",&ser);
    for(int i=0;i<n;i++){
    if(arr[i]==ser){
       printf("\n Element found at %d position .",arr[i]);   
    
    }
    }
    
    return 0;
}