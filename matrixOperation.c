#include<stdio.h>

void main() {
  int matrix1[3][3],matrix2[3][3],Add[3][3],sub[3][3],mul[3][3];
    printf("\n Enter elements of matrix 1 :");
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
      scanf("%d",& matrix1[i][j]);
    }
    }
    printf("\n Enter elements of matrix 2 :");
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
      scanf("%d",& matrix2[i][j]);
    }
    }
    /*
    printf("\nMatrix 1 :");
    printf("\n");
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
      printf("%d ", matrix1[i][j]);
    }
    printf("\n");
    }
    
    printf("\nMatrix 2 :");
    printf("\n");
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
      printf("%d ", matrix2[i][j]);
    }
    printf("\n");
    }
    */
    //addition 
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        Add[i][j]= matrix1[i][j]+matrix2[i][j];
    }
    }
    
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        sub[i][j]= matrix1[i][j]-matrix2[i][j];
    }
    }
    
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
      mul[i][j]=0;
      for(int k=0;k<3;k++){
        mul[i][j]+= matrix1[i][k]*matrix2[k][j];
        }
    }
    }
    printf("\Addition  :");
    printf("\n");
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
      printf("%d ", Add[i][j]);
    }
    printf("\n");
    }
    
    printf("\substarction  :");
    printf("\n");
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
      printf("%d ", sub[i][j]);
    }
    printf("\n");
    }
   printf("\n Multiplicatin  :");
    printf("\n");
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
      printf("%d ", mul[i][j]);
    }
    printf("\n");
    }
    

}