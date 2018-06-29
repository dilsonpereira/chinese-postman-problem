
FLAG = -O3 -m64 -Wall

Matching.o: ./Minimum-Cost-Perfect-Matching/Matching.cpp ./Minimum-Cost-Perfect-Matching/Matching.h ./Minimum-Cost-Perfect-Matching/BinaryHeap.h ./Minimum-Cost-Perfect-Matching/Globals.h ./Minimum-Cost-Perfect-Matching/Graph.h 
	g++ $(FLAG) -c ./Minimum-Cost-Perfect-Matching/Matching.cpp -o Matching.o

BinaryHeap.o: ./Minimum-Cost-Perfect-Matching/BinaryHeap.h ./Minimum-Cost-Perfect-Matching/BinaryHeap.cpp ./Minimum-Cost-Perfect-Matching/Globals.h
	g++ $(FLAG) -c ./Minimum-Cost-Perfect-Matching/BinaryHeap.cpp -o BinaryHeap.o

Graph.o: ./Minimum-Cost-Perfect-Matching/Graph.h ./Minimum-Cost-Perfect-Matching/Graph.cpp
	g++ $(FLAG) -c ./Minimum-Cost-Perfect-Matching/Graph.cpp -o Graph.o

Example.o: Example.cpp Dijkstra.h ./Minimum-Cost-Perfect-Matching/Matching.h ./Minimum-Cost-Perfect-Matching/Graph.h ChinesePostman.h
	g++ $(FLAG) -c Example.cpp -o Example.o

chinese: Matching.o BinaryHeap.o Graph.o Example.o 
	g++ $(FLAG) Matching.o BinaryHeap.o Graph.o Example.o -o chinese

