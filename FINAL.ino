int x = 0;
int y = 0;

void setup() {
   Serial.begin(9600);
    pinMode(5,INPUT);
    pinMode(3,INPUT);
    pinMode(4,INPUT);
    pinMode(6,INPUT);

  digitalWrite(5,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(6,HIGH);
}

void loop() {
  int South = digitalRead(5);
  int West = digitalRead(3);
  int North = digitalRead(4);
  int East = digitalRead(6);
  
  if(South == LOW){
    delay(200);
    Serial.println("K");
  }
   else if(West == LOW){
    delay(200);
    Serial.println("L");
  }
  else if(North == LOW){
    delay(200);
    Serial.println("I");
  }
   else if(East == LOW){
    delay(200);
    Serial.println("J");
  }

 x = analogRead(A0);
 y = analogRead(A1);


 if(y > 1000 && x == 507){
   delay(200);
   Serial.println("W");
 }
  if(y < 10 && x == 507){
   delay(200);
   Serial.println("X");
 }
  if(x < 10 && y == 514){
   delay(200);
   Serial.println("A");
 }
  if(x > 1000 && y == 514){
   delay(200);
   Serial.println("D");
 }

if(x == 507 && y == 514){
     delay(200);
     Serial.println("S");
}

if(x > 800 && y > 800){
     delay(200);
     Serial.println("E");
}

if(x < 10 && y > 800){
     delay(200);
     Serial.println("Q");
}

if(x < 10 && y < 50){
     delay(200);
     Serial.println("Z");
}

if(x > 800 && y < 514){
     delay(200);
     Serial.println("C");
}

  
}
