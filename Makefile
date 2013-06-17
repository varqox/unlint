cpp=g++
targ=test
objects=test.o #unlint.o
flags=-s -O3
headers=unlint.h

all: $(targ) gen cont spr

$(targ): $(objects)
	$(cpp) $(objects) $(flags) -o $(targ)

#unlint.o: unlint.cpp
#	$(cpp) unlint.cpp -c $(flags) -o unlint.o

test.o: test.cpp $(headers)
	$(cpp) test.cpp -c $(flags) -o test.o

gen: gen.cpp
	$(cpp) gen.cpp $(flags) -o gen

spr: spr.cpp
	$(cpp) spr.cpp $(flags) -o spr

cont: cont.cpp
	$(cpp) cont.cpp $(flags) -o cont