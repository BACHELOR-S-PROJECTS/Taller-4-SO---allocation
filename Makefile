main.o: Algorithm.h BestFit.h FirstFit.h WorstFit.h main.cpp 
	g++ -c main.cpp -o main.o
	g++ main.o -o main
	./main