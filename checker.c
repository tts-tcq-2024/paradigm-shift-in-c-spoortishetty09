#include <stdio.h>
#include <assert.h>

// Check if temperature is within acceptable range
int isTemperatureOk(float temperature) {
  return (temperature >= 0 && temperature <= 45);
}

// Check if State of Charge is within acceptable range
int isSocOk(float soc) {
  return (soc >= 20 && soc <= 80);
}

// Check if Charge Rate is within acceptable range
int isChargeRateOk(float chargeRate) {
  return (chargeRate <= 0.8);
}

// Print error messages if any checks fail
void printErrors(int tempOk, int socOk, int chargeRateOk) {
  if (!tempOk) {
    printf("Temperature out of range!\n");
  }
  if (!socOk) {
    printf("State of Charge out of range!\n");
  }
  if (!chargeRateOk) {
    printf("Charge Rate out of range!\n");
  }
}

// Check battery parameters and print errors if any
int batteryIsOk(float temperature, float soc, float chargeRate) {
  int tempOk = isTemperatureOk(temperature);
  int socOk = isSocOk(soc);
  int chargeRateOk = isChargeRateOk(chargeRate);

  printErrors(tempOk, socOk, chargeRateOk);

  return tempOk && socOk && chargeRateOk;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  return 0;
}
