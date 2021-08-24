cc = gcc 
flags = -c -ggdb -Wall -O0 -o
files = main.o parts.o circuit.o input.o cpu.o mem_8_byte.o 

all: parts.o main.o circuit.o input.o mem_8_byte.o cpu.o final.elf

final.elf: main.o parts.o circuit.o input.o cpu.o mem_8_byte.o
	$(cc) $(files) -o final.elf

main.o: main.c
	$(cc) $(flags) main.o main.c

mem_8_byte.o: mem_8_byte.c
	$(cc) $(flags) mem_8_byte.o mem_8_byte.c

input.o: input.c
	$(cc) $(flags) input.o input.c

circuit.o: circuit.c
	$(cc) $(flags) circuit.o circuit.c

parts.o: parts.c
	$(cc) $(flags) parts.o parts.c

cpu.o: cpu.c
	$(cc) $(flags) cpu.o cpu.c



clean:
	rm -rf *.o final.elf
