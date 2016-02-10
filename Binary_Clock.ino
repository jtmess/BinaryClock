int secs = 0, mins = 13, hours = 8;

void setup() {
  for (int k = 2; k <= 21; k++) {
    pinMode(k, OUTPUT);
  }
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  Serial.begin(9600);
}

void loop() {

  static unsigned long lastTick = 0;
  if (millis() - lastTick >= 1000) {
    lastTick = millis();
    secs++;

  }
  if (secs >= 60) {
    mins++;
    secs = 0; // reset seconds to zero
  }
  if (mins >= 60) {
    hours++;
    mins = 0;

  }
  if (hours >= 24) {
    hours  = 0;
    mins  = 0; // reset minutes to zero
  }
  int sunit = secs % 10;
  int munit = mins % 10; //sets the variable munit and hunit for the unit digits
  int hunit = hours % 10;
  Serial.println(sunit);
  if(sunit == 1 || sunit == 3 || sunit == 5 || sunit == 7 || sunit == 9) {  digitalWrite(11, HIGH);} else {  digitalWrite(11,LOW);}
  if(sunit == 2 || sunit == 3 || sunit == 6 || sunit == 7) {digitalWrite(12, HIGH);} else {digitalWrite(12,LOW);}
  if(sunit == 4 || sunit == 5 || sunit == 6 || sunit == 7) {digitalWrite(13, HIGH);} else {digitalWrite(13,LOW);}
  if(sunit == 8 || sunit == 9) {digitalWrite(8, HIGH);} else {digitalWrite(8,LOW);}

  //minutes 
  if((secs >= 10 && secs < 20) || (secs >= 30 && secs < 40) || (secs >= 50 && secs < 60))  {digitalWrite(19, HIGH);} else {digitalWrite(19,LOW);}
  if(secs >= 20 && secs < 40)  {digitalWrite(9, HIGH);} else {digitalWrite(9,LOW);}
  if(secs >= 40 && secs < 60) {digitalWrite(10, HIGH);} else {digitalWrite(10,LOW);}

  
    //minutes units
  if(munit == 1 || munit == 3 || munit == 5 || munit == 7 || munit == 9) {  digitalWrite(4, HIGH);} else {  digitalWrite(4,LOW);}
  if(munit == 2 || munit == 3 || munit == 6 || munit == 7) {digitalWrite(5, HIGH);} else {digitalWrite(5,LOW);}
  if(munit == 4 || munit == 5 || munit == 6 || munit == 7) {digitalWrite(6, HIGH);} else {digitalWrite(6,LOW);}
  if(munit == 8 || munit == 9) {digitalWrite(7, HIGH);} else {digitalWrite(7,LOW);}

  //minutes 
  if((mins >= 10 && mins < 20) || (mins >= 30 && mins < 40) || (mins >= 50 && mins < 60))  {digitalWrite(16, HIGH);} else {digitalWrite(16,LOW);}
  if(mins >= 20 && mins < 40)  {digitalWrite(21, HIGH);} else {digitalWrite(21,LOW);}
  if(mins >= 40 && mins < 60) {digitalWrite(3, HIGH);} else {digitalWrite(3,LOW);}

  //hour units
  if(hunit == 1 || hunit == 3 || hunit == 5 || hunit == 7 || hunit == 9) {digitalWrite(17, HIGH);} else {digitalWrite(17,LOW);}
  if(hunit == 2 || hunit == 3 || hunit == 6 || hunit == 7) {digitalWrite(18, HIGH);} else {digitalWrite(18,LOW);}
  if(hunit == 4 || hunit == 5 || hunit == 6 || hunit == 7) {digitalWrite(14, HIGH);} else {digitalWrite(14,LOW);}
  if(hunit == 8 || hunit == 9) {digitalWrite(2, HIGH);} else {digitalWrite(2,LOW);}  //secs are pins 11, 12, 13, 8

  //hour
  if(hours >= 10 && hours < 20)  {digitalWrite(15, HIGH);} else {digitalWrite(15,LOW);}
  if(hours >= 20 && hours < 24)  {digitalWrite(20, HIGH);} else {digitalWrite(20,LOW);}

   //int vals = analogRead(A0);    // add one minute when pressed
   if(digitalRead(A0)==HIGH) {
   secs++;
   //secs = 0;
   delay(400);
  }
  
   //int valm = analogRead(A1);    // add one minute when pressed
   if(digitalRead(A1)==HIGH) {
   mins++;
   //secs = 0;
   delay(400);
  }
  
   //int valh = analogRead(A2);    // add one hour when pressed
   if(digitalRead(A2)==HIGH) {
   hours++;
   //secs = 0;
   delay(400);
  }
  //Serial.println( vals);
  
}

void setclock() {

}

