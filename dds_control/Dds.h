#pragma once
#include <Controller.h>

class Dds
{
private:
	Controller *_controller;
	int _fClock = 1000; // TODO: получение опорной частоты с МК (1000 примерное значение)
public:
	Dds(Controller *controller);
	int init();
	void setFreq(unsigned long long freq);
	void setFi(unsigned int fi);
	void setA(unsigned int a);
};

