CXX = g++
TARG = test
OBJS = test.o unlint.o
CXXFLAGS = -s -O3
RM = rm -f

.PHONY all clean

all: $(TARG) gen cont spr trol

$(TARG): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(TARG)

unlint.o: ../unlint.cpp
	$(CXX) ../unlint.cpp -c $(CXXFLAGS) -o unlint.o

trol: trol.o unlint.o ../unlint.hpp
	$(CXX) unlint.o trol.o $(CXXFLAGS) -o trol

trol.o: trol.cpp $(HEADERS)
	$(CXX) trol.cpp -c $(CXXFLAGS) -o trol.o

test.o: test.cpp ../unlint.hpp
	$(CXX) test.cpp -c $(CXXFLAGS) -o test.o

gen: gen.cpp
	$(CXX) gen.cpp $(CXXFLAGS) -o gen

spr: spr.cpp
	$(CXX) spr.cpp $(CXXFLAGS) -o spr

cont: cont.cpp
	$(CXX) cont.cpp $(CXXFLAGS) -o cont

clean:
	$(RM) *.o