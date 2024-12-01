#include <stdlib.h>
#include <stdio.h>

int potencia (int base, int expoente, int mod) {
    int res = base;
    
    for (int i = 0; i < expoente - 1; i++) {
        res = (res * base) % mod;
    }

    return res;
}

int main() {
    int p, q, n, e;
    int dado, cifra;

    printf("Informe o valor de p: ");
    scanf("%d", &p);

    printf("Informe o valor de q: ");
    scanf("%d", &q);

    n = p * q;
    printf("N: %d\n", n);
    
    printf("Informe o valor de e: ");
    scanf("%d", &e);

    printf("Informe o valor a ser cifrado: ");
    scanf("%d", &dado);

    if (dado > 1 && dado < n - 1) {
        cifra = potencia(dado, e, n);
        printf ("Valor cifrado: %d\n", cifra);
    }
    else {
        printf ("Valor para cifra inválido\n");
    }

    return 0;
}
