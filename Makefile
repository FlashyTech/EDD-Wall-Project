CC = gcc
CFLAGS = -O2 -march=native
DEPS = pin.h sheet.h

%.o: %.c $(DEPS)
	$(CC) -co $@ $^ $(CFLAGS) -pthread -lpigpio -lrt

eddwall: %.o
	gcc -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm %.o
