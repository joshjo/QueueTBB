all: main

main: main.o
	g++ -o main main.o -ltbb
	
main.o:	main.cpp
	g++ -c main.cpp -ltbb
	
queueTBB.o: queueTBB.cpp queueTBB.h
	g++ -c queueTBB.cpp -ltbb
	
clean:
	rm main main.o queueTBB.o
