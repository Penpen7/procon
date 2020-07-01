#include <stdio.h>
int hoge(int i){
  return i;
}
int main(){
  switch(hoge(0)){
    case 1:
      printf("1");
      break;
    case 2:
      printf("2");
      break;
    default:
      printf("other");
      break;
  }
}
