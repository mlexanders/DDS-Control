#include "SerialController.h"
#include "Command.h"

SerialController::SerialController(void (*writeByte)(bool), void (*csSwitch)(bool))
{
	_writeBytePtr = writeByte;
	_chipSelectPtr = csSwitch;
}

void SerialController::writeByte(bool bit)
{
	_writeBytePtr(bit);
}

void SerialController::chipSelectSwitch(bool isActive)
{
	_chipSelectPtr(!isActive); // CS активируется при 0, для удобства инверсируем isActive
}

void SerialController::write(Command cmd, unsigned short body)
{
	char _cmd = static_cast<char>(cmd);

	for (int i = 8; i > 0; i--)
	{
		writeByte((_cmd >> i) & 1);
	}
	for (int i = 16; i > 0; i--)
	{
		writeByte((body >> i) & 1);
	}
}

short SerialController::read(Command cmd, unsigned short body)
{
	return 0; //TODO: check the returns value
}
