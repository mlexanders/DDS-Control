#pragma once
#include "Command.h"

class Controller
{
public:
	void virtual write(const unsigned char cmd, unsigned short body);
	short virtual read(const unsigned char cmd, unsigned short body);
};

