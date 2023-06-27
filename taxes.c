#include <stdio.h>

// calculates flat tax rate (the total tax percent of this year's income)
double flatTaxRate(double totalTaxes, double yearIncome) {
  double flatRate = 100 * (totalTaxes / yearIncome);
  return flatRate;
}

// applies the tax rate to values
double applyBracketTaxRate(double taxPercent, double currentAmount) {
  return currentAmount * (taxPercent/100);
}

// Eliminates the need for multiple printf statements
void printAmountTaxed(double percentTaxed, double currentBeingTaxed) {
  printf("You were taxed %.2lf%% on the next $%.2lf you made which is $%.2lf.\n",
    percentTaxed, currentBeingTaxed, applyBracketTaxRate(percentTaxed, currentBeingTaxed));
}

void taxCalculation(double yearIncome) {
    double totalTaxes;
    double currentRemainingTotal;
    double currentBeingTaxed;

    currentRemainingTotal = yearIncome;
    totalTaxes = 0;

    if(currentRemainingTotal > 9875) {
      currentBeingTaxed = 9875;
      currentRemainingTotal -= 9875;
      totalTaxes += applyBracketTaxRate(10, currentBeingTaxed);
      printf("You were taxed 10.00%% on the first $%.2lf you made which is $%.2lf.\n",
        currentBeingTaxed, applyBracketTaxRate(10, currentBeingTaxed));

        if (currentRemainingTotal > 30250) {
          currentBeingTaxed = 30250;
          currentRemainingTotal -= 30250;
          totalTaxes += applyBracketTaxRate(12, currentBeingTaxed);
          printAmountTaxed(12, currentBeingTaxed);
              if (currentRemainingTotal > 45400) {
                currentBeingTaxed = 45400;
                currentRemainingTotal -= 45400;
                totalTaxes += applyBracketTaxRate(22, currentBeingTaxed);
                printAmountTaxed(22, currentBeingTaxed);
                if (currentRemainingTotal > 77775) {
                  currentBeingTaxed = 77775;
                  currentRemainingTotal -= 77775;
                  totalTaxes += applyBracketTaxRate(24, currentBeingTaxed);
                  printAmountTaxed(24, currentBeingTaxed);
                  if (currentRemainingTotal > 44050) {
                    currentBeingTaxed = 44050;
                    currentRemainingTotal -= 44050;
                    totalTaxes += applyBracketTaxRate(32, currentBeingTaxed);
                    printAmountTaxed(32, currentBeingTaxed);
                    if (currentRemainingTotal > 311050) {
                      currentBeingTaxed = 311050;
                      currentRemainingTotal -= 311050;
                      totalTaxes += applyBracketTaxRate(35, currentBeingTaxed);
                      printAmountTaxed(35, currentBeingTaxed);
                          if (currentRemainingTotal > 0) {
                            totalTaxes += applyBracketTaxRate(37, currentRemainingTotal);
                            printAmountTaxed(37, currentRemainingTotal);
                          }
                    } else {
                      currentBeingTaxed = currentRemainingTotal;
                      totalTaxes += applyBracketTaxRate(35, currentBeingTaxed);
                      printAmountTaxed(35, currentBeingTaxed);
                    }
                  } else {
                    currentBeingTaxed = currentRemainingTotal;
                    totalTaxes += applyBracketTaxRate(32, currentBeingTaxed);
                    printAmountTaxed(32, currentBeingTaxed);
                  }
                } else {
                  currentBeingTaxed = currentRemainingTotal;
                  totalTaxes += applyBracketTaxRate(24, currentBeingTaxed);
                  printAmountTaxed(24, currentBeingTaxed);
                }
              } else {
                currentBeingTaxed = currentRemainingTotal;
                totalTaxes += applyBracketTaxRate(22, currentBeingTaxed);
                printAmountTaxed(22, currentBeingTaxed);
              }
        } else {
          currentBeingTaxed = currentRemainingTotal;
          totalTaxes += applyBracketTaxRate(12, currentBeingTaxed);
          printAmountTaxed(12, currentBeingTaxed);
        }

    } else {
      currentBeingTaxed = currentRemainingTotal;
      totalTaxes += applyBracketTaxRate(10, currentBeingTaxed);
      currentRemainingTotal -= currentBeingTaxed;
      printf("You were taxed 10.00%% on the first $%.2lf you made which is $%.2lf.\n",
        currentBeingTaxed, applyBracketTaxRate(10, currentBeingTaxed));
    }

    // prints final totals
    printf("In total you will pay $%.2lf in taxes on the $%.2lf you made this year.\n", totalTaxes, yearIncome);
    printf("This would amount to a FLAT tax of %.2lf%% on all of your income.\n", flatTaxRate(totalTaxes, yearIncome));
}

int main() {
  double yearsIncome;

  printf("Enter your income for the year: ");
  scanf("%lf", &yearsIncome);

  // calls for calculation of taxes as well as prints all necassary values
  taxCalculation(yearsIncome);

  return 0;
}
