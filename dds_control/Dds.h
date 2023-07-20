#pragma once
#include <Controller.h>

class Dds
{
private:
	Controller *_controller;
	double _baseClock = 1000.0;	//Опорная частота			TODO: получение опорной частоты с МК (1000 примерное значение)
	int _currentProfile = 0;	//Текущий профиль			TODO: настройка рабочих профилей (0 - по умолчанию) : 0 - 63
	int _currentChannel = 1;	//Текущий канал				TODO: выбор канала (1 - по умолчанию) : 1 или 2
	static const unsigned long CONSTANT_VALUE = 0xFFFF0000;
public:
	Dds(Controller *controller);
	~Dds();
	int init();	//Включение ЦАП, установка рабочего профиля и канала;
	void setFreq(unsigned int clock);	// Установка частоты
	void setFi(unsigned short fi);			//Установка фазы fi
	void setA(unsigned short a);			//Установка амплитуды
};

