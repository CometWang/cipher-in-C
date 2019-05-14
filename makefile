# Name: Jia Wang
# Student Number: 251041197
# Description: This program is the makeﬁle to compile and link the programs.


C = gcc
CFLAGS = -std=c99 -lm
RMFLAGS = -f
test:ciphers.o cipher_main.o
	gcc -o test ciphers.o cipher_main.o
ciphers.o:ciphers.c ciphers.h
	gcc -c ciphers.c
cipher_main.o:cipher_main.c ciphers.h
	gcc -c cipher_main.c
clean:
	rm -f *.o test