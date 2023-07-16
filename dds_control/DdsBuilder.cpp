#include "DdsBuilder.h"
#include <Controller.h>
#include <SerialController.h>

DdsBuilder::DdsBuilder(Controller* controller)
{
    _controller = controller;
}

DdsBuilder DdsBuilder::useSerialController(void (*writeBit)(bool), void (*chipSelect)(bool), void (*clock)(bool))
{
    return DdsBuilder(new SerialController(writeBit, chipSelect, clock));
}

Dds DdsBuilder::getDds()
{
    return Dds(_controller);
}
