#pragma once
#include <Dds.h>
#include <Controller.h>
#include <SerialController.h>

class DdsBuilder
{
private:
	Dds* _dds;
	DdsBuilder(Controller* controller);
public:
	static DdsBuilder useSerialController(void (*writeBit)(bool), void (*chipSelect)(bool), void (*clock)(bool));
	Dds* getDds();
};

