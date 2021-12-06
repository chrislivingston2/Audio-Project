audio: main.o wave_header.o
	g++ -o audio main.o wave_header.o
	
main.o: main.cpp 
	g++ -c main.cpp 
	
wave_header.o: wave_header.cpp wave_header.h
	g++ -c wave_header.cpp wave_header.h

make clean:
	rm *.o audio
