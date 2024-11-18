
TARGET = numerov

SRC = numerov.c #tomar la fuente

CC = gcc #compilacion
CFLAGS = -Wall -lm

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) *.o
