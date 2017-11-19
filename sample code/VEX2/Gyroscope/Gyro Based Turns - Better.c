#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*+++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++++++++
Gyro Based Turns - Better
-This program instructs your robot to turn for the specified number of degrees in "degrees10".
-The first while loop moves the robot most of the way toward the specified number of degrees, exiting
 10 degrees (100 sensor counts) short of the goal.
-This program includes a second while loop which will allow the robot to turn more slowly toward its
 goal, eliminating much of the drift in the system.
-For best sensor results, clear out the gyro and manually configure it at the begging of the code.
-The Gyro is configured by default to provide values from 0 to -3600 for clockwise rotation,
 and 0 to 3600 for counter-clockwise rotation

Robot Model(s): Swervebot

[I/O Port]          [Name]              [Type]                [Description]
Motor Port 2        rightMotor          VEX Motor             Right side motor
Motor Port 3        leftMotor           VEX Motor             Left side motor
Analog Port 8       in8                 VEX Gyro              Top-center mounted,
                                                              away from the Cortex
----------------------------------------------------------------------------------------------------*/

task main()
{
  //Completely clear out any previous sensor readings by setting the port to "sensorNone"
  SensorType[in8] = sensorNone;
  wait1Msec(1000);
  //Reconfigure Analog Port 8 as a Gyro sensor and allow time for ROBOTC to calibrate it
  SensorType[in8] = sensorGyro;
  wait1Msec(2000);


  //Specify the number of degrees for the robot to turn (1 degree = 10, or 900 = 90 degrees)
  int degrees10 = 900;

  //While the absolute value of the gyro is less than the desired rotation - 100...
  while(abs(SensorValue[in8]) < degrees10 - 100)
  {
    //...Continue turning
    motor[rightMotor] = 100;
    motor[leftMotor] = -100;
  }
  //Brief brake to eliminate some drift
  motor[rightMotor] = -5;
  motor[leftMotor] = 5;
  wait1Msec(100);

  //Second while loop to move more slowly toward the goal
  while(abs(SensorValue[in8]) != degrees10)
  {
    if(abs(SensorValue[in8]) > degrees10)
    {
      motor[rightMotor] = -30;
      motor[leftMotor] = 30;
    }
    else
    {
      motor[rightMotor] = 30;
      motor[leftMotor] = -30;
    }
  }
  //Stop
  motor[rightMotor] = 0;
  motor[leftMotor] = 0;
  wait1Msec(250);
}