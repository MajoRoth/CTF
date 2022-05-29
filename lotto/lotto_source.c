#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>

unsigned char submit[6];

void play(){

  int i;
  printf("Submit your 6 lotto bytes : ");
  fflush(stdout);

  int r;
  r = read(0, submit, 6);


  printf("Lotto Start!\n");
  //sleep(1);

  // generate lotto numbers
  unsigned char lotto[6];
  srand(time(NULL));   // Initialization, should only be called once.

  for(i=0; i<6; i++){
      lotto[i] = rand();
      lotto[i] = (lotto[i] % 45) + 1;
    }
  // calculate lotto score
  int match = 0, j = 0;
  for(i=0; i<6; i++){
      for(j=0; j<6; j++){
          if(lotto[i] == submit[j]){
              match++;
            }
        }
    }

  // win!
  if(match == 6){
      printf ("-------------\nCongrats! you won the lotto!\n-------------\n");
    }
  else{
      printf("bad luck...\n");
    }

}

void help(){
  printf("- nLotto Rule -\n");
  printf("lotto is consisted with 6 random natural numbers less than 46\n");
  printf("your goal is to match lotto numbers as many as you can\n");
  printf("if you win lottery for *1st place*, you will get a reward\n");
  printf("mathematical chance to win this game is known to be 1/8145060.\n");
}

int main(int argc, char* argv[]){

  // menu
  unsigned int menu;

  while(1){

      printf("- Select Menu -\n");
      printf("1. Play Lotto\n");
      printf("2. Help\n");
      printf("3. Exit\n");

      scanf("%d", &menu);

      switch(menu){
          case 1:
            play();
          break;
          case 2:
            help();
          break;
          case 3:
            printf("bye\n");
          return 0;
          default:
            printf("invalid menu\n");
          break;
        }
    }
  return 0;
}