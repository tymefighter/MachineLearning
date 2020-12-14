
FLAGS=-std=c++14 -I src

LINALG=src/linalg/*.cpp

testLinalg: ${LINALG} src/test/testLinalg.cpp
	g++ ${FLAGS} ${LINALG} src/test/testLinalg.cpp -o bin/testLinalg
	./bin/testLinalg
