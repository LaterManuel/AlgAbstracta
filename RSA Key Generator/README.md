Implementacion del RSA_KEU_GENERATOR

  1. Generar dos primos p y q, tal que p != q
      
      La generacion de primos se realiza en el constructor del objeto (RSA::RSA(int bits)), donde recibe un numero de bits y el numero que genereara se encuentra entre ese rango.
    
  2. n = p · q

     Realizado en la linea 16 de "RSA.cpp"
      
  3. φ(n) = (p − 1)(q − 1)
  
      Realizado en la linea 15 de "RSA.cpp"
  
  4. Generar aleatoriamente e ∈ [2, n − 1], tal que gcd(e, φ(n)) = 1

     Realizado en la linea 18 de "RSA.cpp"
  
  5. d = INVERSE(e, φ(n))

     Realizado en la linea 21 de "RSA.cpp"
      
  6. return {n, e, d}
    
    * Cifrar usando P(m) = m^e mod n = c.
    
      Realizado en la linea 34 de "RSA.cpp"
      
    * Descifrar usando S(c) = c^d mod n = m.
    
      Realizado en la linea 42 de "RSA.cpp"
