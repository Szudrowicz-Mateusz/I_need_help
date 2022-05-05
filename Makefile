CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

BIN = bin

LIBRARIES	:= -lsfml-graphics -lsfml-window -lsfml-system
EXECUTABLE	:= main

HEADERS = Ball.h Bazowa.h
SRC = Ball.cpp Bazowa.cpp main.cpp
OBJ = Ball.o Bazowa.o main.o

%.o: %.cpp $(HEADERS)
	$(CXX) -c $< -o $@ $(CXX_FLAGS)

all: $(EXECUTABLE)

run: all
	./$(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CXX) $(CXX_FLAGS) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(EXECUTABLE) $(OBJ)
