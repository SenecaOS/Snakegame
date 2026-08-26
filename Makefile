CC = gcc
CLFAGS = -Wall -Wextra -g

snakegame: terminal.o main.o movement.o draw_ui.o gamelogic.o
	$(CC) $(CFLAGS) -o snakegame terminal.o main.o movement.o draw_ui.o gamelogic.o

main.o: main.c data.h
	$(CC) $(CFLAGS) -c main.c

terminal.o: terminal.c
	$(CC) $(CFLAGS) -c terminal.c

movement.o: movement.c
	$(CC) $(CFLAGS) -c movement.c

draw_ui.o: draw_ui.c
	$(CC) $(CFLAGS) -c draw_ui.c
gamelogic.o: gamelogic.c
	$(CC) $(CFLAGS) -c gamelogic.c 
clean:
	rm -f snakegame *.o

