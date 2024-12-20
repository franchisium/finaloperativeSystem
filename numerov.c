#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000         
#define X_MIN -10.0   
#define X_MAX 10.0    
#define H ((X_MAX - X_MIN) / N)  
#define M 1.0          // masa
#define HBAR 1.0       // C en planck
#define OMEGA 1.0      // Fr angular

// Potencial del oscilador armónico
double V(double x) {
    return 0.5 * M * OMEGA * OMEGA * x * x;
}

// Aplicar numerov en base a la ec de schrodinger
void numerov(double psi[], double E) {
    double k_prev, k_curr, k_next;
    double x;
    //restriccion para evitar constantes
    psi[0] = 1e-5;
    psi[1] = 1e-5 * (1 + H);

    for (int i = 1; i < N - 1; i++) {
        x = X_MIN + i * H;

        k_prev = fmax(0.0, 2 * M * (E - V(x - H)) / (HBAR * HBAR));
        k_curr = fmax(0.0, 2 * M * (E - V(x)) / (HBAR * HBAR));
        k_next = fmax(0.0, 2 * M * (E - V(x + H)) / (HBAR * HBAR));

        psi[i + 1] = (2 * (1 - 5 * H * H * k_curr / 12) * psi[i] -
                      (1 + H * H * k_prev / 12) * psi[i - 1]) /
                     (1 + H * H * k_next / 12);
    }
}

// Normalización de la función de onda
void normalize(double psi[]) {
    double norm = 0.0;

    for (int i = 0; i < N; i++) {
        norm += psi[i] * psi[i] * H;
    }

    norm = sqrt(norm);

    if (norm == 0) {
        printf("Error: la función de onda no puede normalizarse\n");
        exit(1);
    }

    for (int i = 0; i < N; i++) {
        psi[i] /= norm;
    }
}

int main() {
    double psi[N];
    double energies[] = {0.5, 1.5, 2.5, 3.5}; //valores de energias (para 4 estados)
    int num_states = sizeof(energies) / sizeof(energies[0]);

    FILE *file = fopen("resultados.txt", "w");
    if (file == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    for (int n = 0; n < num_states; ++n) {
        numerov(psi, energies[n]);
        normalize(psi);

        fprintf(file, "# Estado n=%d\n", n);
        for (int i = 0; i < N; ++i) {
            double x = X_MIN + i * H;
            fprintf(file, "%f %f\n", x, psi[i]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Datos guardados en resultados.txt\n");

    return 0;
}
