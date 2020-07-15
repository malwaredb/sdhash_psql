#ifndef sdhash_helper__
#define sdhash_helper__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int32_t sdhash_similarity(char* hash1, char* hash2);
char* sdhash_from_buffer(char* name, char *buffer, int buffLen);
char* sdhash_from_file(char* fname);

#ifdef __cplusplus
}
#endif

#endif
