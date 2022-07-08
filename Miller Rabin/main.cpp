#include <iostream>
#include <NTL/ZZ.h>
#include <math.h>

using namespace std;
using namespace NTL;

ZZ module(ZZ a, ZZ n){
	ZZ r = a-n*(a/n);
	r = r+(r<0)*n;
	return r;
}

ZZ modPow(ZZ a ,ZZ n,ZZ m){

	ZZ exp (1);
	ZZ x = module(a,m);

	while(n>0){
		if(module(n, ZZ(2)) == 1)
			exp = module(exp*x,m);
		x = module(x*x,m);
		n>>=1;
	}
	return exp;
}

ZZ RandomNumber(ZZ init,ZZ end) {
	ZZ k = end - init + 1;
	ZZ num = RandomBnd(k)+init;
	return num;
}

bool millerRabinTest(ZZ number, ZZ iter)
{
	// Casos Base
	if(module(number,ZZ(2))== 0) return false;
	if (number <= 1 || number == 4)  return false;
	if (number <= 3) return true;

	// number-1 = 2^d * r ; r >= 1
	ZZ d = number - 1;

	//Hallar  el exponente d
	while (module(d,ZZ(2)) == 0)
		d >>= 1;


	// Iterar
	for (ZZ i (0); i < iter; i++){

		// obtener un numero random en [2..n-2]
		ZZ a = RandomNumber(ZZ(2),number-2);

		// X =  a^d mod( n)
		ZZ x = modPow(a, d, number);

		if (x == 1  || x == number-1)
			return true;

		while (d != number-1)
		{
			x= module(x*x,number);
			//x= x*x % n;
			d <<=1;

			if (x == 1)   return false;
			if (x == number-1)  return true;
		}
		return false;
	}

	return true;
}

int main() {
    cout<<"Primos del 100 al 10000: "<<endl;
    for(ZZ num = ZZ(100); num < ZZ(10000); num += ZZ(1)){
        if (millerRabinTest(num,ZZ(1000))){
            cout<<num<< ", ";
        }
        else{
            //cout<<num<< " not prime "<<endl;
        }
    }
    int cont=1;
    cout<<endl;
    cout<<"Numeros de 16 bits"<<endl;
    for(ZZ num = ZZ(65536); cont<=10; num += ZZ(1)){
        if (millerRabinTest(num,ZZ(1000))){
            cout<<num<< ", ";
            cont++;
        }
        else{
            //cout<<num<< " not prime "<<endl;
        }
    }
    cout<<endl;
    ZZ x = conv<ZZ>("4294967296");
    cont=1;
    cout<<"Numeros de 32 bits"<<endl;
    for(ZZ num = x; cont<=10; num += ZZ(1)){
        if (millerRabinTest(num,ZZ(1000))){
            cout<<num<< ", ";
            cont++;
        }
        else{
            //cout<<num<< " not prime "<<endl;
        }
    }
    cout<<endl;
    ZZ y = conv<ZZ>("18446744073709551616");
    cont=1;
    cout<<"Numeros de 64 bits"<<endl;
    for(ZZ num = y; cont<=10; num += ZZ(1)){
        if (millerRabinTest(num,ZZ(1000))){
            cout<<num<< ", ";
            cont++;
        }
        else{
            //cout<<num<< " not prime "<<endl;
        }
    }
}

