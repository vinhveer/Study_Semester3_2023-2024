#include <stdio.h>
void sum(int &x,int &y){
   x = 5;
   y = x +7;   
}
int main(){
   int a = 1, b = 2;   
   sum(a, b);
   printf("sau khi goi sum: %d", a);
   return 0;
}