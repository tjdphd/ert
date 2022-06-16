testiri: libiri testiri.c
	gcc -L. -o testiri -liri testiri.c
%.o:	%.for
	gfortran -fpic -c -o $@ $< 
objects := $(patsubst %.for,%.o, $(wildcard *.for))
objects := $(filter-out iritest.o irirtam-test.o, $(objects))

libiri : $(objects)
	gfortran -shared -o libiri.so $(objects)

.PHONY: clean

clean:
	rm -f *.o libiri.so testiri
