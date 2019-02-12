#include <stdio.h>

int max(int num1,int num2){
  if(num1>=num2){
    return num1;
  }else{
    return num2;
  }
}

int main(void){
  int num1,num2;
  scanf("%d %d", &num1,&num2);
  int maximo= max(num1,num2);
  printf("%d\n", maximo);
}
