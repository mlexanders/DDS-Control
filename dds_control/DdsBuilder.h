#pragma once
#include <Dds.h>
#include <Controller.h>

class DdsBuilder
{
private:
	Controller *_controller;
	DdsBuilder(Controller *controller);
public:
	static DdsBuilder useSerialController(void (*writeBit)(bool), void (*chipSelect)(bool), void (*clock)(bool));
	Dds getDds();
};

