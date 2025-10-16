int Pin[3] = {9, 10, 11}; //R:9,G:10,B:11
int ButtonPin = 8;
int Mood = 0;
int NaturalMood = 10;
bool Press = 0;

void setup() {
  for(int i=0;i<3;i++){
    pinMode(Pin[i], OUTPUT);
  }
  pinMode(ButtonPin, INPUT);
  Serial.begin(9600);
}

void loop() {

  float Brightness = 255 / 10.0;
  if(Mood % 21 <= NaturalMood){
    analogWrite(9 , 0);
    analogWrite(10 , 255 - Brightness * (Mood % 21 - NaturalMood));
    analogWrite(11 , Brightness * (Mood % 21 - NaturalMood));
  }
  else
  {
    analogWrite(9 , Brightness * (Mood % 21 - NaturalMood));
    analogWrite(10 , 255 - Brightness * (Mood % 21 - NaturalMood));
    analogWrite(11 , 0);
  }
  
  if(!digitalRead(ButtonPin) && !Press){
    Press = 1;
    Mood++;
  }
  else if(digitalRead(ButtonPin) && Press)
  {
    Press = 0;
  }
}