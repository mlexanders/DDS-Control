#include "SerialController.h"
#include "Command.h"

SerialController::SerialController(void (*writeBit)(bool), void (*chipSelect)(bool), void (*clock)(bool))
{
	_writeBit = writeBit;
	_chipSelect = chipSelect;
	_clock = clock;
}

void SerialController::write(Command cmd, unsigned short body)
{
	_chipSelect(true);
	for (int i = 7; i >= 0; i--)
	{
		_clock(true);
		_writeBit(cmd.getBit(i));
		_clock(false);
	}
	for (int i = 15; i >= 0; i--)
	{
		_clock(true);
		_writeBit((body >> i) & 1); 	// TODO: change to getBit
		_clock(false);
	}
	_chipSelect(false);
}

short SerialController::read(Command cmd, unsigned short body)
{
	return 0; //TODO: NOT IMPLEMENTATION. Check the returns value
}
