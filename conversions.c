#include <stdio.h>
#include <ctype.h>

// checks for initial invalid input
void invalidInput(char userInput) {
  if (isalpha(userInput) == 0) {
    printf("Invalid formatting. Ending program.\n");
  } else {
    printf("Unknown conversion type %c chosen. Ending program.\n ", userInput);
  }
}

// uses inch as standard unit for conversions
double inchToUnit(double distance, char newUnit) {
  double conversion;
  switch (newUnit) {
    case 'I':
      conversion = distance;
      break;
    case 'F':
      conversion = distance / 12;
      break;
    case 'Y':
      conversion = distance / 36;
      break;
    case 'M':
      conversion = distance / 63360;
      break;
    default:
      conversion = distance;
      break;
  }
  return conversion;
}

// converts distances to inches and calls inchToUnit() for final conversion
double distUnitConvert(char initialUnit, char newUnit, double distance) {
  double newDistance;
  switch (initialUnit) {
    case 'I':
      newDistance = inchToUnit(distance, newUnit);
      return newDistance;
      break;
    case 'F':
      newDistance = inchToUnit(distance * 12, newUnit);
      return newDistance;
      break;
    case 'Y':
      newDistance = inchToUnit(distance * 36, newUnit);
      return newDistance;
      break;
    case 'M':
      newDistance = inchToUnit(distance * 63360, newUnit);
      break;
    default:
      newDistance = distance;
      break;
    }
    return newDistance;
}

// checks for errors and prints results
void distanceConversion() {
  char initialUnit;
  char newUnit;
  double distance;

  printf("Enter the distance followed by its suffix (I,F,Y,M): ");
  scanf(" %lf %c", &distance, &initialUnit);
  initialUnit = toupper(initialUnit);

  if ((initialUnit == 'I' || initialUnit == 'F' || initialUnit == 'Y' || initialUnit == 'M') && distance != 0) {
    printf("Enter the new unit type (I,F,Y,M): ");
    scanf(" %c", &newUnit);
    newUnit = toupper(newUnit);
    if ((newUnit == 'I' || newUnit == 'F' || newUnit == 'Y' || newUnit == 'M')) {
      printf("%.2lf%c is %.2lf%c\n", distance, initialUnit, distUnitConvert(initialUnit, newUnit, distance), newUnit);
    } else {
      printf("%c is not a valid distance type. Ending program.\n", newUnit);
    }
  } else if (initialUnit == '\0') {
    printf("Invalid formatting. Ending program.\n");
  } else {
    printf("%c is not a valid distance type. Ending program.\n", initialUnit);
  }
}

// uses fahrenheit as standard unit
double fahrenheitToUnit(double temperature, char newUnit) {
  double conversion;
  switch (newUnit) {
    case 'F':
      conversion = temperature;
      break;
    case 'C':
      conversion = (temperature - 32) * 5 / 9;
      break;
    case 'K':
      conversion = (temperature - 32) * 5 / 9 + 273.15;
      break;
    default:
      conversion = temperature;
      break;
  }
  return conversion;
}

// converts units to fahrenheit and uses fahrenheitToUnit() for final conversion
double tempUnitConvert(char initialUnit, char newUnit, double temperature) {
  double newTemperature;
  switch (initialUnit) {
    case 'F':
      newTemperature = fahrenheitToUnit(temperature, newUnit);
      break;
    case 'C':
      newTemperature = fahrenheitToUnit(temperature * 9 / 5 + 32, newUnit);
      break;
    case 'K':
      newTemperature = fahrenheitToUnit((temperature - 273.15) * 9 / 5 + 32, newUnit);
      break;
    default:
      newTemperature = temperature;
      break;
  }
  return newTemperature;
}

// checks for errors and prints results
void temperatureConversion() {
  char initialUnit;
  char newUnit;
  double temperature;

  printf("Enter the temperature followed by its suffix (F, C, or K): ");
  scanf(" %lf %c", &temperature, &initialUnit);
  initialUnit = toupper(initialUnit);

  if (initialUnit == 'F' || initialUnit == 'C' || initialUnit == 'K') {
    printf("Enter the new unit type (F, C, or K): ");
    scanf(" %c", &newUnit);
    newUnit = toupper(newUnit);
    if (newUnit == 'F' || newUnit == 'C' || newUnit == 'K') {
      printf("%.2lf%c is %.2lf%c\n", temperature, initialUnit,
        tempUnitConvert(initialUnit, newUnit, temperature), newUnit);
    } else {
      printf("%c is not a valid temperature type. Ending program.\n", newUnit);
    }
  } else if (initialUnit == '\0') {
      printf("%c is not a valid temperature type. Ending program.\n", initialUnit);

  } else {
      printf("Invalid formatting. Ending program.\n");
  }
}

// determines whether user picked distance, temperature, or neither
void distanceOrTemperature(char userInput) {
  switch (userInput) {
    case 'D':
      distanceConversion();
      break;
    case 'T':
      temperatureConversion();
      break;
    default:
      invalidInput(userInput);
      break;
  }
}

// gathers initial user input
char getUserInput() {
  char userInput;
  printf("Pick the type of conversion that you would like to do.\n");
  printf("T or t for temperature\n");
  printf("D or d for distance\n");
  printf("Enter your choice: ");
  scanf(" %c", &userInput);
  userInput = toupper(userInput);
  return userInput;
}

// calls other functions
int main() {
  char userInput = getUserInput();
  distanceOrTemperature(userInput);
  return 0;
}
