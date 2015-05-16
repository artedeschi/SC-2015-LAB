/*
 * Drive.h
 *
 *  Created on: May 9, 2015
 *      Author: Adam
 */

#ifndef SRC_SUBSYSTEMS_DRIVE_H_
#define SRC_SUBSYSTEMS_DRIVE_H_

#include "Commands/Subsystem.h"

class Drive: public Subsystem
{
private:
	Talon* left;
	Talon* right;
	float d;

public:
	Drive();
	void setMoveConst(float m);
	void mainDrive(float move, float rot);
	float Limit(float n, float max);
	void SetDefCom();
	virtual ~Drive();

};

#endif /* SRC_SUBSYSTEMS_DRIVE_H_ */
