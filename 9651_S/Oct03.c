#pragma config(Sensor, dgtl1,  solenoid1,            sensorDigitalOut)
#pragma config(Sensor, dgtl2,  solenoid2,            sensorDigitalOut)
#pragma config(Motor,  port2,           frontRight,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           backRight,     tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port4,           frontLeft,     tmotorNormal, openLoop)
#pragma config(Motor,  port5,           backLeft,      tmotorNormal, openLoop)
#pragma config(Motor,  port6,           rightArm,     tmotorNormal, openLoop)
#pragma config(Motor,  port7,           leftArm,     tmotorNormal, openLoop)
#pragma config(Motor,  port8,           grabberArm,  tmotorNormal, openLoop)
//*!!Code automatically  generated by 'ROBOTC' configuration wizard               !!*//

/*+++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++++++++
Mecanum Drive - Basic
- This program allows you to remotely control a robot with mecanum wheels.
- The left joystick Y-axis controls the robot's forward and backward movement.
- The left joystick X-axis controls the robot's left and right movement.
- The right joystick X-axis controls the robot's rotation.

[I/O Port]          [Name]              [Type]                [Description]
Motor Port 2        frontRight          VEX Motor             Front Right motor
Motor Port 3        backRight           VEX Motor             Back Right motor
Motor Port 4        frontLeft           VEX Motor             Front Left motor
Motor Port 5        backLeft            VEX Motor             Back Left motor
----------------------------------------------------------------------------------------------------*/

task main()
{
  //Loop Forever
  while(1 == 1)
  {

  	bPlaySounds = false;

    //Remote Control Commands
    motor[frontRight] = vexRT[Ch3] - vexRT[Ch1] - vexRT[Ch4];
    motor[backRight] =  vexRT[Ch3] - vexRT[Ch1] + vexRT[Ch4];
    motor[frontLeft] = vexRT[Ch3] + vexRT[Ch1] + vexRT[Ch4];
    motor[backLeft] =  vexRT[Ch3] + vexRT[Ch1] - vexRT[Ch4];

   if(vexRT[Btn7U] == 1){
		bPlaySounds = true;
		playSoundFile("car");
		playSoundFile("car.wav");
		while(bSoundActive)
			wait1Msec(1);
	}

  if(vexRT[Btn6D] == 1){
  	 motor[rightArm] = 127;
  	 motor[leftArm] = 127;
	}
	else if(vexRT[Btn6U] == 1){
		 motor[rightArm] = -127;
		 motor[leftArm] = -127;
	}
	else{
		 motor[rightArm] = 0;
		 motor[leftArm] = 0;
	}

	if(vexRT[Btn5D] == 1){
		 motor[grabberArm] = 127;
	}
	else if(vexRT[Btn5U] == 1){
		 motor[grabberArm] = -127;
	}
	else{
		 motor[grabberArm] = 0;
	}

	if(vexRT[Btn8U] == 1)         // If button 6U (upper right shoulder button) is pressed:
    {
      SensorValue[solenoid1] = 1;
      SensorValue[solenoid2] = 1; // ...activate the solenoid.
    }
    else                          // If button 6U (upper right shoulder button) is  NOT pressed:
    {
      SensorValue[solenoid1] = 0;
      SensorValue[solenoid2] = 1; // ..deactivate the solenoid.
  }

}
}