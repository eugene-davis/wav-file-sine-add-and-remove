#Linking
build: wave_io.o main.o
	g++ main.o wave_io.o -o 381-project-phase-1

#Compilation
main.o: main.cpp
	g++ -c main.cpp -o main.o
	
wave_io.o: wave_io.cpp
	g++ -c wave_io.cpp -o wave_io.o
	
clean:
	rm *o 381-project-phase-1