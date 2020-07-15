#include <iostream>
#include <fstream>
#include <cstdlib>
#include "sdbf_class.h"
#include "sdhash_helper.h"
using namespace std;

extern "C" {

const uint32_t BSIZE = 1024*16; // 16KB

int32_t sdhash_similarity(char* hash1, char* hash2) {
	sdbf test1(hash1);
        sdbf test2(hash2);
        return test1.compare(&test2, 0);
}

char* sdhash_from_buffer(char* name, char *buffer, int buffLen) {
	sdbf sdbfObj(name, buffer, BSIZE, buffLen, NULL);
	string sdbfStr = sdbfObj.to_string();
	char *b = new char [sdbfStr.length()+1];
	strcpy(b, sdbfStr.c_str());
	return b;
}

char* sdhash_from_file(char* fname) {
	sdbf sdbfObj(fname, BSIZE);
	string sdbfStr = sdbfObj.to_string();
	char *b = new char [sdbfStr.length()+1];
	strcpy(b, sdbfStr.c_str());
	return b;
}

}
