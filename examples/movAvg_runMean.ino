/*Tomas de Camino Beck 
   using running mean over analog values
*/
#include "runmean.h"
#include "movingAvg.h"     

#define NVALUES 10 //sensor Window hereda esta cantidad

//create the object for a NVALUES value running mean
TrunMean runMean(NVALUES);


movingAvg avg_sensor(10); //Ventana del sensor debe ser ajustada segun periodicidad

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Read de analog pin
  float  val [i] = analogRead(A0);
  //add new value
  runMean.addNew(val);
  //get the running mean with new value and NVALUES-1 previous
  int pre_processed_value=runMean.getMean();
  int moving_avg = avg_sensor.reading(pre_processed_value);
  Serial.println(moving_avg); 


  delay(1000);
}


//things to add to github