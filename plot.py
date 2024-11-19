import numpy as np
import matplotlib.pyplot as plt

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

fig, axs = plt.subplots(2, 2, figsize=(14, 12))
axs = axs.flatten()

for n, state in enumerate(data):
    x = np.array([point[0] for point in state])  
    psi = np.array([point[1] for point in state])  
    
    dx = x[1] - x[0]
    psi /= np.sqrt(np.sum(psi**2) * dx) 
    psi_squared = psi**2  
    potential = 0.5 * x**2  

    # Escalar las funciones
    psi *= 2  
    psi_squared /= np.max(psi_squared)  
    potential /= np.max(potential)  

    # Graficar
    axs[n].plot(x, psi, label=r"$\Psi(x)$", linewidth=1.5, color="blue")
    axs[n].plot(x, psi_squared, label=r"$|\Psi(x)|^2$", linestyle="--", color="orange")
    axs[n].plot(x, potential, 'k--', label=r"$V(x)$ (escalado)", alpha=0.8)
    axs[n].set_title(f"Estado n={n}", fontsize=12)
    axs[n].set_xlabel("x", fontsize=10)
    axs[n].set_ylabel("Amplitud", fontsize=10)
    axs[n].legend(fontsize=9)
    axs[n].grid(alpha=0.3)

fig.suptitle("Funciones de Onda del Oscilador Armónico Cuántico", fontsize=18, y=0.98)
plt.tight_layout(rect=[0, 0, 1, 0.96])
plt.savefig("oscilador_armonico_cuantico.png", dpi=300)
plt.show()
