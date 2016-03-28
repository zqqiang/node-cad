#include "postgres.h"
#include "fmgr.h"

#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stddef.h>
// #include <curl/curl.h>

PG_MODULE_MAGIC;

// occapi lib api
int occ_get_line_number(char *filename);
int occ_write_edge_face_class_evaluate(FILE *fs);
int occ_write_edge_face_class(FILE *fs);

// call this function to start a nanosecond-resolution timer
struct timespec timer_start() {
  struct timespec start_time;
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time);
  return start_time;
}

// call this function to end a timer, returning nanoseconds elapsed as a long
long timer_end(struct timespec start_time) {
  struct timespec end_time;
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_time);
  long diffInNanos = end_time.tv_nsec - start_time.tv_nsec;
  return diffInNanos;
}

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

PG_FUNCTION_INFO_V1( full_edge );
Datum full_edge(PG_FUNCTION_ARGS);
Datum full_edge(PG_FUNCTION_ARGS)
{
  char* pch;
  pch = PG_GETARG_CSTRING(0);
  if (strcmp(pch, "evaluate") == 0) {
    struct timespec vartime = timer_start();
    FILE *fs = fopen("D:\\Workspaces\\Project\\nxCad\\evaluate_full_edge.csv", "w");

    long time_elapsed_nanos = timer_end(vartime);
    printf("LOG: Time taken (nanoseconds): %ld\n", time_elapsed_nanos);

    occ_write_edge_face_class_evaluate(fs);

    fprintf (fs, "%ld\n", time_elapsed_nanos);
    fclose (fs);
  } else if (strcmp(pch, "import") == 0) {
    FILE *fs = fopen("D:\\Workspaces\\Project\\nxCad\\full_edge.csv", "w");

    occ_write_edge_face_class(fs);

    fclose (fs);
  } else {
    printf("wrong option: %s\n", pch);
  }
  return true;
}