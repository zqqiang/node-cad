#include "postgres.h"
#include "fmgr.h"

#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

PG_FUNCTION_INFO_V1(cadinit);
Datum cadinit(PG_FUNCTION_ARGS);
Datum cadinit(PG_FUNCTION_ARGS) {
  int mode;
  char *version;
  char *fixno;
  int result = cficInit(&mode, &version, &fixno);
  cficFree(version);
  cficFree(fixno);

  if (result == CFI_ERR_OK)
    puts("LOG: cficInit works");
  else
    puts("LOG: CFI module failed to start");

  puts("PG_GETARG_CSTRING");
  char *pch;
  pch = PG_GETARG_CSTRING(0);
  char path[100];
  sprintf(path, "/home/zhibin/models/%s.fbm", pch);
  puts(path);

  char *model_name_full;
  int32 n;

  STEPControl_Reader aReader;

  Interface_Static::SetCVal("xstep.cascade.unit", "mm");
  Interface_Static::SetIVal("read.step.nonmanifold", 1);
  Interface_Static::SetIVal("read.step.product.mode", 1);
  Interface_Static::SetRVal("read.precision.val", 0.01);

  if (aReader.ReadFile(_filename.c_str()) != IFSelect_RetDone) {
    puts("LOG: open model failed");
  } else {
    puts("LOG: open model success");

    // todo: better calculate line number method?
    TopoDS_Shape aResShape;
    TopExp_Explorer expEdge(aResShape, TopAbs_EDGE);
    while (expEdge.More()) {
      n++;
      expEdge.Next();
    }

    printf("there are %d lines\n", n);
    FILE *fs = fopen("/home/zhibin/logs/edgenumber.csv", "a+");
    fprintf(fs, "%d\n", n);
    fclose(fs);
  }

  PG_RETURN_INT32(n);
}

PG_FUNCTION_INFO_V1(full_edge);
Datum full_edge(PG_FUNCTION_ARGS);
Datum full_edge(PG_FUNCTION_ARGS) {
  int line_number, line_list_size = 500000, line_number_returned,
                   line_number_of_parents;
  int *line_list_of_entity_numbers, *line_signed_list_of_entity_numbers,
      *line_list_of_entity_types;
  int class;
  int magic, i;

  char *pch;
  pch = PG_GETARG_CSTRING(0);

  if (strcmp(pch, "evaluate") == 0) {
    struct timespec vartime = timer_start();  // begin a timer called 'vartime'

    FILE *fs = fopen("/home/zhibin/logs/evaluate_full_edge.csv", "w");
    // cficGetModelEntityTotal(CFI_TYPE_LINE, CFI_SUBTYPE_ALL, &line_number);
    magic = 0;
    cficGetModelEntityList(CFI_TYPE_LINE, CFI_SUBTYPE_ALL, line_list_size,
                           &magic, &line_number_returned,
                           &line_list_of_entity_numbers);

    cficGetTopoParentTotal(CFI_TYPE_LINE, line_list_of_entity_numbers[0],
                           &line_number_of_parents);
    magic = 0;
    cficGetTopoParentList(CFI_TYPE_LINE, line_list_of_entity_numbers[0],
                          line_list_size, &magic, &line_number_returned,
                          &line_list_of_entity_types,
                          &line_signed_list_of_entity_numbers);
    classify(abs(line_list_of_entity_numbers[0]), &class);

    long time_elapsed_nanos = timer_end(vartime);
    printf("Time taken (nanoseconds): %ld\n", time_elapsed_nanos);

    fprintf(fs, "%ld\n", time_elapsed_nanos);
    fclose(fs);

    return true;

  } else if (strcmp(pch, "import") == 0) {
    FILE *fs = fopen("/home/zhibin/logs/full_edge.csv", "w");
    cficGetModelEntityTotal(CFI_TYPE_LINE, CFI_SUBTYPE_ALL, &line_number);
    magic = 0;
    cficGetModelEntityList(CFI_TYPE_LINE, CFI_SUBTYPE_ALL, line_list_size,
                           &magic, &line_number_returned,
                           &line_list_of_entity_numbers);

    for (i = 0; i < line_number; i++) {
      cficGetTopoParentTotal(CFI_TYPE_LINE, line_list_of_entity_numbers[i],
                             &line_number_of_parents);
      magic = 0;
      cficGetTopoParentList(CFI_TYPE_LINE, line_list_of_entity_numbers[i],
                            line_list_size, &magic, &line_number_returned,
                            &line_list_of_entity_types,
                            &line_signed_list_of_entity_numbers);
      classify(abs(line_list_of_entity_numbers[i]), &class);
      fprintf(fs, "%d,%d,%d,%d\n%d,%d,%d,%d\n",
              (line_list_of_entity_numbers[i]),
              abs(line_signed_list_of_entity_numbers[0]),
              abs(line_signed_list_of_entity_numbers[1]), class,
              (line_list_of_entity_numbers[i]),
              abs(line_signed_list_of_entity_numbers[1]),
              abs(line_signed_list_of_entity_numbers[0]), class);
    }
    fclose(fs);
    return true;
  }
}