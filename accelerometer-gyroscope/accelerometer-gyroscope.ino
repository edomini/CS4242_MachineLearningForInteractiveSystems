/*
  Arduino LSM9DS1 - Simple Accelerometer

  This example reads the acceleration values from the LSM9DS1
  sensor and continuously prints them to the Serial Monitor
  or Serial Plotter.

  The circuit:
  - Arduino Nano 33 BLE Sense

  created 10 Jul 2019
  by Riccardo Rizzo

  This example code is in the public domain.
*/

#include <Arduino_LSM9DS1.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Started");

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Acceleration in g's");
  Serial.println("X\tY\tZ");

  Serial.print("Gyroscope sample rate = ");
  Serial.print(IMU.gyroscopeSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Gyroscope in degrees/second");
  Serial.println("X\tY\tZ");
}

void loop() {
  float x, y, z;
  float a, b, c;

  if (IMU.accelerationAvailable() && IMU.gyroscopeAvailable()) {
    IMU.readAcceleration(x, y, z);
    IMU.readGyroscope(a, b, c);

    Serial.print('x');
    Serial.print(x);
    Serial.print('\t');
    Serial.print('y');
    Serial.print(y);
    Serial.print('\t');
    Serial.print('z');
    Serial.print(z);
    Serial.print('\t');
    Serial.print('a');
    Serial.print(a);
    Serial.print('\t');
    Serial.print('b');
    Serial.print(b);
    Serial.print('\t');
    Serial.print('c');
    Serial.print(c);
    Serial.println('\t');

  }
}