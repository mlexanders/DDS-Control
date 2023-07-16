#include "Command.h"

Command::Command(const unsigned char cmd) {
	_cmd = cmd;
}

unsigned char Command::getBit(int i) {
	return (_cmd >> i) & 1;
}