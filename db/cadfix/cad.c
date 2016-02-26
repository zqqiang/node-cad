#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <math.h>
#include <stdlib.h>
#include <stddef.h>

#include "postgres.h"
#include "fmgr.h"
#include "occapi.h"

PG_FUNCTION_INFO_V1(cadinit);
Datum cadinit(PG_FUNCTION_ARGS);
Datum cadinit(PG_FUNCTION_ARGS)
{
  puts("PG_GETARG_CSTRING");
  char* pch;
  pch = PG_GETARG_CSTRING(0);
  char path[100];
  sprintf(path, "/home/zqqiang/models/%s.fbm", pch);
  puts(path);

  char* model_name_full;
  int32 n = occ_get_line_number(path);

  printf("there are %d lines\n", n);
  FILE* fs = fopen("/home/zqqiang/logs/edgenumber.csv", "a+");
  fprintf(fs, "%d\n", n);
  fclose(fs);

  PG_RETURN_INT32(n);
}