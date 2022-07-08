#include "RSA.h"

RSA::RSA(int bits) {
    vector<int> random_prime = prime_bits(bits); //genera los primos entre (bits^2)/2 y (bits^2)-1


    p = random_prime[module(random(123, 123 + random_prime.size()), random_prime.size() - 1)];
    //p = 3;
    //q = 11;
    q = random_prime[module(random(321, 321 + random_prime.size()), random_prime.size() - 1)];
    e = random_prime[random(0, random_prime.size() - 1)];

    N = p * q;
    oN = (p-1)*(q-1);
    while (mcd(e, oN) != 1) { //si el mcd(e, oN) != 1, busco otro primo tal que mcd(e, oN) == 1
        e = random_prime[random(0, random_prime.size() - 1)];
    }
    d = inverse(e, oN);
    cout << "El valor de \"p\" es: " << p << endl;
    cout << "El valor de \"q\" es: " << q << endl;
    cout << "El valor de \"e\" es: " << e << endl;
    cout << "El valor de \"d\" es: " << d << endl;
    cout << "El valor de \"N\" es: " << N << endl;
}

RSA::RSA(int a, int b) {
    e = a;
    N = b;
}

void RSA::chiper(int mssg) {
    encrypted_letter = modular_exponentiation(mssg, e, N);
}

void RSA::dechiper(int letters) {
    message = modular_exponentiation(letters, d, N);
}

void RSA::show_encryption() {
    cout << endl << "Mensaje cifrado: ";
    cout << encrypted_letter;

}

void RSA::show_decryption() {
    cout << endl << "Mensaje decifrado: "<<message;
}
