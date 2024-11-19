import numpy as np
import matplotlib.pyplot as plt

# Leer datos del archivo generado por el código en C
with open("resultados.txt", "r") as file:
    lines = file.readlines()

data = []
state = []
for line in lines:
    if line.startswith("#"):
        if state:
            data.append(state)
        state = []
    elif line.strip():
        x, psi = map(float, line.split())
        state.append((x, psi))
if state:
    data.append(state)

# Configuración de la gráfica
fig, axs = plt.subplots(2, 2, figsize=(12, 10))
axs = axs.flatten()

for n, state in enumerate(data):
    x = np.array([point[0] for point in state])
    psi = np.array([point[1] for point in state])
    
    # Normalización adicional para seguridad
    dx = x[1] - x[0]
    psi /= np.sqrt(np.sum(psi**2) * dx)
    
    psi_squared = psi**2
    potential = 0.5 * x**2  # V(x)

    # Escalado para mejor visualización
    psi /= np.max(np.abs(psi))  # Escalar Psi para claridad
    psi_squared /= np.max(psi_squared)  # Escalar Psi^2
    potential /= np.max(potential)  # Escalar V(x)

    axs[n].plot(x, psi, label=r"$\Psi(x)$")
    axs[n].plot(x, psi_squared, label=r"$|\Psi(x)|^2$")
    axs[n].plot(x, potential, 'k--', label=r"$V(x)$ (escalado)")
    axs[n].set_title(f"Estado n={n}")
    axs[n].set_xlabel("x")
    axs[n].set_ylabel("Amplitud")
    axs[n].legend()
    axs[n].grid()

fig.suptitle("Funciones de Onda del Oscilador Armónico Cuántico", fontsize=16)
plt.tight_layout(rect=[0, 0, 1, 0.96])
plt.savefig("oscilador_armonico_cuantico.png", dpi=300)
plt.show()
