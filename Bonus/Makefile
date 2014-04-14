# Author: Eugene Davis
# Class: CPE 381
# This make file compiles and links Bonus of CPE Project

#Linking
build: wave_io.o main.o bonus_fourier.o
	g++ -std=gnu++0x  main.o wave_io.o bonus_fourier.o -o 381-bonus

#Compilation
main.o: main.cpp
	g++ -std=gnu++0x  -c main.cpp -o main.o
	
wave_io.o: wave_io.cpp
	g++ -std=gnu++0x  -c wave_io.cpp -o wave_io.o
	
bonus_fourier.o: bonus_fourier.cpp
	g++ -std=gnu++0x  -c bonus_fourier.cpp -o bonus_fourier.o 
	
clean:
	rm *o 381-bonus
