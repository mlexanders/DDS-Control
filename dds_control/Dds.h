#pragma once
#include <Controller.h>

class Dds
{
private:
	Controller *_controller;
	int _fClock = 1000; // TODO: ��������� ������� ������� � �� (1000 ��������� ��������)
	int _currentProfile = 0; // TODO: ��������� ������� �������� (0 - �� ���������) : 0 - 63
	int _currentChannel = 1; // TODO: ����� ������ (1 - �� ���������) : 1 ��� 2
public:
	Dds(Controller *controller);
	int init();
	void setFreq(unsigned long long freq);
	void setFi(unsigned int fi);
	void setA(unsigned short a);
};

