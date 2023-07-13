#include "DdsBuilder.h"
#include <SerialController.h>

DdsBuilder::DdsBuilder(BaseController* controller)
{
    _controller = controller;
}

DdsBuilder DdsBuilder::useSerialController(void (*writeBit)(bool), void (*csSwitch)(bool))
{
    return DdsBuilder(new SerialController(writeBit, csSwitch));
}

Dds DdsBuilder::getDds()
{
    return Dds();
}
