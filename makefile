test.exe: testLL.o Node.o LinkedList.o
	g++ testLL.o Node.o LinkedList.o -o test.exe

test.o: testLL.cpp
	g++ -c testLL.cpp -o testLL.o

Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o

LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp -o LinkedList.o

clean:
	rm *.o test.exe

run:
	test.exe