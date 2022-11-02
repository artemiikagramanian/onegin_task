all: onegin

onegin: main.o sort.o string_functions.o input_output.o operations.o 
	g++ main.o sort.o string_functions.o input_output.o operations.o

main.o: main.cpp
	g++ main.cpp -c main.o

sort.o: sort.cpp
	g++ sort.cpp -c sort.o

string_functions.o: string_functions.cpp
	g++ string_functions.cpp -c string_functions.o

input_output.o: input_output.cpp
	g++ input_output.cpp -c input_output.o

operations.o: operations.cpp
	g++ operations.cpp -c operations.o
