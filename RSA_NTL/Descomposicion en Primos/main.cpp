#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <NTL/ZZ.h>

using namespace NTL;
using namespace std;

ZZ module(ZZ a, ZZ n) {
    ZZ r = a - n * (a / n);
    r = r + (r < 0) * n;
    return r;
}

int main()
{
    ZZ num = conv<ZZ>("35794234179725868774991807832568455403003778024228226193532908190484670252364677411513516111204504060317568667");
    cout<<num<<" = ";
    ZZ uno = conv<ZZ>("1");
    for(ZZ i = conv<ZZ>("2"); num > 1; i+=uno){
        while (module(num, i) == 0){
            cout<<" * "<<i;
            num /= i;
        }
    }

    return 0;
}
