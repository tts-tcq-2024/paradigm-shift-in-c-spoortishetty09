#include <stdio.h>
#include <assert.h>

int isTemperatureOk(float temperature) {
  return (temperature >= 0 && temperature <= 45);
}

int isSocOk(float soc) {
  return (soc >= 20 && soc <= 80);
}

int isChargeRateOk(float chargeRate) {
  return (chargeRate <= 0.8);
}

void printErrorMessage(float temperature, float soc, float chargeRate) {
  if (!isTemperatureOk(temperature)) {
    printf("Temperature out of range!\n");
  }
  if (!isSocOk(soc)) {
    printf("State of Charge out of range!\n");
  }
  if (!isChargeRateOk(chargeRate)) {
    printf("Charge Rate out of range!\n");
  }
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
  int tempOk = isTemperatureOk(temperature);
  int socOk = isSocOk(soc);
  int chargeRateOk = isChargeRateOk(chargeRate);

  if (!tempOk || !socOk || !chargeRateOk) {
    printErrorMessage(temperature, soc, chargeRate);
  }
  
  return tempOk && socOk && chargeRateOk;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  return 0;
}
