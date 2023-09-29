CXX = g++
EXE = test.exe
OBJ = $(SRC:.cpp=.o)
FILE = test.cpp

OUTPUT = output.txt
INPUT = input.txt

# Lets us send the name of file to execute using make FILE=
ifdef FILE
  SRC = $(FILE)
else
  SRC = test.cpp
endif

all: compile link run clean

IO: compile link runIO cleanIO

compile:
	$(CXX) -c -o $(OBJ) $(SRC)

link:
	$(CXX) *.o -o $(EXE)

run:
	$(EXE)

runIO:
# Takes input from file and outputs to file
	type $(INPUT) | $(EXE) > $(OUTPUT)

clean:
# Ensure empty line is printed before clean so output is clear
# since the output is on the terminal, not a file
	@echo off
	@echo. & rem Empty line
	del $(EXE) *.o 
	@echo on

cleanIO:
# No need to print empty line since output is in a file
	del $(EXE) *.o 