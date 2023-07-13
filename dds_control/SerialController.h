#pragma once
#include "BaseController.h"
using Func = void (*)(bool);

class SerialController : public BaseController
{
private:
	Func _writeBit; // Ссылка на функцию, которая которая отправляет бит
	void writeBit(bool byte);

	Func _chipSelect; // Ссылка на функцию, которая активирует CS для отправки фрейма
	void chipSelectSwitch(bool byte);
public:
	SerialController(void (*writeBit)(bool), void (*csSwitch)(bool));

	void write(Command cmd, unsigned short body);
	short read(Command cmd, unsigned short body);
};

