CFLAGS = -std=c++11
CC = g++

target:main

main: main.cpp Read.cpp Gate.cpp Gate.h Input.cpp Input.h Output.cpp Output.h And.cpp And.h Or.cpp Or.h Not.h Not.cpp Flipflop.cpp Flipflop.h Decoder.h Decoder.cpp
	$(CC) $(CFLAGS)  main.cpp Gate.cpp Input.cpp Output.cpp And.cpp Or.cpp Not.cpp Flipflop.cpp Decoder.cpp -o main 
clean:
	 rm -rf *o main
