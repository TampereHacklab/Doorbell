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
    digitalWrite(HBrEnable, HIGH);
    PlayBellSingle();
    delay(1000);
    PlayBellSingle();
    delay(2000);
  }
  
  while (digitalRead(ButtonPin) == HIGH) {
    digitalWrite(HBrEnable, LOW);
  }
 }

void PlayBellSingle(){   //doorbell music goes here!
  RingHighBell();
  delay(500);
  RingLowBell();
 }

/* This is just for dull ringing, like old phone
void DoorBellRing(){
  RingHighBell();
  delay(25);
  RingLowBell();
  delay(25);
}
*/

void RingHighBell(){ //pull hammer to high tone bell
  digitalWrite(HighBellPin, HIGH); //Strike
  delay(HammerTime);
  digitalWrite(HighBellPin, LOW);
  
  digitalWrite(LowBellPin, HIGH);  //PullBack
  delay(PullBackTime);
  digitalWrite(LowBellPin, LOW);
 }

void RingLowBell(){ //pull hammer to low tone bell
  digitalWrite(LowBellPin, HIGH); //Strike
  delay(HammerTime);
  digitalWrite(LowBellPin, LOW);
  
  digitalWrite(HighBellPin, HIGH); //PullBack
  delay(PullBackTime);
  digitalWrite(HighBellPin, LOW);
 }

  /* 
   * In a world of magnets and miracles
   * Our thoughts strayed constantly and without boundary
   * The ringing of the division bell had begun
   *  High Hopes - Pink Floyd
   */
