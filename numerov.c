#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000        
#define X_MIN -10.0  
#define X_MAX 10.0  
#define H ((X_MAX - X_MIN) / N)  
#define M 1.0        
#define HBAR 1.0      
#define OMEGA 1.0    

// Potencial del oscilador armónico
double V(double x) {
    return 0.5 * M * OMEGA * OMEGA * x * x;
}

// Implementación del método de Numerov
void numerov(double psi[], double E) {
    double x = X_MIN;
    double k_prev, k_curr, k_next;

    psi[0] = 0.0;       // Condición inicial
    psi[1] = 1e-5;      // Segundo valor inicial

    for (int i = 1; i < N - 1; i++) {
        x = X_MIN + i * H;
        k_prev = 2 * M * (E - V(x - H)) / (HBAR * HBAR);
        k_curr = 2 * M * (E - V(x)) / (HBAR * HBAR);
        k_next = 2 * M * (E - V(x + H)) / (HBAR * HBAR);

        psi[i + 1] = (2 * (1 - 5 * H * H * k_curr / 12) * psi[i] -
                      (1 + H * H * k_prev / 12) * psi[i - 1]) /
                     (1 + H * H * k_next / 12);
    }
}

int main() {
    double psi[N];
    double E = 1.0; // Energía inicial

    // Calcular las funciones de onda con Numerov
    numerov(psi, E);

    // Guardar los resultados en un archivo
    FILE *file = fopen("resultados.txt", "w");
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    // Escribir los resultados en el archivo
    for (int i = 0; i < N; ++i) {
        double x = X_MIN + i * H;
        fprintf(file, "%f %f\n", x, psi[i]);
    }

    // Cerrar el archivo
    fclose(file);
    printf("Datos guardados en resultados.txt\n");

    return 0;
}
