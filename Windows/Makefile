CC = gcc
WR = windres
CFLAGS = -fdiagnostics-color=always -g -Wall
RES = resources.rc
FILES = ch_main.c ch_game.c resources.o

all:
	$(WR) $(RES) -O coff -o resources.o
	$(CC) $(CFLAGS) $(FILES) -o choices.exe

clean:
	rm -f choices
	
.PHONY: all clean
