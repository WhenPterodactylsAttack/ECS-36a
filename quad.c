#include <stdio.h>
#include <math.h>

// calculates and prints the answers to the quadratic formula
void quadCalculation(double a, double b, double c) {
  double firstSolution;
  double secondSolution;
  double discriminant;

  discriminant = pow(b, 2) - (4 * a * c);
  firstSolution = (-1 * b + sqrt(discriminant)) / (2 * a);
  secondSolution = (-1 * b - sqrt(discriminant)) / (2 * a);

  if (discriminant > 1) {
    printf("There are 2 real solutions\n");
    printf("Solution 1: %.2lf\n", firstSolution);
    printf("Solution 2: %.2lf\n", secondSolution);
  } else if (discriminant == 0) {
    printf("There is one real solution: %.2lf\n", firstSolution);
  } else {
    printf("There are no real solutions");
  }
}

int main() {
  double a;
  double b;
  double c;

  // gathers user input
  printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
  printf("Please enter a: ");
  scanf("%lf" , &a);
  printf("Please enter b: ");
  scanf("%lf" , &b);
  printf("Please enter c: ");
  scanf("%lf" , &c);

  // calls external function
  quadCalculation(a, b, c);

  return 0;
}
