#include <DS3231.h>
#include <Wire.h>
#include <Servo.h>

DS3231 Clock;
byte Hour;
byte Minute;
byte Second;

bool h, Pm;

int hour;
int minute;
int second;
int shag;
Servo serv;

const int buzz = 9;

void test() {
  Serial.print(hour);
  Serial.print(' ');
  Serial.print(minute);
  Serial.print(' ');
  Serial.print(second);
  Serial.print(' ');
  Serial.println();
}
void Time() {
  Clock.setClockMode(false); // 24h if true = 12h
  Clock.setHour(14);
  Clock.setMinute(59);
  Clock.setSecond(51);
}

void Start() {
  tone(buzz, 200); delay(500); noTone(buzz);
  tone(buzz, 400); delay(500); noTone(buzz);
  tone(buzz, 600); delay(500); noTone(buzz);
}

void End() {
  tone(buzz, 600); delay(500); noTone(buzz);
  tone(buzz, 400); delay(500); noTone(buzz);
  tone(buzz, 200); delay(500); noTone(buzz);
}



void setup() {
  pinMode(buzz, OUTPUT);
  Wire.begin(); // start i2c intrfc
  Serial.begin(9600); // start srl interfc
}

void loop() {
  //Time();
  hour = Clock.getHour(h, Pm);
  minute = Clock.getMinute();
  second = Clock.getSecond();

  test();
  // Morning
  if (hour == 9 && minute == 00 && second == 02 ) {
    Start(); // play melody
    serv.attach(6);
    serv.write(0); //open the kormushka
    delay(1000);
    serv.detach();
    delay(180000); // 3 minutes. change it for bigger or smaller pause
    End();
    serv.attach(6);
    delay(100);
    for (int i=0; i <= 160; i++)
    {
      serv.write(i);
      delay(20);
    }
    serv.detach();
  }
  else if (hour == 10 && minute == 00 && second == 02 ) {
    Start(); // play melody
    serv.attach(6);
    serv.write(0); //open the kormushka
    delay(1000);
    serv.detach();
    delay(180000); // 3 minutes. change it for bigger or smaller pause
    End();
    serv.attach(6);
    delay(100);
    for (int i=0; i <= 160; i++)
    {
      serv.write(i);
      delay(20);
    }
    serv.detach();
  }
  else if (hour == 11 && minute == 00 && second == 02 ) {
    Start(); // play melody
    serv.attach(6);
    serv.write(0); //open the kormushka
    delay(1000);
    serv.detach();
    delay(180000); // 3 minutes. change it for bigger or smaller pause
    End();
    serv.attach(6);
    delay(100);
    for (int i=0; i <= 160; i++)
    {
      serv.write(i);
      delay(20);
    }
    serv.detach();
  }
  // Evening
  else if (hour == 20 && minute == 00 && second == 02 ) {
    Start(); // play melody
    serv.attach(6);
    serv.write(0); //open the kormushka
    delay(1000);
    serv.detach();
    delay(180000); // 3 minutes. change it for bigger or smaller pause
    End();
    serv.attach(6);
    delay(100);
    for (int i=0; i <= 160; i++)
    {
      serv.write(i);
      delay(20);
    }
    serv.detach();
  }
  else if (hour == 21 && minute == 00 && second == 02 ) {
    Start(); // play melody
    serv.attach(6);
    serv.write(0); //open the kormushka
    delay(1000);
    serv.detach();
    delay(180000); // 3 minutes. change it for bigger or smaller pause
    End();
    serv.attach(6);
    delay(100);
    for (int i=0; i <= 160; i++)
    {
      serv.write(i);
      delay(20);
    }
    serv.detach();
  }
  else if (hour == 22 && minute == 00 && second == 02 ) {
    Start(); // play melody
    serv.attach(6);
    serv.write(0); //open the kormushka
    delay(1000);
    serv.detach();
    delay(180000); // 3 minutes. change it for bigger or smaller pause
    End();
    serv.attach(6);
    delay(100);
    for (int i=0; i <= 160; i++)
    {
      serv.write(i);
      delay(20);
    }
    serv.detach();
  }
  //Testing open/close
  if (second % 30 == 0) {
    serv.attach(6);
    serv.write(170);
    delay(1000);
    serv.detach();
  }
}
