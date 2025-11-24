CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

OBJS = WordCount.o tddFuncs.o

all: test01 test02 test03

test01: lab07Test01.o $(OBJS)
	$(CXX) $(CXXFLAGS) -o test01 lab07Test01.o $(OBJS)

test02: lab07Test02.o $(OBJS)
	$(CXX) $(CXXFLAGS) -o test02 lab07Test02.o $(OBJS)

test03: lab07Test03.o $(OBJS)
	$(CXX) $(CXXFLAGS) -o test03 lab07Test03.o $(OBJS)

WordCount.o: WordCount.cpp WordCount.h
	$(CXX) $(CXXFLAGS) -c WordCount.cpp

tddFuncs.o: tddFuncs.cpp tddFuncs.h
	$(CXX) $(CXXFLAGS) -c tddFuncs.cpp

lab07Test01.o: lab07Test01.cpp WordCount.h tddFuncs.h
	$(CXX) $(CXXFLAGS) -c lab07Test01.cpp

lab07Test02.o: lab07Test02.cpp WordCount.h tddFuncs.h
	$(CXX) $(CXXFLAGS) -c lab07Test02.cpp

lab07Test03.o: lab07Test03.cpp WordCount.h tddFuncs.h
	$(CXX) $(CXXFLAGS) -c lab07Test03.cpp

clean:
	rm -f *.o test01 test02 test03
