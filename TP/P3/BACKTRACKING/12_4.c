/*Aplicația 12.4: Se dau urmatoarele 6 culori: alb, galben, rosu, verde, albastru si negru.
Costruiti toate steagurile formate din 3 culori care indeplinesc urmatoarele conditii:
- orice steag trebuie sa contina culoarea verde sau culoarea galben la mijloc.
- culorile din fiecare steag trebuie sa fie distincte.
*/
#include <stdio.h>
#include <stdlib.h>

int valid(int *sol, int poz) {
    for (int i = 0; i < poz; i++) {
        if (sol[i] == sol[poz])
            return 0; // Verifică dacă culorile sunt distincte
    }
    return 1;
}

int solutie(int *sol, int poz) {
    if (poz != 2)
        return 0; // Steagul trebuie să fie complet (poz = 2)

    // Verificăm dacă culoarea din mijloc este galben (1) sau verde (3)
    if (sol[1] != 1 && sol[1] != 3)
        return 0;

    return 1;
}

void afis(int *sol) {
    for (int i = 0; i < 3; i++) {
        switch (sol[i]) {
            case 0: printf("alb "); break;
            case 1: printf("galben "); break;
            case 2: printf("rosu "); break;
            case 3: printf("verde "); break;
            case 4: printf("albastru "); break;
            case 5: printf("negru "); break;
        }
    }
    printf("\n");
}

void back(int *sol, int poz) {
    for (int i = 0; i <= 5; i++) {
        sol[poz] = i;
        if (valid(sol, poz)) {
            if (solutie(sol, poz))
                afis(sol); // Afișează soluția dacă este completă și validă
            else
                back(sol, poz + 1); // Continuă recursiv pentru poziția următoare
        }
    }
}

int main() {
    int sol[3] = {0}; // Inițializăm vectorul cu 0 pentru a evita erori de memorie
    back(sol, 0); // Pornim backtracking-ul de la poziția 0

    return 0;
}
