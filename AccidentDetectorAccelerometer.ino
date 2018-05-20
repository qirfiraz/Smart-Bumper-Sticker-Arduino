  int prevx = 0;
  int prevy = 0;
  int prevz = 0;


void setup() {
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
   prevx = 0;
   prevy = 0;
   prevz = 0;

 }

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValuex = analogRead(A2);
  int sensorValuey = analogRead(A3);
  int sensorValuez = analogRead(A4);
 
 
if (  ( prevx != 0 && prevy !=0 && prevz !=0 )  &&            ( 
      (abs( prevx - sensorValuex ) > ( abs (prevx) /7) ) || 
      (abs( prevy - sensorValuey ) > ( abs (prevy) /7) ) || 
      (abs( prevz - sensorValuez ) > ( abs (prevz) /7) )      )
   ) 
   { 
    Serial.print(  abs( prevx - sensorValuex )); 
    Serial.print(",");  
    Serial.print(  abs( prevy - sensorValuey ));
    Serial.print(",");   
    Serial.print(  abs( prevz - sensorValuez )); 
    Serial.print(",");  
    Serial.println("xyz");
   }
     
   prevx = sensorValuex;
   prevy = sensorValuey;
   prevz = sensorValuez;

  
  delay(500);        // delay in between reads for stability
}

