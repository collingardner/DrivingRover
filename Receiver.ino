#include <Wire.h>
String passback = "";
void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop() {
 delay(200);
 Serial.println(passback);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
int old = 0;
int x = 1;
void receiveEvent(int howMany) {
  
  if(old != x){
  
  String str = "";
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    //Serial.print(c);// print the character
    str.concat(c);
  }
  int x = Wire.read();    // receive byte as an integer
    //passback = str + x ;
  if(x < 7 && str.equals("L")){
    passback = "Dont Turn Left";
  }
  else if(x < 7 && str.equals("R")){
    passback = "Dont Turn Right";
  }
  else if(x < 7 && str.equals("B")){
    passback = "Dont Go Back";
  }
  else{
   // passback = "Everything is fine";
  }
  ///Serial.println(str + x);// print the integer
}
}
