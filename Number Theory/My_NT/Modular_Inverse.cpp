// calculate a^n % M
int modExp(int a, int n, int M) {
    int res = 1;
     a %= M;
    while (n > 0) {
        if (n & 1) res = (res * a) % M;
        a = (a * a) % M;
        n >>= 1;
    }
    return res;
}
//Modular multiplicative inverse
// Using Fermat's Little Theorem: a^(M-1) ≡ 1 (mod M)
// a^(M-2) ≡ a^(-1) (mod M)
// Therefore a^-1 ≡ a^(M-2) (mod M)
 int modInverse(int a, int M) {
    return modExp(a, M - 2, M);
}