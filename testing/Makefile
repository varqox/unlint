CXX = g++
TARG = test
OBJS = test.o unlint.o
CXXFLAGS = -s -O3
HEADERS = ../unlint.hpp
RM = rm -f

.PHONY all clean

all: $(TARG) gen cont spr trol

$(TARG): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(TARG)

unlint.o: ../unlint.CXX
	$(CXX) ../unlint.CXX -c $(CXXFLAGS) -o unlint.o

trol: trol.o unlint.o $(HEADERS)
	$(CXX) unlint.o trol.o $(CXXFLAGS) -o trol

trol.o: trol.CXX $(HEADERS)
	$(CXX) trol.CXX -c $(CXXFLAGS) -o trol.o

test.o: test.CXX $(HEADERS)
	$(CXX) test.CXX -c $(CXXFLAGS) -o test.o

gen: gen.CXX
	$(CXX) gen.CXX $(CXXFLAGS) -o gen

spr: spr.CXX
	$(CXX) spr.CXX $(CXXFLAGS) -o spr

cont: cont.CXX
	$(CXX) cont.CXX $(CXXFLAGS) -o cont

clean:
	$(RM) *.o