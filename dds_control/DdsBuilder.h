#pragma once
#include <Dds.h>
#include <BaseController.h>

class DdsBuilder
{
private:
	BaseController *_controller;
	DdsBuilder(BaseController *controller);
public:
	static DdsBuilder useSerialController(void (*writeBit)(bool), void (*csSwitch)(bool));
	Dds getDds();
};

