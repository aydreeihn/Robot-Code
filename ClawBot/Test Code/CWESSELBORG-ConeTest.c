

task main()

ultrasonicInit()

{
 while (true)
 {
  motor[rightMotor] = SensorValue(sonarSensor) / 2;
  motor[leftMotor] = SensorValue(sonarSensor) / 2;
 }
}
