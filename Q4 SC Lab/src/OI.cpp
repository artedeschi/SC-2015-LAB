#include "OI.h"
#include "Commandbase.h"
#include "Commands/Forward"
#include "Commands/Reverse"

OI::OI() : driveStick(new Joystick(DRIVE))
{
	Button* driveTrigger = new JoystickButton(driveStick, 1);
	driveTrigger->WhenPressed(new Reverse());
	driveTrigger->WhenReleased(new Forward());
	// Process operator interface input here.
}

Joystick* OI::getDriveStick()
{
	return driveStick;
}
