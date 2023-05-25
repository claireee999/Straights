CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD 
EXEC = straights
OBJECTS = vec.o subject.o card.o game.o computerPlayer.o humanPlayer.o main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
