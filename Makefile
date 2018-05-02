CC = gcc
CFLAGS = -O2 -march=native

GCH = pin.h.gch sheet.h.gch
OBJ = main.o 

eddwall: $(OBJ) $(GCH)
	gcc -o $@ $(OBJ) $(CFLAGS) -lpigpio -pthread -lrt

$(GCH): *.h
	$(CC) -c $^ $(CFLAGS) -pthread -lpigpio -lrt

$(OBJ): *.c
	$(CC) -c $^ $(CFLAGS) -pthread -lpigpio -lrt


.PHONY: clean
clean:
	rm *.o *.gch
