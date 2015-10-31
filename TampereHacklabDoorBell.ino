/*Tampere Hacklab doorbell ringer
 * 
 * Arduino controlled bell ringer.
 * Two tone bell is connected trough
 * H-Bridge L293D IC.
 * 
 * Pin 5 goes low when button is pressed.
 * Pin 3 and 4 are H-Bridge control lines,
 * when either is high, hammer is pulled
 * to corresponding bell (high and low tone)
 * Pin 6 is H-bridge enable, pull high
 * 
 * Ketturi 2015
 */

//Some defines
const int ButtonPin = 5;
const int LowBellPin = 3;
const int HighBellPin = 4;
const int HBrEnable = 6;
const int HammerTime = 50;      //How long hammer solennoid is powered
const int PullBackTime = 5;     //Time to pull hammer away from bell
int counter = 0;

void setup() {
  //Set pin direction
  pinMode(ButtonPin, INPUT_PULLUP);
  pinMode(LowBellPin, OUTPUT);
  pinMode(HighBellPin, OUTPUT);
  pinMode(HBrEnable, OUTPUT);

  //Make extra sure everything is low!
  digitalWrite(LowBellPin, LOW);
  digitalWrite(HighBellPin, LOW);
  digitalWrite(HBrEnable, LOW);
}

void loop() {
  if (digitalRead(ButtonPin) == LOW) {
    if (counter >= 1){ //If button is held down bell will ring faster
      DoorBellRing();
      }
    
    else {             //If button is quiqly pressed it will just ring once
      counter = counter+1;
      PlayBellSingle();
      delay(500);
      }
    
  if (digitalRead(ButtonPin) == HIGH){
    counter = 0;
    }
  } 
 }

void PlayBellSingle(){   //Doorbell single ring
  RingHighBell();
  delay(500);
  RingLowBell();
 }


void DoorBellRing(){  // This is just for dull ringing, like old phone
  RingHighBell();
  delay(25);
  RingLowBell();
  delay(25);
}


void RingHighBell(){ //pull hammer to high tone bell
  digitalWrite(HBrEnable, HIGH);
  digitalWrite(HighBellPin, HIGH); //Strike
  delay(HammerTime);
  digitalWrite(HighBellPin, LOW);
  
  digitalWrite(LowBellPin, HIGH);  //PullBack
  delay(PullBackTime);
  digitalWrite(LowBellPin, LOW);
  digitalWrite(HBrEnable, LOW);
 }

void RingLowBell(){ //pull hammer to low tone bell
  digitalWrite(HBrEnable, HIGH);
  digitalWrite(LowBellPin, HIGH); //Strike
  delay(HammerTime);
  digitalWrite(LowBellPin, LOW);
  
  digitalWrite(HighBellPin, HIGH); //PullBack
  delay(PullBackTime);
  digitalWrite(HighBellPin, LOW);
  digitalWrite(HBrEnable, LOW);
 }

  /* 
   * In a world of magnets and miracles
   * Our thoughts strayed constantly and without boundary
   * The ringing of the division bell had begun
   *  High Hopes - Pink Floyd
   */
