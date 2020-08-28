#include <assert.h>
#include<iostream>
using namespace std;

const float bpmLimits[] = {70,150};
const float spo2Limits[] = {90,100};
const float respRateLimits[] = {30,95};

class Alert
{
  public:
    virtual void SendAlert(const char* VitalName, const char* message) = 0;
}
class AlertInSMS : public Alert
{
  public:
   void SendAlert(const char* VitalName, const char* message) override
   { cout<<"SMS sent:"<< VitalName << " " << message << endl;
   }
};

class AlertInSound : public Alert
{
  public:
   void SendAlert(const char* VitalName, const char* message) override
   { cout<<"Alarm sound:"<< VitalName << " " << message << endl;
   }
};

bool vitalIsOk(const char* VitalName,float value, const int lowerlimit,const int upperlimit, Alert* alert)
{
  if (value < lowerlimit)
  { alert->SendAlert( VitalName, "is low");
  return false; 
  else if (value > upperlimit)
     { alert->SendAlert( VitalName, "is high");
           return false; }
  else
  {
        return true;
   }
 }
 
bool vitalsAreOk(float bpm, float spo2, float respRate,Alert* alert) {
  
   return (vitalIsOk("BPM", bpm, bpmLimits[0], bpmLimits[1],alert ) 
    && vitalIsOk( "SPO2", spo2, spo2Limits[0], spo2Limits[1],alert ) 
    && vitalIsOk("Respiration Rate", respRate, respRateLimit[0], respRateLimits[1]),alert );
  
}
int main() {
  Alert* alert = new AlertInSMS();
  assert(vitalsAreOk(80, 95, 60) == true);
  
   alert = new AlertInSMS();
  assert(vitalsAreOk(60, 90, 40) == false);
}
