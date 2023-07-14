#pragma once

class Command {
private:
	unsigned char _cmd;
public:
	static const unsigned char NOP = 0b00000000;	//��� ��������, data ������������
	static const unsigned char SETA = 0b00010000;	//������ addr � �������� ������� 
	static const unsigned char WR = 0b00100000;		//������ data � ������� �� ������� � �������� �������������
	static const unsigned char WRI = 0b00100000;	//������ addr � �������� ������� �� ������ � �������� �������� � ����������� �������������� ��������� �������� 
	static const unsigned char SETAFT = 0b00100000;	//������ addr � �������� ������� � �������� �������� �������� �� ������ addr � ��������� �������

	Command(const unsigned char cmd);

	unsigned char getByte(int i);
};

