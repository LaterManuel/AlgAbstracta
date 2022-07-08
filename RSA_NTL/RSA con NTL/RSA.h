#include <iostream>
#include "Funciones.h"

using namespace std;

class RSA {
private:
    ZZ d;
    ZZ p;
    ZZ q;
    ZZ oN;
    //string alfabeto = "abcdefghijklmnopqrstuvwxyz ";

public:
    ZZ e;
    ZZ N;
    ZZ message;
    ZZ encrypted_letter;

    RSA(int);

    RSA(ZZ, ZZ);

    void chiper(ZZ);        //convierte cada letra del mensaje en (su posicion^e)mod N

    void dechiper(ZZ); //convierte cada numero del vector en (numero^d)mod N

    void show_encryption();     //imprime cada valor del vector encrypted_letter de quien cifro el mensaje

    void show_decryption();     //imprime el string de quien decifro el mensaje cifrado
};

