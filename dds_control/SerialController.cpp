#include "SerialController.h"
#include "Command.h"

SerialController::SerialController(void (*writeBit)(bool), void (*csSwitch)(bool))
{
	_writeBit = writeBit;
	_chipSelect = csSwitch;
}

void SerialController::writeBit(bool bit)
{
	_writeBit(bit);
}

void SerialController::chipSelectSwitch(bool isActive)
{
	_chipSelect(isActive);
}

void SerialController::write(Command cmd, unsigned short body)
{
	chipSelectSwitch(true);
	for (int i = 7; i >= 0; i--)
	{
		_writeBit(cmd.getByte(i));
	}
	for (int i = 15; i >= 0; i--)
	{
		_writeBit(cmd.getByte(i));
	}
	chipSelectSwitch(false);
}

short SerialController::read(Command cmd, unsigned short body)
{
	return 0; //TODO: NOT IMPLEMENTATION. Check the returns value
}
