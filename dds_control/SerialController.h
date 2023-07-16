#pragma once
#include "Controller.h"
using Func = void (*)(bool);

class SerialController : public Controller
{
private:
	Func _writeBit;		// Ссылка на функцию, которая которая отправляет бит
	Func _chipSelect;	// Ссылка на функцию, которая активирует CS для отправки фрейма
	Func _clock;		// Ссылка на функцию, которая активирует clock
public:
	SerialController(void (*writeBit)(bool), void (*csSwitch)(bool), void (*clock)(bool));

	void write(Command cmd, unsigned short body);
	short read(Command cmd, unsigned short body);
};

