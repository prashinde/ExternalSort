ExternalSort: Collection.o Memory.o ExternalSort.o main.o
	g++ -std=c++11 -o ExternalSort -g Collection.o Memory.o ExternalSort.o main.o

ExternalSort.o: ExternalSort.cpp
	g++ -std=c++11 -g -c -Wall ExternalSort.cpp

Collection.o: Collection.cpp
	g++ -std=c++11 -g -c -Wall Collection.cpp

Memory.o:Memory.cpp
	g++ -std=c++11 -g -c -Wall Memory.cpp

main.o: main.cpp
	g++ -std=c++11 -g -c -Wall main.cpp

ExternalSortTest: ExternalSortTest.o ExternalSort.o
	g++ -std=c++11 -o ExternalSortTest -g ExternalSortTest.o ExternalSort.o \
		-lgtest -lpthread

ExternalSortTest.o: ExternalSortTest.cpp
	g++ -std=c++11 -g -c -Wall ExternalSortTest.cpp

all: ExternalSort ExternalSortTest

test: ExternalSortTest

clean:
	rm -f *.o ExternalSort ExternalSortTest
