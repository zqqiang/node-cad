#include "postgres.h"
#include "fmgr.h"

#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>
// #include <curl/curl.h>

PG_MODULE_MAGIC;

int occ_get_line_number(char *filename);

PG_FUNCTION_INFO_V1(cadinit);
Datum cadinit(PG_FUNCTION_ARGS);
Datum cadinit(PG_FUNCTION_ARGS)
{
  int n = 0;
  char* fullpath = NULL;

  fullpath = PG_GETARG_CSTRING(0);
  n = occ_get_line_number(fullpath);

  PG_RETURN_INT32(n);
}