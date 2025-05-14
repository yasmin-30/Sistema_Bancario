#alvos
all: main

main: main.cpp ContaBancaria.o ContaBancaria.h Cliente.o Cliente.h
	g++ -o main main.cpp ContaBancaria.o Cliente.o
Cliente.o: Cliente.cpp Cliente.h
	g++ -c Cliente.cpp
ContaBancaria.o: ContaBancaria.cpp ContaBancaria.h Cliente.o
	g++ -c ContaBancaria.cpp

#limpar alvos
clean:
	rm -f *.o main