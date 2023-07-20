#include "SerialController.h"
#include "Command.h"

SerialController::SerialController(void (*writeBit)(bool), void (*chipSelect)(bool), void (*clock)(bool))
{
	_writeBit = writeBit;
	_chipSelect = chipSelect;
	_clock = clock;
	_chipSelect(false);
}

void SerialController::write(const unsigned char cmd, unsigned short body)
{
	_chipSelect(false);
	for (int i = 7; i >= 0; i--)
	{
		_clock(false);
		_writeBit((cmd>> i) & 1);
		_clock(true);
	}
	for (int i = 15; i >= 0; i--)
	{
		_clock(false);
		_writeBit((body >> i) & 1);
		_clock(true);
	}
	_chipSelect(true);
}

short SerialController::read(const unsigned char cmd, unsigned short body)
{
	return 0;
}


