#include <math.h>
#include <stdio.h>
#include <string.h>

int id(int x){
  return x;
}

int squared(int x){
  return x*x;
}

int factorial(int x){
  if ( x == 1){
    return 1;
  }
  return x * factorial (x-1);
}

int power(int x, int p){
  int value = 1;
  while (p!=0)
    {
      value*=x;
      --p;
    }
  return value;
}

int main(){
  int d = 0;
  printf("Hello all!\n");
  while(1){
      printf ("1 - play, 2 - exit, 3 - win\n");
      scanf("%d", &d);
      if (d == 1)
        {
          printf("enter a number\n");
          scanf("%d", &d);
          int result = factorial (d) - pow (d, 4);
          printf("your result is %d\n\n",  result);
        }
      else if (d == 3)
        {
          printf("now the game begins, enter your number!\n");
          scanf("%d", &d);
          int value = 498000;
          int a = -power (d, 4);
          int b = 56*power (d, 3);
          int c = 462*squared(d);
          int h = 752*id(d);
          int e = 500;
          d = (a+b+c+h)/4+e;
          if (d > value){
              printf ("You won!!\n\n");
              break;
          }
          printf("your result is %d\n\n",  d);
        }
      else{
          break;
        }
  }


}
