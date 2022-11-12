
test: main.c lib/ppm.h lib/libppm.a
	gcc -std=c2x -o build/test.exe main.c -L"./lib" -L"C:\\libs" -I"C:\\libs" -lppm -lcanvas -lcolor

lib/ppm.h: ppm.h
	cp ppm.h lib/ppm.h

lib/libppm.a: bin/ppm.o lib/ppm.h
	ar rcs lib/libppm.a bin/ppm.o

bin/ppm.o: ppm.c ppm.h
	gcc -std=c2x -c -o bin/ppm.o ppm.c -L"C:\\libs" -I"C:\\libs"

install: lib/ppm.h lib/libppm.a
	cp lib/ppm.h "C:\\libs\\ppm.h"
	cp lib/libppm.a "C:\\libs\\libppm.a"
