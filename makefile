C = gcc
O = -o
W = -Wall
PAQUETES = -lm
ARCHIVO_C = numerov.c
EJECUTABLE_C = oscilador
VENV_DIR = .venv
PYTHON_SCRIPT = plot.py
IMAGEN = oscilador_armonico_cuantico.png

.PHONY: all clean run_c run_python 
# Regla principal: compilar y ejecutar el programa en C
all: $(EJECUTABLE_C) run_c run_python

# Regla para compilar el programa en C
$(EJECUTABLE_C): $(ARCHIVO_C)
	$(C) $(W) $(O) $@ $^ $(PAQUETES)

venv: $(VENV_DIR)/bin/activate

$(VENV_DIR)/bin/activate:
	python3 -m venv $(VENV_DIR)
	$(VENV_DIR)/bin/pip install matplotlib numpy

# Regla para ejecutar el programa compilado
run_c: $(EJECUTABLE_C)
	@echo "Ejecutando programa en C..."
	./$(EJECUTABLE_C)

run_python: venv
	$(VENV_DIR)/bin/python $(PYTHON_SCRIPT)


# Limpieza de archivos generados
clean:
	rm -f $(EJECUTABLE_C)
	rm -f resultados.txt
	rm -r $(VENV_DIR)
	rm -f $(IMAGEN)