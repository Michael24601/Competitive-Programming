CXX = g++
EXE = main.exe
OBJ = $(SRC:.cpp=.o)

# Lets us send the name of file to execute using make FILE=
ifdef FILE
  SRC = $(FILE)
else
  SRC = main.cpp
endif

all: compile link run clean

compile:
	$(CXX) -c -o $(OBJ) $(SRC)

link:
	$(CXX) *.o -o $(EXE)

run:
# If the input file is specified, use it, otherwise, take user command line input
ifdef INPUT
	type $(INPUT) | $(EXE)
else
	$(EXE)
endif

clean:
# Ensure empty line is printed before clean so output is clear
	@echo off
	@echo. & rem Empty line
	del $(EXE) *.o 
	@echo on