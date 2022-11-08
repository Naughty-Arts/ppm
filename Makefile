test: main.c lib/ppm.h
	gcc -std=c2x -o build/test.exe main.c -L./lib -I"C:\\libs" -L"C:\\libs"

lib/ppm.h: ppm.h
	cp ppm.h lib/ppm.h

install: lib/ppm.h
	cp lib/ppm.h "C:\\libs\ppm.h"
