#include "Command.h"

Command::Command(const unsigned char cmd) {
	_cmd = cmd;
}

unsigned char Command::getByte(int i) {
	return (_cmd >> i) & 1;
}