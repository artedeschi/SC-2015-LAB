#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick* driveStick;

public:
	OI();
	Joystick* getDriveStick();
};

#endif
