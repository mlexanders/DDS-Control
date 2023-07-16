#include <iostream>
#include <DdsBuilder.h>
using namespace std;

int i = 0;
bool j = 1;

void write(bool bit);   //SDI
void chipSelect(bool isActive); //SCSn
void clock(bool isActive);  //SCK

Dds dds = DdsBuilder::useSerialController(&write, &chipSelect, &clock).getDds();

int main()
{
	dds.setFreq(300);
}


void write(bool bit) {
    cout << i << ":" << bit;
    i++;
}

void chipSelect(bool isActive) {
    cout << "CS\t" << isActive << "\n";
    i = 0;
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