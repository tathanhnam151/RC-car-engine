#define RIGHTMOVE 13
#define RIGHTREV 12
#define LEFTMOVE 11
#define LEFTREV 10

void setup()
{
  Serial.begin(9600);
  Serial.println("Arduino with HC-06 is ready");

  Serial1.begin(9600);
  Serial1.println("BTSerial started at 9600");
  pinMode(RIGHTMOVE, OUTPUT);
  pinMode(RIGHTREV, OUTPUT);
  pinMode(LEFTMOVE, OUTPUT);
  pinMode(LEFTREV, OUTPUT);
}

void loop()
{

  // Keep reading from HC-06 and send to Arduino Serial Monitor
  if (Serial1.available())
  {
    Serial.write(Serial1.read());
  }
  digitalWrite(RIGHTMOVE, LOW);
  digitalWrite(LEFTMOVE, LOW);
  digitalWrite(RIGHTREV, LOW);
  digitalWrite(LEFTREV, LOW);
  delay(5);
  //   Keep reading from Arduino Serial Monitor and send to HC-06
  if (Serial.available())
  {
    Serial1.write(Serial.read());
  }
  char data = Serial1.read();
  switch (data) // đọc dữ liệu của chuỗi
  {
    case 'w': {
        digitalWrite(RIGHTMOVE, HIGH);
        digitalWrite(LEFTMOVE, HIGH);
        break;
      }
    case 'a': digitalWrite(RIGHTMOVE, HIGH); break;
    case 's': {
        digitalWrite(RIGHTMOVE, HIGH);
        digitalWrite(LEFTMOVE, HIGH);
        digitalWrite(LEFTREV, HIGH);
        digitalWrite(RIGHTREV, HIGH);
        break;
      }
    case 'd': digitalWrite(LEFTMOVE, HIGH); break;
    default : break;
  }
  delay(100);
}
