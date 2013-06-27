cpp=g++
targ=test
objects=test.o #unlint.o
flags=-s -O3
headers=../unlint.hpp

all: $(targ) gen cont spr trol

$(targ): $(objects)
	$(cpp) $(objects) $(flags) -o $(targ)

unlint.o: ../unlint.cpp
	$(cpp) ../unlint.cpp -c $(flags) -o unlint.o

trol: trol.o unlint.o $(headers)
	$(cpp) unlint.o trol.o $(flags) -o trol

trol.o: trol.cpp $(headers)
	$(cpp) trol.cpp -c $(flags) -o trol.o

test.o: test.cpp $(headers)
	$(cpp) test.cpp -c $(flags) -o test.o

gen: gen.cpp
	$(cpp) gen.cpp $(flags) -o gen

spr: spr.cpp
	$(cpp) spr.cpp $(flags) -o spr

cont: cont.cpp
	$(cpp) cont.cpp $(flags) -o cont