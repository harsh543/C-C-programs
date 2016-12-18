#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define upperStart 65
#define lowerStart 97

int checkConsoleArgs(int);
string getCipherChars(string, string);
char encryptChar(int, string, int);

int main (int argc, string argv[]) {
  // see if keyword was passed as argument during execute  
  int consoleArgs = checkConsoleArgs(argc);
  if(consoleArgs == 1){
    return 1;
  }

  string keyword = argv[1];

  printf("What would you like to encrypt?\n");
  string plaintext = GetString();

  // pass the plaintext and the keyword to encrypt  
  getCipherChars(plaintext, keyword);

  return 0;
}

int checkConsoleArgs (int consoleArgsCount) {
  // this program was executed juuuuust right!
  if(consoleArgsCount == 2) {
    return 0;

  // this program was executed with too few console arguments.
  } else if(consoleArgsCount < 2) {
    printf("This program requires a keyword as a console argument. Please try again.\n");
    return 1;

  // this program was executed with too many console arguments.
  } else {
    printf("Please enter only one keyword for the encryption.\n");
    return 1;
  }
}

string getCipherChars(string plaintext, string keyword){
  int plaintextLen = strlen(plaintext);

  int newChar;
  int j = 0;
  for(int i = 0; i < plaintextLen; i++) {
    newChar = plaintext[i];

    // encrypt chars if it's alphabetical
    if(isalpha(newChar)) {
      encryptChar(newChar, keyword, j);

      // increment j (for keyword index) only when it's alpha.
      j++;

    // print other chars as is.
    } else {
      printf("%c", newChar);
    } 
  }

  printf("\n");
  return 0;
}

char encryptChar(int newChar, string keyword, int j) {

  int indexStart;

  // if uppercase char, set the index to start at uppercase ASCII start
  if(isupper(newChar)) {
    indexStart = upperStart;

  // if lowercase char, set the index to start at lowercase ASCII start
  } else {
    indexStart = lowerStart;
  }

  char encryptedChar;
  int keywordLen = strlen(keyword);

  // get alpha index of keyword letter, modulus it's length - the ASCII start
  int cipherNum = keyword[j % keywordLen] - lowerStart;

  // find alpha index of keyword char
  cipherNum = (((newChar - indexStart) + cipherNum) % 26);

  // convert back to ASCII index of cipher
  encryptedChar = indexStart + cipherNum;

  printf("%c", encryptedChar);

  return 0;
}
