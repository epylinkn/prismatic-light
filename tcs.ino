/*     Arduino Color Sensing Tutorial
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */
 
#define S0 D5
#define S1 D6
#define S2 D7
#define S3 D8
#define sensorOut D1
#define TCSLED D2
#define sensorEnable D3

int frequency = 0;

void tcsSetup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  pinMode(sensorEnable, OUTPUT);
  pinMode(TCSLED, OUTPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);

  digitalWrite(sensorEnable, LOW);
  digitalWrite(TCSLED, LOW);
}

void tcsLoop() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print("\t");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("\t");//printing name
  delay(100);

  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print("\t");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("\t");//printing name
  delay(100);

  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print("\t");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.println("\t");//printing name
  delay(100);
}
