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

// occapi lib api
int occ_get_line_number(char *filename);
int occ_write_edge_face_class_evaluate(FILE *fs);
int occ_write_edge_face_class(FILE *fs);

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

PG_FUNCTION_INFO_V1(full_edge);
Datum full_edge(PG_FUNCTION_ARGS);
Datum full_edge(PG_FUNCTION_ARGS)
{
  char *method, *path;
  method = PG_GETARG_CSTRING(0);
  path = PG_GETARG_CSTRING(1);

  printf("path => %s\n", path);

  if (strcmp(method, "evaluate") == 0) {
    FILE *fs = fopen(path, "w");
    occ_write_edge_face_class_evaluate(fs);
    fclose (fs);
  } else if (strcmp(method, "import") == 0) {
    FILE *fs = fopen(path, "w");
    occ_write_edge_face_class(fs);
    fclose (fs);
  } else {
    printf("wrong option: %s\n", method);
  }
  return true;
}