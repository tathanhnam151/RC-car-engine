#include <SoftwareSerial.h>
#define LED 13
SoftwareSerial BT1serial(2, 3); // RX | TX

char c = ' ';

void setup()
{
  // start the serial communication with the host computer
  Serial.begin(9600);
  Serial.println("Arduino with HC-05 is ready");

  // start communication with the HC-05 using 9600
  BT1serial.begin(9600);
  Serial.println("BTserial started at 9600");
}

void loop()
{

  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (BT1serial.available())
  {
    c = BT1serial.read();
    Serial.write(c);
  }

  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
  {
    c =  Serial.read();
    BT1serial.write(c);
  }
}
