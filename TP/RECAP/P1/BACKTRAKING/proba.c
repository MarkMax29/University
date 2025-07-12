#include <stdio.h>
#include <stdlib.h>

int valid(int v[], int k) {
    if (k == 0 && v[k] == 0) {
        return 0; // Prima cifră nu poate fi zero.
    }
    return 1;
}

int solutie(int v[], int c, int k, int n) {
    int unu = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 1) {
            unu++;
        }
    }
    return (unu == c);
}

void afisare(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
    }
    printf("\n");
}

void back(int v[], int k, int c, int n) {
    if (k == n) {
        if (solutie(v, c, k, n)) {
            afisare(v, n);
        }
        return;
    }

    for (int i = 0; i <= 9; i++) {
        v[k] = i;
        if (valid(v, k)) {
            back(v, k + 1, c, n);
        }
    }
}

int main() {
    int n, c;
    printf("Introduceti n si k: ");
    scanf("%d %d", &n, &c);

    if (c > n) {
        printf("Nu este posibil să ai mai multe cifre de 1 decât numărul total de cifre.\n");
        return -1;
    }

    int v[n];
    back(v, 0, c, n);

    return 0;
}
