#pragma once

class Command {
private:
	unsigned char _cmd;
public:
	static const unsigned char NOP = 0b00000000;		//Ќет операции. «начение data игнорируетс€.
	static const unsigned char SETA = 0b00010000;	//«апись addr в адресный регистр. 
	static const unsigned char WR = 0b00100000;		//«апись addr в адресный регистр. 
	static const unsigned char WRI = 0b00100000;		//«апись data в регистр по адресу в адресном регистре с последующей инкрементацией адресного регистра
	static const unsigned char SETAFT = 0b00100000;	//«апись addr в адресный регистр c выборкой значени€ регистра по адресу addr в сдвиговый регистр.

	Command(const unsigned char cmd);

	unsigned char getByte(int i);
};

