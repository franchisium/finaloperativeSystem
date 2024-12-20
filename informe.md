# Proyecto: Oscilador Armonico Cuantico

Este proyecto implementa el método de Numerov para resolver numericamente el oscilador armonico cuantico, un sistema fisico que se describe mdiante la ecuacion de Schrodinger en una direccion:

![Ecuacion](/src/ecuacionosci.png)

Estos son pasos necesarios para ejecutarlo en Debian y Fedora (tambien si quieres realizarlo con Ubuntu WSL):

## Requisitos del sistema

Paquetes necesarios:

- **gcc** compilar c
- **make**
- **python3** manejar el script de graficas

## Instalacion de dependencias

#### Fedora:

    ´sudo dnf install gcc make python3 python3-pip fim´

    'sudo dnf install python3.11-venv'

    ´fim oscilador_armonico_cuantico.png´ // una vez compilado y ejecutado, sino sale la imagen 

#### Debian:

    ´sudo apt update´

    ´sudo apt install gcc make python3 python3-pip´

    'sudo apt install python3.11-venv'
    
### Ubuntu WSL:

    ´sudo apt upgrade´

    ´sudo apt install gcc make python3 python3-pip fim´

    ´sudo apt install python3.11-venv´
    
    ´fim oscilador_armonico_cuantico.png´
    
## Compilar y Ejecutar

    'git clone https://github.com/franchisium/finaloperativeSystem.git'

    'cd finaloperativeSystem'

    'make' //automatizar el proceso

    //una vez finalizado

    'make clean'

## Teoria y Resultados

Implementación del metodo de Numerov
El metodo de Numerov resuelve ecuaciones diferenciales de la forma:

![metodo](/src/metodonumerov.png)

El potencial del oscilador armonico cuántico está dado por 

![potencial](/src/potencial.png)

La ecuación de Schrodinger se discretiza usando el método de Numerov, obteniendo un conjunto de valores discretos para ψ(x).

**Por lo tanto**

El programa debe calcular y graficar: Las funciones propias y las densidades de probabilidad 

Ejemplo de graficas esperadas:

![graphs](/src/graphsesperadas.jpg)
