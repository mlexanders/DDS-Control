﻿#pragma once

class Command {
public:
	static const unsigned char NOP = 0b00000000;	//Нет операции, data игнорируется
	static const unsigned char SETA = 0b00010000;	//Запись addr в адресный регистр 
	static const unsigned char WR = 0b00100000;		//Запись data в регистр по адресу в адресном пространстве
	static const unsigned char WRI = 0b00100000;	//Запись addr в адресный регистр по адресу в адресном регистре с последующей инкрементацией адресного регистра 
	static const unsigned char SETAFT = 0b00100000;	//Запись addr в адресный регистр с выборкой значения регистра по адресу addr в сдвиговый регистр
};

