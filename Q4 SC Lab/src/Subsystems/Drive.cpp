/*
 * Drive.cpp
 *
 *  Created on: May 9, 2015
 *      Author: Adam
 */

#include <Subsystems/Drive.h>
#include "Commands/ArcadeDrive.h"
#include "../CommandBase.h"
#include <math.h>

Drive::Drive() : Subsystem("Drive"), left(new Talon(LEFT_MOTOR)), right(new Talon(RIGHT_MOTOR))
{
}

void Drive::setMoveConst(float m)
{
	mult = m;
}

void Drive::mainDrive(float moveVal, float rotVal)
{
	float leftMotorOut;
	float rightMotorOut;



	if(moveVal > 0.0)
	{

		moveVal = Drive::Limit(moveVal, 1.0) * mult;
		rotVal = Drive::Limit(rotVal, 1.0);


		if(rotVal > 0.0)
		{
			leftMotorOut = moveVal - rotVal;
			rightMotorOut = max(moveVal, rotVal);
		}

		else
		{
			leftMotorOut = max(moveVal, -rotVal);
			rightMotorOut = moveVal + rotVal;
		}
	}

	else
	{
		if(rotVal > 0.0)
		{
			leftMotorOut = - max(-moveVal, rotVal);
			rightMotorOut = moveVal + rotVal;
		}

		else
		{
			leftMotorOut = moveVal - rotVal;
			rightMotorOut = - max(-moveVal, -rotVal);
		}
	}
}

float Drive::Limit(float n, float max)
{
	if (n > max)
		{
			return max;
		}
		if (n < -max)
		{
			return -max;
		}
		return n;
}

Void Drive::InitDefCom()
{
	SetDefultCommand(new ArcadeDrive());
}

Drive::~Drive() {
	// TODO Auto-generated destructor stub
}

