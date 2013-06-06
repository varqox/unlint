targ=test
objects=test.o #unlint.o
flags=-s -O3
headers=unlint.h

all: $(targ) gen

$(targ): $(objects)
	g++ $(objects) $(flags) -o $(targ)

#unlint.o: unlint.cpp
#	g++ unlint.cpp -c $(flags) -o unlint.o

test.o: test.cpp $(headers)
	g++ test.cpp -c $(flags) -o test.o

gen: gen.cpp
	g++ gen.cpp $(flags) -o gen