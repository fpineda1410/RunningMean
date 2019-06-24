/*Tomas de Camino Beck 
   using running mean over analog values
*/
#include "runmean.h"

#define NVALUES 10

//create the object for a NVALUES value running mean
TrunMean runMean(NVALUES);

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Read de analog pin
  float  val = analogRead(A0);
  //ad new value
  runMean.addNew(val);
  //get the running mean with new value and NVALUES-1 previous
  Serial.println(runMean.getMean());
  delay(200);
}
