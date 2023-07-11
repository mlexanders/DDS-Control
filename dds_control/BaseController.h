#pragma once
#include "Command.h"

namespace DdsControl {
	class BaseController
	{
	public:
		void virtual write(Command cmd, unsigned short body);
		short virtual read(Command cmd, unsigned short body);
	};
};

