#include <stdio.h>
#include <math.h>
#include <cs50.h>

float promptUser(void);
void checkNegNumbers(int);
int calculateCoins(int);

int main(void) {
  promptUser();
}

float promptUser(void) {
  printf("How much change is owed? ");
  float changeAmount = GetFloat();

  // convert change to integer of # of cents
  int intAmount = round(changeAmount * 100);

  checkNegNumbers(intAmount);
  return 0;
}

void checkNegNumbers(num) {
  if(num < 0){
    printf("Please enter a positive number for your change. ");
    float changeAmount = GetFloat();

    // convert change to integer of # of cents
    int intAmount = round(changeAmount * 100);

    checkNegNumbers(intAmount);
  } else {
    calculateCoins(num);
  }
}

int calculateCoins(centsAmount) {

  // define coin set
  int quarter = 25;
  int dime = 10;
  int nickel = 5;
  int penny = 1;

  // calculate max num of each coin and remove from total amount
  int numQuarters = (centsAmount / quarter);
  centsAmount = centsAmount - (numQuarters * quarter);

  int numDimes = (centsAmount / dime);
  centsAmount = centsAmount - (numDimes * dime);

  int numNickels = (centsAmount / nickel);
  centsAmount = centsAmount - (numNickels * nickel);

  int numPennies = (centsAmount / penny);

  // add the number of coins for each coin together
  int total = numQuarters + numDimes + numNickels + numPennies;

  printf("You need %d coins. %d quarters, %d dimes, %d nickels, and %d pennies.\n", total, numQuarters, numDimes, numNickels, numPennies);

  return 0;
}
