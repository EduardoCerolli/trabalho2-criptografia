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

int main () {
    int e = 13, n = 473;
    int p, q, totiente, d;

    fatoraN(n, &p, &q);

    totiente = (p - 1) * (q - 1);

    d = inversoMod(e, totiente);

    printf("%d %d\n", p, q);
    printf("%d\n", d);

    return 0;
}