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
  int n = occ_get_line_number("D:\\Workspaces\\Project\\nxCad\\node-cad\\data\\Cable Tie 2,5х100 мм.STEP");
  // CURL *curl;
  // CURLcode res;

  // curl = curl_easy_init();
  // if (curl) {
  //   curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.ca");
  //   /* example.com is redirected, so we tell libcurl to follow redirection */
  //   curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

  //   /* Perform the request, res will get the return code */
  //   res = curl_easy_perform(curl);
  //   /* Check for errors */
  //   if (res != CURLE_OK)
  //     fprintf(stderr, "curl_easy_perform() failed: %s\n",
  //             curl_easy_strerror(res));

  //   /* always cleanup */
  //   curl_easy_cleanup(curl);
  // }

  puts("puts => cadinit is running!");

  PG_RETURN_INT32(n);
}