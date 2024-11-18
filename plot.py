import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("resultados.txt")
x = data[:, 0]
psi = data[:, 1]

plt.plot(x, psi)
plt.title("Función de onda $\psi(x)$")
plt.xlabel("x")
plt.ylabel("$\psi(x)$")
plt.grid(True)
plt.savefig('resultados.png', 
            dpi=300, bbox_inches='tight')
plt.close()
