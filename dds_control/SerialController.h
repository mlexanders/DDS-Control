#pragma once
#include "BaseController.h"
using Func = void (*)(bool);

class SerialController : public BaseController
{
private:
	Func _writeBytePtr; // ������ �� �������, ������� ������� ���������� ���
	void writeByte(bool byte);

	Func _chipSelectPtr; // ������ �� �������, ������� ���������� CS ��� �������� ������
	void chipSelectSwitch(bool byte);
public:
	SerialController(void (*writeByte)(bool), void (*csSwitch)(bool));

	void write(Command cmd, unsigned short body);
	short read(Command cmd, unsigned short body);
};

