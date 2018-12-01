#include<stdio.h> /* printf, fgets */

void mario();

int main(void){
  mario();

  return 0;
}

void mario(){
  int h;
  printf("Height: ");
  scanf("%d",&h);
  for(int place=1;place<h+1;place++){
    for(int space=0;space<h-place;space++){
      printf(" ");
    }
    for(int space=0;space<place;space++){
      printf("#");
    }
    printf("  ");
    for(int space=0;space<place;space++){
      printf("#");
    }
    for(int space=0;space<h-place;space++){
      printf(" ");
    }
    printf("\n");
  }
}
