#include <stdio.h>
#include <cs50.h>

void buildPyramid(blocks) {
  // build pyramid
  for(int j = 0; j < blocks; j++) {

    // type spaces on every row
    int space = blocks - (j + 1);
    for(int i = 0; i < space; i++) {
      printf(" ");
    }

    // type 2 hashes on every row
    printf("##");

    // type extra hashes on every row
    int hash = blocks - (blocks - j);
    for(int k = 1; k <= hash; k++){
      printf("#");
    }

    // return for new row
    printf("\n");
  }
}

void checkNumber(num) {
  if(num <= 0) {
    // warn them if a negative num
    printf("Please enter a positive number. ");
    int numBlocks = GetInt();
    checkNumber(numBlocks);
  }
  else {
    buildPyramid(num);
  }
}

int main(void) {
  // get number of blocks to build
  printf("How many blocks high do you want the pyramid? ");
  int numBlocks = GetInt();
  checkNumber(numBlocks); 
}
