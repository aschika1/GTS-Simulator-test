/* 
 Ground Tracking Station Simulation Software for Interfacing with RPi web based multithreading
 Andrew Chika
 */


#include <Wire.h>
//#include <Adafruit_MotorShield.h>
//#include "utility/Adafruit_PWMServoDriver.h"
//#define mag_add 0x0F  //7-bit address of slave device
//#define accel_add 0x1E  //7-bit address of slave device
#define M_PI   3.14159265358979323846	/* pi */
//Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
//initialize motors, giving names and port configs
//Adafruit_StepperMotor *azimuth_motor = AFMS.getStepper(96, 1);
//Adafruit_StepperMotor *elevation = AFMS.getStepper(96, 2);


//intialize variable for accelerometer data
int accel_x_rawLB;
int accel_x_rawHB;
int accel_x_raw;
long int accel_max[3];
double accel_ref;
double accel_x_data;
double elevation_angle;

//initialize global calibration variables. needed for calculating current azimuth

double x_axis_max;
double x_axis_min;
double y_axis_max;
double y_axis_min;
double x_offset;
double y_offset;
double sigma_x;
double theta;


void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps

  //  AFMS.begin();
  //  azimuth_motor->setSpeed(100);
  //  elevation->setSpeed(50);
  //  Wire.begin();
  //  i2cwrite(accel_add,0x20,0x31);  
  delay(20);
  //  i2cwrite(mag_add,0x1C,0x00);  // configure data rate to 400Hz
  //  i2cwrite(mag_add,0x1B,0x90);  






}

void loop() 
{
  double cw_max = 180;
  double ccw_max = 185;
  double az_o;
  double az_i;
  boolean zero_xing = false;
  boolean cw_max_breach = false;
  boolean ccw_max_breach = false;
  boolean cw_rot = false;
  boolean ccw_rot = false;
  boolean north = false;
  boolean startup = true;
  double cw_delta;
  double ccw_delta;
  double az;
  double UL_3;
  double LL_3;
  double UL_1;
  double LL_1;

  double e;
  double e_o;
  double e_i;
  double delta_e;

  Serial.println("Ready to engage!!");
  String engage = "";
  while(startup)
  {
    if(Serial.available()>0)
    { 
      char readChar = Serial.read(); 

      // If the next character is a linefeed (enter)
      // the name is complete. Exit the while() loop.
      engage += readChar;
      if (readChar == '\n')
      {
        if(engage == "engage\n")
        {
          Serial.println("Warp Tracking Engaged Captain!");
          startup = false;
        }
        else if(engage != "engage")
        {
          engage = "";
        }
      }
    }
  }

  Serial.println("Ground tracking platform begin!");
  Serial.print("Accel Dev ID is: fake");
  //  Serial.println(i2cread(accel_add,0x1E)); //read accelerometer device id
  Serial.print(" Mag dev ID is: fake");
  //  Serial.println(i2cread(mag_add,0x0F)); //read accelerometer device id

  Serial.println("Level Complete");
  delay(10);

  Serial.println("At this point calibration would be completed");
  while(1)
  {

    //PROMPT USER FOR AZIMUTH INFO
    Serial.println("Enter Azimuth:");
    while (Serial.available() == 0) ;  // Wait here until input buffer has a character
    {
      //Side 1
      az_o = Serial.parseFloat();        // new command in 1.0 forward
      while (Serial.available() > 0)  // .parseFloat() can leave non-numeric characters
      { 
        Serial.read() ;  // clear the keyboard buffer
      }     
    }
    Serial.println("Enter Elevation:");
    while (Serial.available() == 0) ;  // Wait here until input buffer has a character
    {
      e_o = Serial.parseFloat();
      while (Serial.available() > 0)  // .parseFloat() can leave non-numeric characters
      { 
        Serial.read() ;  // clear the keyboard buffer
      }     
    }    
    Serial.print("Destination Azimuth: "); 
    Serial.println(az_o, DEC);
    Serial.print("Destination Elevation: "); 
    Serial.println(e_o, DEC);

    //DETERMINE CURRENT POSITONS

    //    az_i = measure_az_fine();
    //   e_i = measure_e();
    Serial.println("Current azimuth: poopy");
    //    Serial.println(az_i);
    Serial.println("Current elevation: Extra poopy");
    //   Serial.println(e_i);



    delay(2000);
    Serial.print("Current Azimuth: Finished");
    Serial.println("Current elevation: Finished");
    Serial.print("CW max: Finished");
    Serial.print("CCW max: Finished");




  }
}






