#include "Dds.h"
#include "Addresses.h"
#include <math.h>

Dds::Dds(Controller *controller)
{
    _controller = controller;
}

int Dds::init()
{
    return 0;   //TODO: NOT IMPLEMENTATION.
}

/*------------------------------------------------------------
freq = 0x 0000 4CCC CCCC CCCD => size: 64bit / 8 byte

    => Ch x _dPh y _L   =   0xCCCD      - [ 0; 15] bits - 0th 
    => Ch x _dPh y _M   =   0xCCCC,     - [16; 31] bits - 1th 
    => Ch x _dPh y _H   =   0x4CCC,     - [32; 47] bits - 2th 
    * USES ONLY 48 bit [0; 47]
--------------------------------------------------------------*/
void Dds::setFreq(unsigned long long freq) // ”становка частоты [ћ√ц]
{ 
    double cl = static_cast<double>(freq * 0x1000000000000) / _fClock;
    freq = (unsigned long long)cl;

    _controller->write(Command::SETA, Addresses::CH1_dPh0_L);
    _controller->write(Command::WR, (freq >> (0 * 16)) & 0xFFFF); // (побитовый сдвиг на i * 16 бит) & (11111111 11111111)

    _controller->write(Command::SETA, Addresses::CH1_dPh0_M);
    _controller->write(Command::WR, (freq >> (1 * 16)) & 0xFFFF);

    _controller->write(Command::SETA, Addresses::CH1_dPh0_H);
    _controller->write(Command::WR, (freq >> (2 * 16)) & 0xFFFF);
}


void Dds::setFi(unsigned int fi)     // ”становка фазы   [∞]
{
    //TODO: NOT IMPLEMENTATION. //
}


void Dds::setA(unsigned int a)       // ”становка амплитуды [дЅ]
{
    //TODO: NOT IMPLEMENTATION. // use Mul
}
