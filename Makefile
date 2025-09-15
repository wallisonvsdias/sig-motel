all:
	gcc -c -Wall *.c
	gcc -o sig-motel *.o

.PHONY: clean
clean:
	rm -f *.o sig-motel