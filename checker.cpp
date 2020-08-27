#include <assert.h>

const int bpmlimits[] = {70,150};
const int respRatecheck[] = {30,95};

bool bpmisOk(float bpm)
{
  return (bpm > bpmlimits[0] && bpm < bpmlimits[1];
 }
 
bool spo2isOk(float spo2)
 { 
   return (spo2 < 90); 
 }

bool respRateisOk(float respRate)
 {
    return (respRate > respRatecheck[0] && respRate < respRatecheck[1];
 }

bool vitalsAreOk(float bpm, float spo2, float respRate) {
  return(bpmisOk(bpm) && spo2isOk(spo2) && respRateisOk(respRate)) ;
}

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
}
