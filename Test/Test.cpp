#include <iostream>
#include <SerialController.h>
#include <Addresses.h>
#include <Tst.h>

using namespace std;



void write(bool bit) {
    if (bit)
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
}

void csSwitch(bool bit) {
    cout << "CS";
}

SerialController* sc = new SerialController(&write, &csSwitch);
void (*ptr)(bool) = &write;

int main()
{
    Command cmd = Command::NOP;
    short body = Addresses::CH1_dPh0_H;

    sc->write(cmd, body);

    Tst *t = new Tst(1);
}
