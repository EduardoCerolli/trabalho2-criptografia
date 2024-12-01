#include <stdlib.h>
#include <stdio.h>

int primo (int n) {
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int proximoPrimo (int n) {
    while (1) {
        n++;
        if (primo(n))
            return n;
    }
}

void fatoraN (int n, int *p, int *q) {
    int a = 1, b;

    while (a < 1024) {
        a = proximoPrimo(a);
        b = 1;
        while (b < 1024) {
            b = proximoPrimo(b);
            if ((a * b) == n) {
                *p = a;
                *q = b;
                
                return;
            }
        }
    }

    return;
}

int inversoMod (int e, int totiente) {
    int i = 1, d = 0, div;
    
    while (d == 0) {
        div = ((totiente * i) + 1); 
        if ((div % e) == 0)
            d = div / e;

        i++;
    }
    
    return d;
}

int potencia (int base, int expoente, int mod) {
    int res = base;
    
    for (int i = 0; i < expoente - 1; i++) {
        res = (res * base) % mod;
    }

    return res;
}

int main () {
    int e, n;
    int p, q, totiente, d;
    int dado, decifra;

    printf("Informe o valor de e: ");
    scanf("%d", &e);

    printf("Informe o valor de n: ");
    scanf("%d", &n);

    fatoraN(n, &p, &q);

    totiente = (p - 1) * (q - 1);

    d = inversoMod(e, totiente);

    printf("Informe o valor a ser decifrado: ");
    scanf("%d", &dado);

    decifra = potencia(dado, d, n);

    printf("P e Q: %d %d\n", p, q);
    printf("D: %d\n", d);
    printf("Dado decifrado: %d\n", decifra);

    return 0;
}