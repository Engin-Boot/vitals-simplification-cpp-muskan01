#include <assert.h>

const int bpmlimits[] = {70,150};
const int spo2check = 90;
const int respRatecheck[] = {30,95};

bool vitalIsOk(float value, int *limits)
{
  return (value >= limits[0] && value <= limits[1]);
 }
 
bool vitalcheck (float value, int checker)
{
  return (value >= checker);
}
bool vitalsAreOk(float bpm, float spo2, float respRate) {
  return(vitalIsOk(bpm,bpmlimits) && vitalcheck(spo2,spo2check) && vitalIsOk(respRate,respRatecheck));
}
int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
}
