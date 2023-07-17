#pragma once
#include <Controller.h>

class Dds
{
private:
	Controller *_controller;
	int _fClock = 1000;			//Опорная частота			TODO: получение опорной частоты с МК (1000 примерное значение)
	int _currentProfile = 0;	//Текущий профиль			TODO: настройка рабочих профилей (0 - по умолчанию) : 0 - 63
	int _currentChannel = 1;	//Текущий канал				TODO: выбор канала (1 - по умолчанию) : 1 или 2
	static const unsigned long long _k = 28147497671065;		//коэффициент => 2^48
public:
	Dds(Controller *controller);
	int init();	//Включение ЦАП, установка рабочего профиля и канала;
	void setFreq(unsigned long long freq);	// Установка частоты
	void setFi(unsigned int fi);			//Установка фазы fi
	void setA(unsigned short a);			//Установка амплитуды
};

