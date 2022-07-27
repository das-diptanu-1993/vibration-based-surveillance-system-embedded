int sensePinX = 8; int sensePinY = 9;
int sensePinZ = 10;
int ledPinX = 10;
int ledPinY = 11;
int ledPinZ = 12;
int powerPin = 13;
int th = 10;
void setup() {
  pinMode(sensePinX, INPUT);
  pinMode(sensePinY, INPUT);
  pinMode(sensePinZ, INPUT);
  pinMode(ledPinX, OUTPUT);
  pinMode(ledPinY, OUTPUT);
  pinMode(ledPinZ, OUTPUT);
  pinMode(powerPin, OUTPUT);
  Serial.begin(9600);}
void loop() {
  int valueX = 0;
  int previousX = 0;
  int valueY = 0;
  int previousY = 0;
  int valueZ = 0;
  int previousZ = 0;
  digitalWrite(powerPin, HIGH);
  while(1){
      valueX = analogRead(sensePinX);
      valueY = analogRead(sensePinY);
      valueZ = analogRead(sensePinZ);
      int changeX = abs(valueX - previousX);
      int changeY = abs(valueY - previousY);
      int changeZ = abs(valueZ - previousZ);
      previousX = valueX;
      previousY = valueY;
      previousZ = valueZ;
      if(changeX>th){
          digitalWrite(ledPinX, HIGH);
          Serial.print("Vibration in x_axis detected. Intensity: ");
          Serial.print(changeX);
          Serial.println();
          delay(1000);}
      else{
          digitalWrite(ledPinX, LOW);}
      if(changeY>th){
          digitalWrite(ledPinY, HIGH);
          Serial.print("Vibration in y_axis detected. Intensity: ");
          Serial.print(changeY);
          Serial.println();
          delay(1000);}
      else{
          digitalWrite(ledPinY, LOW);}
      if(changeZ>th){
          digitalWrite(ledPinZ, HIGH);
          Serial.print("Vibration in z_axis detected. Intensity: ");
          Serial.print(changeZ);
          Serial.println();
          delay(1000);}
      else{
          digitalWrite(ledPinZ, LOW);}
      Serial.print(changeX);
      Serial.print(" ");
      Serial.print(changeY);
      Serial.print(" ");
      Serial.print(changeZ);
      Serial.println();}}

