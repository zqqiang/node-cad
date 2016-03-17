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

PG_MODULE_MAGIC;

int occ_get_line_number(char *filename);

PG_FUNCTION_INFO_V1(cadinit);
Datum cadinit(PG_FUNCTION_ARGS);
Datum cadinit(PG_FUNCTION_ARGS)
{
  int n = 0;
  char path[100];
  char* pch = PG_GETARG_CSTRING(0);
  FILE* fs = fopen("/home/zqqiang/logs/edgenumber.csv", "a+");

  sprintf(path, "/home/zqqiang/models/%s.fbm", pch);
  puts(path);

  n = occ_get_line_number(path);

  printf("there are %d lines\n", n);
  fprintf(fs, "%d\n", n);
  fclose(fs);

  PG_RETURN_INT32(n);
}