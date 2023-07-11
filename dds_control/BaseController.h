#pragma once
#include "Comands.h"

namespace DdsControl {
	class BaseController
	{
	public:
		void virtual write(Command cmd, unsigned short body);
		short virtual read(Command cmd, unsigned short body);
	};
};

