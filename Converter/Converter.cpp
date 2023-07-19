#include <iostream>
using namespace std;


const unsigned int m[] = { 0, 1, 2, 3, 40, 60, 80, 90, 100, 130, 150, 190, 201, 205, 260, 299, 301, 350, 370, 390, 399, 400, 410, 412, 433, 460, 490, 500, 600 };
unsigned long long a;
unsigned long long b;

void compute(int clock);
void oldCompute(unsigned long long clock);

void vs(unsigned int clock) {
    compute(clock);
    cout << endl;
    oldCompute((unsigned long long)clock);

    cout << "\t d ==> ";
    printf("%llu", a - b);
    cout << "\n----------" << endl;;
};


int main()
{
  /*  for (int i = 0; i < 29; i++)
    {
        vs(m[i]);
    }*/
    vs(300);
}

void compute(int clock) {
    static const unsigned long CONSTANT_VALUE = 0xFFFF0000;
    unsigned short result[3];
    unsigned long buffer = CONSTANT_VALUE * (clock / 1000.);

    result[0] = (buffer >> 16) & 0xFFFF;
    result[1] = (buffer | (buffer << 16)) >> 16 & 0xFFFF;
    result[2] = result[1] + 1;

    for (int i = 0; i < 3; i++) {
        cout << hex << result[i];
        a = (unsigned long long)result[0] << (16 * i);
    }
}

void oldCompute(unsigned long long clock) {


    double a = clock / 1000.;
    b = static_cast<unsigned long long>(a * (1ULL << 48));

    cout << hex << ((b >> (2 * 16)) & 0xFFFF);
    cout << hex << ((b >> (1 * 16)) & 0xFFFF);
    cout << hex << ((b >> (0 * 16)) & 0xFFFF);

}
