CC = g++
FLAGS = -std=c++11 
COMPILE_FLAGS = $(FLAGS) -c 
ALL_FILES= main.o JsonBuilder.o Data.o String.o Integer.o Array.o Object.o Exceptions.o

all: 1.out

1.out: ${ALL_FILES}
	${CC} ${ALL_FILES} ${FLAGS} -o 1.out

main.o: main.cpp JsonBuilder.hpp
	${CC} ${COMPILE_FLAGS} main.cpp 

JsonBuilder.o: JsonBuilder.cpp JsonBuilder.hpp Data.h Object.h String.h Integer.h Array.h Exceptions.h
	${CC} ${COMPILE_FLAGS} JsonBuilder.cpp

Data.o: Data.cpp Data.h Exceptions.h
	${CC} ${COMPILE_FLAGS} Data.cpp

Object.o: Object.cpp Object.h Data.h Integer.h String.h Exceptions.h
	${CC} ${COMPILE_FLAGS} Object.cpp

String.o: String.cpp String.h Data.h Integer.h Exceptions.h
	${CC} ${COMPILE_FLAGS} String.cpp

Integer.o: Integer.cpp Integer.h Data.h String.h Exceptions.h
	${CC} ${COMPILE_FLAGS} Integer.cpp

Array.o: Array.cpp Array.h Data.h Integer.h String.h Exceptions.h
	${CC} ${COMPILE_FLAGS} Array.cpp

Exceptions.o: Exceptions.h Exceptions.cpp
	${CC} ${COMPILE_FLAGS} Exceptions.cpp
	
.PHONY: clean
clean:
	rm -r *.o *.out