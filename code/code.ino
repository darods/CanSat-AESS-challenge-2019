/* Written by el-nasa (Daniel Alejandro Rodriguez) 2019
 *  GitHub : https://github.com/el-NASA
 *  Project : https://github.com/el-NASA/CanSat-AESS-challenge-2019
 *  
* The main purpose of this arduino sketch is to provide an useful code to make the data logger for a cansat or a model rocket.
* The necessary libraries to execute it are:
*
*MPU6050 : https://github.com/jarzebski/Arduino-MPU6050 by Korneliusz Jarzebski
*BMP 280 : https://github.com/adafruit/Adafruit_BMP280_Library (if you have the chinese version you will have to change the I2C address from 0x77 to 0x76 (or something like that))
* Reference Project : 
* Arduino Rocket Data Logger : https://www.instructables.com/id/Arduino-Rocket-Data-Logger/ by calmac_projects
*/

 //Declaring libraries
#include <MPU6050.h>//Library for the  6 axis accelerometer and gyro
#include <Adafruit_BMP280.h>

//Declaring the Sensors
MPU6050 mpu;
Adafruit_BMP280 bmp;

//MPU6050 variables
float timeStep = 0.1;//It is used for calculating pitch, roll and yaw, you can find the original example
//in the MPU6050 examples (MPU6050_gyro_pitch_roll_yaw)

// Pitch, Roll and Yaw values
float pitch = 0;
float roll = 0;
float yaw = 0;

//Free fall variables
boolean ledState = false;
boolean freefallDetected = false;
int freefallBlinkCount = 0;



// BMP280 Variables
float reference;



// Interval between data records in milliseconds.
// The interval must be greater than the maximum SD write latency plus the
// time to acquire and write data to the SD to avoid overrun errors.
// Run the bench example to check the quality of your SD card.
const uint32_t SAMPLE_INTERVAL_MS = 500;

// Time in micros for next data record.
uint32_t logTime = 0;


void setup() {
  Serial.begin(9600);

  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_16G))
  {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }  
  // Calibrate gyroscope. The calibration must be at rest.
  mpu.calibrateGyro();

  // Set threshold sensivty. Default 3.
  // If you don't want use threshold, comment this line or set 0.
  mpu.setThreshold(3);
  mpu.setDHPFMode(MPU6050_DHPF_5HZ);

  mpu.setFreeFallDetectionThreshold(17);
  mpu.setFreeFallDetectionDuration(2); 
  attachInterrupt(0, doInt, RISING); 

  //Initialize BMP280 sensor   
  if (!bmp.begin()) {  
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  }
  reference = bmp.readAltitude(1013.25);
 
}

void loop() {
  logData();
  
  delay(SAMPLE_INTERVAL_MS);
   // Time for next record.
  logTime += SAMPLE_INTERVAL_MS ;

}
