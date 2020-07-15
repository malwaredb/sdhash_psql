INCLUDESRV=$(shell pg_config --includedir-server)
INCLUDEDIR=$(shell pg_config --includedir)
INSTALLDIR=$(shell pg_config --pkglibdir)

all: sdhash_psql.so
INCLUDES = -I sdhash/sdbf/
MISC = -Wall

all: main sdhash_psql.so

sdhash_psql.o: sdhash_psql.c sdhash_helper.h
	gcc -I$(INCLUDESRV) -I$(INCLUDEDIR) -fPIC -c sdhash_psql.c ${MISC}

sdhash_psql.so: sdhash_psql.o sdhash_helper.o
	gcc -fopenmp -shared -Wl,--no-as-needed -o sdhash_psql.so sdhash_psql.o sdhash_helper.o sdhash/libsdbf.a sdhash/external/stage/lib/libboost_thread.a sdhash/external/stage/lib/libboost_filesystem.a -lcrypto -lm -lc

install: sdhash_psql.so
	install -g root -o root sdhash_psql.so $(INSTALLDIR)/sdhash_psql.so

sdhash_helper.o: sdhash_helper.h sdhash_helper.cpp
	g++ -c sdhash_helper.cpp -fPIC ${INCLUDES} ${MISC}

main.o: main.cpp
	g++ -c main.cpp ${INCLUDES} ${MISC}

main: main.o
	g++ main.o -o main ${MISC} -fopenmp sdhash/libsdbf.a sdhash/external/stage/lib/libboost_thread.a sdhash/external/stage/lib/libboost_filesystem.a -lcrypto -lm -lc

.phony: clean
clean:
	rm *.o *.so main
