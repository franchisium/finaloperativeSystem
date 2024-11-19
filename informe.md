# Proyecto: Oscilador Armonico Cuantico

Este proyecto implementa el método de Numerov para resolver numericamente el oscilador armonico cuantico, un sistema fisico que se describe mdiante la ecuacion de Schrodinger en una direccion:

![Ecuacion](/src/ecuacionosci.png)

Estos son pasos necesarios para ejecutarlo en Debian y Fedora (tambien si quieres realizarlo con Ubuntu WSL):

## Requisitos del sistema

Paquetes necesarios:

- **gcc** compilar c
- **make**
- **python3** manejar el script de graficas
- **pip** para instalar paquetes **matplotlib** para hacer plots

## Instalacion de dependencias

#### Fedora:

    ´sudo dnf install gcc make python3 python3-pip´

    ´pip3 install matplotlib´

    ´sudo dnf install fim´ //ver las graficas como imagen

#### Debian y Ubuntu (WSL):

    ´sudo apt update´

    ´sudo apt install gcc make python3 python3-pip´

    ´pip3 install matplotlib´
    
    ´sudo apt install fim´ //ver las graficas como imagen

## Compilar y Ejecutar

    'git clone https://github.com/franchisium/finaloperativeSystem.git'

    'cd finaloperativeSystem'

    'make' //automatizar el proceso

    './numerov'

    'python3 plot.py' //genera la imagen de las graficas

    fim resultados.png

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
