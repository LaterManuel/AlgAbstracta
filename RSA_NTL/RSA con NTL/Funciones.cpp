#include "Funciones.h"

ZZ module(ZZ a, ZZ n) {
    ZZ r = a - n * (a / n);
    r = r + (r < 0) * n;
    return r;
}

ZZ recursive_Euclid(ZZ a, ZZ b){
    if (module(a, b) == ZZ(0)){
        return b;
    }
    else   {
        ZZ temp = b;
        b = module(a, b);
        a = temp;
        recursive_Euclid(a,b);
    }
}

ZZ Euclid(ZZ a, ZZ b){
    while (module(a, b) != 0){
        ZZ temp = b;
        b = module(a, b);
        a = temp;
    }
    return b;
}

ZZ mcd(ZZ a, ZZ b){
    return Euclid(a, b);
}

void Euclid_extended(ZZ a, ZZ b, ZZ &x, ZZ &y) {
    x = ZZ(1), y = ZZ(0);

    ZZ x1(0), y1(1), a1(a), b1(b);
    while (b1 != 0) {
        ZZ q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
}

ZZ inverse(ZZ a, ZZ n) {
    ZZ x, y;
    Euclid_extended(a, n, x, y);
    return module(x, n);
}

ZZ modular_exponentiation(ZZ base, ZZ exponent, ZZ mod){
    ZZ dos = conv<ZZ>("2");
    ZZ reply = base;
    exponent/=dos;
    while (exponent != ZZ(0)){
        base = module(base*base, mod);
        if (module(exponent, ZZ(2)) != ZZ(0)){
            reply = module(reply*base, mod);
        }
        exponent/=dos;
    }
    return reply;
}



vector<int> criba_eratostenes(int limit)
{
    vector<int> criba;
    int prime_found;  // primos que se vayan encontrando

    // llenando el vector desde 2 hasta limit
    for (int i = 2; i <= limit; i++)
        criba.push_back(i);

    if (limit == 2 || limit == 3)
        return criba;

    // iteradores para la seleccion
    vector<int>::iterator it = criba.begin();
    vector<int>::iterator it2;
    prime_found = *it;  // El primer primo es 2

    while (prime_found*prime_found < limit)
    {
        it2 = it + 1;

        for(; it2 <= criba.end(); it2++) //Borra multiplos de los primos hallados
            if(*it2 % prime_found == 0)
                criba.erase(it2);
        it++;
        prime_found = *it;
    }

    return criba;
}


vector <int> prime_bits(int bit){ //devuelve los elementos primos segun el numero de bits que pide
    vector <int> primos = criba_eratostenes(pow(2, bit)-1);
    vector<int>::iterator it = primos.begin();
    while (*it < pow(2, bit)/2){
        primos.erase(it);
    }
    return primos;
}

