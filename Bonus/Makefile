CC = g++
FLAGS = -std=c++11 
COMPILE_FLAGS = $(FLAGS) -c 
ALL_FILES= main.o Messenger.o Robot.o Channel.o Exceptions.o

all: 2.out

2.out: ${ALL_FILES}
	${CC} ${ALL_FILES} ${FLAGS} -o 2.out

main.o: main.cpp Messenger.h Exceptions.h
	${CC} ${COMPILE_FLAGS} main.cpp 

Messenger.o: Messenger.cpp Messenger.h Robot.h Channel.h Exceptions.h
	${CC} ${COMPILE_FLAGS} Messenger.cpp

Robot.o: Robot.h Robot.cpp Channel.h
	${CC} ${COMPILE_FLAGS} Robot.cpp

Channel.o: Channel.cpp Channel.h Robot.h
	${CC} ${COMPILE_FLAGS} Channel.cpp

Exceptions.o: Exceptions.h Exceptions.cpp
	${CC} ${COMPILE_FLAGS} Exceptions.cpp
	
.PHONY: clean
clean:
	rm -r *.o *.out