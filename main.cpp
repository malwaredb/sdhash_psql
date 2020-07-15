#include <iostream>
#include <fstream>
#include <cstdlib>
#include "sdbf_class.h"
using namespace std;

const char* TEST_SDHASH1 = "sdbf:03:12:README.files:586:sha1:256:5:7ff:160:1:8:AAAAAAAAAAAAAAAAAgAAAAAAAAAAAQAAAAIAAAACAAAAAAAAAACAAAAAAAAgEgAAAAAAAAAAAAAAAACAAAEAQAAAAAAIAAAACAAAAAAAAAAAAAAAAAACAAAAAAAgAAAAAAAAAAAgAAAAAAAAIAAAAAAAAQAAQAAAACAAAAAAAAAAAAAAAAAAAABAAEAAAAAAAAAAAAAAAQAAAAAAAAAABAAAAAAAAAAAAAAAAAABAABAAAAAAAACAAAAAAAACAAAAACAQAAAAAAIACAAAAAAAAAAAAABBAAAgAAAAAAAAIAAAAAAAAAAIAAAAEAAAAAAAAAAAAAACAAAAAQAAAAAAA==";

int main(int argc, char* argv[]) {
	sdbf test1(TEST_SDHASH1);
	cout << "sdbf1: " << test1.name() << ", size: " << test1.size() << endl;
	sdbf test2(TEST_SDHASH1);
	cout << "sdbf2: " << test2.name() << ", size: " << test2.size() << endl;
	uint32_t similarity = test1.compare(&test2, 0);
	cout << "Similarity: " << similarity << endl;

	if (argc > 1) {
		char* fname = argv[1];
		sdbf test3(fname, 1024*16);
		cout << test3.name() << " size: " << test3.size() << endl;

		if (argc > 2) {
			sdbf test4(argv[2], 1024*16);
			cout << test4.name() << " size: " << test4.size() << endl;
			cout << test3.name() << " & " << test4.name() << " similarity: " << test3.compare(&test4, 0) << endl;
		}
	}

	return EXIT_SUCCESS;
}
