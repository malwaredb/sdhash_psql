#include "postgres.h"
#include "fmgr.h"
#include "sdhash_helper.h"

PG_MODULE_MAGIC;

#define MAX_SIZE 10000000

PG_FUNCTION_INFO_V1(pg_sdhash_compare);
Datum pg_sdhash_compare(PG_FUNCTION_ARGS);

Datum pg_sdhash_compare(PG_FUNCTION_ARGS) {
  text *arg1 = PG_GETARG_TEXT_P(0);
  text *arg2 = PG_GETARG_TEXT_P(1);
  int32 score = sdhash_similarity((char *) VARDATA(arg1), (char *) VARDATA(arg2));
  PG_RETURN_INT32(score);
}
// 
// CREATE OR REPLACE FUNCTION fuzzy_compare(TEXT, TEXT) RETURNS INTEGER AS 'ssdeep_psql.so', 'pg_fuzzy_compare' LANGUAGE 'C';
//
