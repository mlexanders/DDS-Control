#pragma once
#include <Controller.h>

class Dds
{
private:
	Controller *_controller;
	int _fClock = 1000; // TODO: ��������� ������� ������� � �� (1000 ��������� ��������)
public:
	Dds(Controller *controller);
	int init();
	void setFreq(unsigned long long freq);
	void setFi(unsigned int fi);
	void setA(unsigned int a);
};

