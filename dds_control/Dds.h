#pragma once
#include <Controller.h>

class Dds
{
private:
	Controller *_controller;
	int _fClock = 1000; // TODO: получение опорной частоты с МК (1000 примерное значение)
	int _currentProfile = 0; // TODO: настройка рабочих профилей (0 - по умолчанию) : 0 - 63
	int _currentChannel = 1; // TODO: выбор канала (1 - по умолчанию) : 1 или 2
public:
	Dds(Controller *controller);
	int init();
	void setFreq(unsigned long long freq);
	void setFi(unsigned int fi);
	void setA(unsigned short a);
};

