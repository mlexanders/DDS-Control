#include <iostream>
#include <DdsBuilder.h>
using namespace std;

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

int i = 0;
bool j = 1;

void write(bool bit);   //SDI
void chipSelect(bool isActive); //SCSn
void clock(bool isActive);  //SCK

Dds *dds = DdsBuilder::useSerialController(&write, &chipSelect, &clock).getDds();

int main()
{
    _CrtMemState s1;
    _CrtMemCheckpoint(&s1);

    if (dds->init() == 1) return 1;

    dds->setFreq(300);
    dds->setFreq(2);
    dds->setFreq(1);
    dds->setA(1);
    dds->setFi(5);

   
    _CrtDumpMemoryLeaks();
    return 0;
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