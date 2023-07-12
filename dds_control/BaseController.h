#pragma once
#include "Command.h"

class BaseController
{
public:
	void virtual write(Command cmd, unsigned short body);
	short virtual read(Command cmd, unsigned short body);
};

