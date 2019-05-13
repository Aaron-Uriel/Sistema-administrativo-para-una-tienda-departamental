#include <stdio.h>

void gotoxy(int x,int y)
 {
 printf("%c[%d;%df",0x1B,y,x);
 }

void cover(){
  system("color 07");
  printf("Office Depot\n\nCARGANDO ");
  for (int x = 1 ; x <= 100 ; x++){
      printf("*");
      sleep (400);
  }
}

int main(){
  cover();
}