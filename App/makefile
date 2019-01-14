App_ranges: main.o
	g++ main.o lib/libIntRange.a -o App_ranges -lm
	-rm *.o
main.o:
	g++ -std=c++11 -o main.o -c src/main.cpp