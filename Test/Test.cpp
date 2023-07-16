#include <iostream>
#include <SerialController.h>
#include <Addresses.h>
#include <DdsBuilder.h>
using namespace std;


int i = 0;
bool j = true;

void write(bool bit);
void chipSelect(bool isActive);
void clock(bool isActive);

SerialController* controller = new SerialController(&write, &chipSelect, &clock);


int main() {
    Dds dds = DdsBuilder::useSerialController(&write, &chipSelect, &clock).getDds();

    Command cmd = Command::SETA;
    short body = Addresses::SWRST;

    controller->write(cmd, body);
}


void write(bool bit) {
    cout << i << ":" << bit;
    i++;
}

void chipSelect(bool isActive) {
    cout << "CS\t" << isActive << "\n";
}

void clock(bool isActive) {
    if (j)
    {
        cout << "clock" << isActive << "\t";
    }
    else
    {
        cout << "\tclock" << isActive << "\n";
    }
    j = !j;
}
