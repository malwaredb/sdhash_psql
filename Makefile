INCLUDES = -I sdhash/sdbf/
MISC = -Wall

all: main

main.o: main.cpp
	g++ -c main.cpp ${INCLUDES} ${MISC}

main: main.o
	g++ main.o -o main ${MISC} -fopenmp sdhash/libsdbf.a sdhash/external/stage/lib/libboost_thread.a sdhash/external/stage/lib/libboost_filesystem.a -lcrypto -lm -lc

.phony: clean
clean:
	rm *.o main
