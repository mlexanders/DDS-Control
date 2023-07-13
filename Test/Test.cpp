#include <iostream>
#include <SerialController.h>
#include <Addresses.h>
using namespace std;

int i = 0;

void write(bool bit) {
    cout << i << ":";
    if (bit)
    {
        cout << "1\n";
    }
    else
    {
        cout << "0\n";
    }
    i++;
}

void csSwitch(bool bit) {
    cout << "CS" << bit << "\n";
}

SerialController* sc = new SerialController(&write, &csSwitch);

int main()
{
    Command cmd = Command::SETA;
    short body = Addresses::SWRST;

    sc->write(cmd, body);
}
