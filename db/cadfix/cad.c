#include "postgres.h"
#include "fmgr.h"

#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

PG_FUNCTION_INFO_V1( cadinit );
Datum cadinit(PG_FUNCTION_ARGS);
Datum cadinit(PG_FUNCTION_ARGS)
{
  int mode;
  char *version;
  char *fixno;
  int result = cficInit(&mode, &version, &fixno);
  cficFree(version);
  cficFree(fixno);

  if(result==CFI_ERR_OK)
    puts("LOG: cficInit works");
  else
    puts("LOG: CFI module failed to start");

  puts("PG_GETARG_CSTRING");
  char* pch;
  pch=PG_GETARG_CSTRING(0);
  char path[100];
  sprintf(path,"/home/zhibin/models/%s.fbm",pch);
  puts(path);
  
  char *model_name_full;
  int32 n;
  if( cficFileModelOpen(path)!=CFI_ERR_OK){
    puts("LOG: open model failed");
  }
  else{
    puts("LOG: open model success");
    cficGetModelName(&model_name_full);
    printf("model name is %s\n",model_name_full);
    cficGetModelEntityTotal(CFI_TYPE_LINE,CFI_SUBTYPE_ALL,&n);
    printf("there are %d lines\n", n);
    FILE *fs = fopen("/home/zhibin/logs/edgenumber.csv","a+");
    fprintf(fs,"%d\n",n);
    fclose(fs);
  }

  PG_RETURN_INT32(n); 
}