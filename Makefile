
CFLAGS = -Wall -g

fsm: state_machines.o
	gcc $(CFLAGS) state_machines.c -o state_machines

clean:
	rm -rf *.o *.dSYM