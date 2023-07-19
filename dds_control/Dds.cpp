#include "Dds.h"
#include "Addresses.h"
#include <math.h>

Dds::Dds(Controller *controller)
{
    _controller = controller;
}

int Dds::init()
{   
    _controller->write(Command::SETA, Addresses::SEL_REG);
    _controller->write(Command::WR, _currentProfile);   //Выбор активного профиля синтеза
    
    _controller->write(Command::SETA, Addresses::CLR);
    _controller->write(Command::WR, 0x000F);
    
    _controller->write(Command::SETA, Addresses::CTR); 
    _controller->write(Command::WR, 0b0001000000000000); //Включение ЦАП-1 

    return 0;
}

/*------------------------------------------------------------
freq = 0x 0000 4CCC CCCC CCCD => size: 64bit / 8 byte

    => Ch x _dPh y _L   =   0xCCCD      - [ 0; 15] bits - 0th 
    => Ch x _dPh y _M   =   0xCCCC,     - [16; 31] bits - 1th 
    => Ch x _dPh y _H   =   0x4CCC,     - [32; 47] bits - 2th 
    * USES ONLY 48 bit [0; 47]
--------------------------------------------------------------*/
void Dds::setFreq(unsigned int clock) // Установка частоты [МГц]
{ 
    unsigned short result[3]{};
    unsigned long buffer = CONSTANT_VALUE * (clock / _baseClock);

    result[2] = (buffer >> 16) & 0xFFFF;
    result[1] = (buffer | (buffer << 16)) >> 16 & 0xFFFF;
    result[0] = result[1] + 1;

    _controller->write(Command::SETA, Addresses::CH1_dPh0_L);
    _controller->write(Command::WR, result[0]); 

    _controller->write(Command::SETA, Addresses::CH1_dPh0_M);
    _controller->write(Command::WR, result[1]);

    _controller->write(Command::SETA, Addresses::CH1_dPh0_H);
    _controller->write(Command::WR, result[2]);
}


void Dds::setFi(unsigned short fi)     // Установка фазы   [°]
{
    _controller->write(Command::SETA, Addresses::CH1_Offset0);
    _controller->write(Command::WR, fi);
}


void Dds::setA(unsigned short a)       // Установка амплитуды [дБ]
{
    _controller->write(Command::SETA, Addresses::CH1_Mul0);
    _controller->write(Command::WR, a );   // A = mul / 2^12
}
