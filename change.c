#include<stdio.h>

int main() {
  double userInput;
  double currentValue;

  // prompts user to enter number
  printf("Please enter the amount of money you wish to withdraw: ");
  scanf("%lf", &userInput);

  // splits and prints user's
  currentValue = (int)userInput / 100;
  printf("You received %d hundred(s)\n", currentValue);
  userInput -= (currentValue * 100);

  currentValue = (int)userInput / 50;
  printf("You received %d fifty(s)\n", currentValue);
  userInput -= (currentValue * 50);

  currentValue = (int)userInput / 20;
  printf("You received %d twenty(s)\n", currentValue);
  userInput -= (currentValue * 20);

  currentValue = (int)userInput / 10;
  printf("You received %d ten(s)\n", currentValue);
  userInput -= (currentValue * 10);

  currentValue = (int)userInput / 5;
  printf("You received %d five(s)\n", currentValue);
  userInput -= (currentValue * 5);

  currentValue = (int)userInput / 1;
  printf("You received %d one(s)\n", currentValue);
  userInput -= (currentValue * 1);

  return 0;
}
