CPU.out: main.o decoder.o reader.o registers.o
	g++ -Wall -o CPU.out -ansi main.o decoder.o reader.o registers.o

main.o: main.c registers.h decoder.h reader.h instruction.h main.h
	g++ -c -Wall -ansi main.c

decoder.o: decoder.c decoder.h registers.h main.h
	g++ -c -Wall -ansi decoder.c

reader.o: reader.c reader.h instruction.h registers.h main.h
	g++ -c -Wall -ansi reader.c

registers.o: registers.c registers.h main.h
	g++ -c -Wall -ansi registers.c

clean:
	rm -c -g main.o decoder.o reader.o registers.o

