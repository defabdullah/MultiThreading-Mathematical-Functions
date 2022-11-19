main.exe : main.o functions.o
	g++ -g main.o functions.o -o main.exe -lpthread

main.o : main.cpp main.h
	g++ -g -c main.cpp

functions.o : functions.cpp main.h
	g++ -g -c functions.cpp

clean:
	rm -f *.o main.exe