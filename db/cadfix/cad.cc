#include "postgres.h"
#include "fmgr.h"

#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

PG_FUNCTION_INFO_V1(cadinit);
Datum cadinit(PG_FUNCTION_ARGS);
Datum cadinit(PG_FUNCTION_ARGS) {
  int mode;
  char* version;
  char* fixno;
  int result = cficInit(&mode, &version, &fixno);
  cficFree(version);
  cficFree(fixno);

  if (result == CFI_ERR_OK)
    puts("LOG: cficInit works");
  else
    puts("LOG: CFI module failed to start");

  puts("PG_GETARG_CSTRING");
  char* pch;
  pch = PG_GETARG_CSTRING(0);
  char path[100];
  sprintf(path, "/home/zhibin/models/%s.fbm", pch);
  puts(path);

  char* model_name_full;
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
    FILE* fs = fopen("/home/zhibin/logs/edgenumber.csv", "a+");
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

  char* pch;
  pch = PG_GETARG_CSTRING(0);

  if (strcmp(pch, "evaluate") == 0) {
    struct timespec vartime = timer_start();  // begin a timer called 'vartime'

    FILE* fs = fopen("/home/zhibin/logs/evaluate_full_edge.csv", "w");
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
    FILE* fs = fopen("/home/zhibin/logs/full_edge.csv", "w");
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

PG_FUNCTION_INFO_V1(translate2);
Datum translate2(PG_FUNCTION_ARGS);
Datum translate2(PG_FUNCTION_ARGS) {
  FILE* fp;
  char* pch;
  char path[100];
  char line_buffer[100];
  char line_number = 0;
  char* p[100];
  char* buff;
  int i, j;

  //////////////////////////////////////////////////////////
  // 0. extra from table
  int geomtablenumber = 0;
  char featurename[100];
  // How to extend?
  // 1. define new predicate flag variable
  // 2. Define and allocate memeory of char array[] to put the fragment cmd

  bool equalflage = false;
  bool geomflage = false;
  bool maxarea = false;
  bool parallel = false;

  char cmd_equal[20000] = "";
  char cmd_unequal[20000] = "";
  char cmd_geom[20000] = "";
  char cmd_maxarea[20000] = "";
  char cmd_parallel[20000] = "";

  // bounds variables
  bool boundsflage = false;
  char cmd_bounds[20000] = "";

  bool dihedralflage = false;
  char cmd_dihedral[20000] = "";

  bool face_shape_flag = false;
  char cmd_shape_face[20000] = "";

  struct snode *face_shape_head, *face_shape_curr, *face_shape_temp;  // geom
  // export variables
  bool export_flag = false;
  char cmd_export[20000] = "CREATE TABLE RESULT AS SELECT distinct\n";
  struct snode *export_head, *export_curr, *export_temp;

  char selectclause[10000] =
      "CREATE TABLE RESULT AS SELECT \n";  // CREATE TABLE RESULT AS
  char targetlist[10000] = "";  // used for group by statement
  char agglist[10000] = "";     // used for group by statement
  char fromclause[10000] = "\nFROM\n";
  char whereclause[2000000] = "\nWHERE\n";
  static char query[2000000] = "";

  bool issinglequery = true;
  char selectclause2[10000] =
      "CREATE TABLE RESULT AS SELECT *\n";  // CREATE TABLE RESULT AS
  char fromclause2[10000] = "FROM result";
  char whereclause2[2000000] = "\nWHERE\n";
  static char query2[2000000] = "";

  struct entity *entityhead, *entitycurr, *entitytemp;
  pch = PG_GETARG_CSTRING(0);

  sprintf(path, "/home/zhibin/defs/%s.csv", pch);
  puts(path);
  fp = fopen(path, "a+");

  char* shapelist[100];
  int si = 0, tsi;
  bool isshape = false;

  // 3. create a new predicate list

  // store entity type info

  entityhead = (entity*)malloc(sizeof(entity));
  entitycurr = entityhead;

  int full_edge_number = 0;  // bounds to full_edge
  struct node *head, *curr, *temp;
  head = (node*)malloc(sizeof(node));
  curr = head;

  struct geomnode *geomhead, *geomcurr, *geomtemp;  // geom
  geomhead = (geomnode*)malloc(sizeof(geomnode));
  geomcurr = geomhead;
  // 4.

  /////////////////start of while
  while (fgets(line_buffer, sizeof(line_buffer), fp)) {  // read a line
    ++line_number;
    //  printf("Read line%4d: %s", line_number, line_buffer);
    line_buffer[strlen(line_buffer) - 1] = '\0';

    buff = line_buffer;
    i = 0;
    while ((p[i] = strtok(buff, " :,()")) !=
           NULL) {  // break into 3 strings. p[0],p[1],p[2]
      i++;
      buff = NULL;
    }

    if (strcmp(p[0], "define") == 0 && strcmp(p[2], "as") == 0) {
      strcpy(featurename, p[1]);
      //  printf("feature name %s\n", featurename);
      continue;
    }

    if (strcmp(p[0], "face") == 0 || strcmp(p[0], "edge") == 0 ||
        strcmp(p[0], "vertex") == 0) {
      //   printf("type line, i=%d\n",i);

      while (i > 2) {
        //   printf("p[%d]=%s\n",i-1,p[i-1]);
        i--;
        entitytemp = (entity*)malloc(sizeof(entity));
        strcpy(entitytemp->name, p[i]);
        strcpy(entitytemp->type, p[1]);
        entitytemp->next = NULL;
        entitycurr->next = entitytemp;
        entitycurr = entitytemp;
        if (entityhead == NULL) entityhead = entitycurr;
        p[i] = '\0';
      }
      continue;
    }

    if (strcmp(p[0], "satisfying") == 0) {
      continue;
    }

    // 4. readin predicates, put data into a list
    if (strcmp(p[0], "bounds") == 0) {
      //  puts("start to read bounds");
      boundsflage = true;
      temp = (node*)malloc(sizeof(node));
      strcpy(temp->edge, p[1]);
      strcpy(temp->face, p[2]);
      temp->next = NULL;
      curr->next = temp;
      curr = temp;
      if (head == NULL) head = curr;
    }
    /// ends bounds check
    else if (strcmp(p[0], "dihedral") == 0) {
      dihedralflage = true;
      sprintf(cmd_dihedral, "%sfull_edge_%s.dihedral=%s AND\n", cmd_dihedral,
              p[1], p[2]);
    } else if (strcmp(p[0], "<") == 0) {
      equalflage = true;
      sprintf(cmd_equal, "%s full_edge_%s.edge<full_edge_%s.edge AND\n",
              cmd_equal, p[0], p[2]);
    } else if (strcmp(p[0], "area") == 0) {  // example for direct translate
      sprintf(fromclause, "%sface_area %s,\n", fromclause, p[1]);
      sprintf(whereclause, "%s%s.area>%s AND\n", whereclause, p[1], p[2]);
      continue;
    } else if (strcmp(p[0], "shape_face") ==
               0) {  // example for direct translate
      isshape = true;
      shapelist[si] = malloc(sizeof(char) * 20);
      strcpy(shapelist[si], p[1]);
      si++;
    }

    else if (strcmp(p[0], "export") == 0) {  // example for direct translate
      puts("in export");
      if (export_flag == false) {  // generate face shape list
        export_head = (snode*)malloc(sizeof(snode));
        export_curr = export_head;
        export_flag = true;
      }
      while (i > 1) {
        i--;
        export_temp = (snode*)malloc(sizeof(snode));
        strcpy(export_temp->id, p[i]);
        export_temp->next = NULL;
        export_curr->next = export_temp;
        export_curr = export_temp;
        if (export_head == NULL) export_head = export_curr;
        p[i] = '\0';
      }
      continue;
    }
  }
  //////////////end of reading

  puts("end of reading");

  if (boundsflage) {  // start to turn bounds relation into full_edge relation
    // show bounds data read from csv file.
    // curr=head->next;
    // while(curr){
    //   printf("2:%s %s\n", curr->edge, curr->face);
    //   curr=curr->next;
    // }

    //////////////////////////////////////////////////////////////////////////
    // create triple relation
    list l = head, templist;
    struct node3 *head3, *curr3, *temp3;
    head3 = (node3*)malloc(sizeof(node3));
    curr3 = head3;

    while (l) {
      //    printf("%s %s\n", l->edge, l->face);
      templist = l;
      //   printf("%s %s\n", q->edge, q->face);

      while (templist) {
        if (strcmp(templist->edge, l->edge) == 0 &&
            strcmp(templist->face, l->face) != 0) {
          temp3 = (node3*)malloc(sizeof(node3));
          strcpy(temp3->edge, templist->edge);
          strcpy(temp3->face1, l->face);
          strcpy(temp3->face2, templist->face);

          temp3->next = NULL;
          curr3->next = temp3;
          curr3 = temp3;
          if (head3->next == NULL) head3 = curr3;
          full_edge_number++;  // this is to confirm how many from tables
        }
        // printf(" q %s %s\n", q->edge, q->face);
        templist = templist->next;
      }

      l = l->next;
    }

    // ////////////////////////////////////////////////////////////////////////

    char* facelist[100];
    bool isexist = false;
    i = 0;
    // show triple relations , j always points to tail of the array
    curr3 = head3->next;
    while (curr3) {
      printf("list:%s %s %s\n", curr3->edge, curr3->face1, curr3->face2);
      sprintf(selectclause, "%sfull_edge_%s.edge as %s,\n", selectclause,
              curr3->edge, curr3->edge);
      sprintf(targetlist, "%sfull_edge_%s.edge,\n", targetlist, curr3->edge);

      // generating other target list
      j = i;
      while (facelist[i]) {
        i--;
      }
      i = j;
      while (facelist[i] && strcmp(facelist[i], curr3->face1) != 0) {
        i--;
      }
      if (i == 0) {
        sprintf(selectclause, "%sfull_edge_%s.face1 as %s,\n", selectclause,
                curr3->edge, curr3->face1);
        sprintf(targetlist, "%sfull_edge_%s.face1,\n", targetlist, curr3->edge);
        facelist[++j] = malloc(sizeof(char) * 20);
        strcpy(facelist[j], curr3->face1);

        // if shape agg exists
        if (isshape) {
          tsi = si - 1;
          while (shapelist[tsi]) {
            if (strcmp(shapelist[tsi], curr3->face1) == 0) {
              sprintf(agglist,
                      "%sface_geometry_is('evaluate', full_edge_%s.face1, "
                      "2006) AND\n",
                      agglist, curr3->edge);
            }
            tsi--;
          }
        }
        // end shape
      }

      i = j;
      while (facelist[i] && strcmp(facelist[i], curr3->face2) != 0) {
        i--;
      }
      if (i == 0) {
        sprintf(selectclause, "%sfull_edge_%s.face2 as %s,\n", selectclause,
                curr3->edge, curr3->face2);
        sprintf(targetlist, "%sfull_edge_%s.face2,\n", targetlist, curr3->edge);
        facelist[++j] = malloc(sizeof(char) * 20);
        strcpy(facelist[j], curr3->face2);
        // shape
        if (isshape) {
          tsi = si - 1;
          while (shapelist[tsi]) {
            if (strcmp(shapelist[tsi], curr3->face2) == 0) {
              sprintf(agglist,
                      "%sface_geometry_is('evaluate', full_edge_%s.face2, "
                      "2006) AND\n",
                      agglist, curr3->edge);
            }
            tsi--;
          }
        }
        // end shape
      }
      i = j;
      // sprintf(targetlist,"%sfull_edge_%s,\n ",selectclause, curr3->edge);
      curr3 = curr3->next;
    }
    // generate shape agg functions
    ////////////////////////////////////////////////////////////////////////
    // predicates to keep all enities are distinct to each other 25/feb/2015
    char* face_internal[100];  // face entities internal representation, elg..,
                               // full_edge_e1.face1 = face1
    char* edge_internal[100];
    i = 0;
    int k = 0;
    // show triple relations , j always points to tail of the array
    curr3 = head3->next;

    while (curr3) {
      printf("list:%s %s %s\n", curr3->edge, curr3->face1, curr3->face2);
      // sprintf(selectclause,"%sfull_edge_%s.edge as %s,\n",selectclause,
      // curr3->edge, curr3->edge );
      // sprintf(targetlist,"%sfull_edge_%s,\n",targetlist, curr3->edge);

      edge_internal[++k] = malloc(sizeof(char) * 20);
      sprintf(edge_internal[k], "full_edge_%s.edge", curr3->edge);

      // generating other target list
      j = i;
      while (facelist[i]) {
        i--;
      }
      i = j;
      while (facelist[i] && strcmp(facelist[i], curr3->face1) != 0) {
        i--;
      }
      if (i == 0) {
        // sprintf(selectclause,"%sfull_edge_%s.face1 as %s,\n",selectclause,
        // curr3->edge, curr3->face1);
        // sprintf(targetlist,"%sfull_edge_%s.face1,\n",targetlist,
        // curr3->edge);
        ++j;
        facelist[j] = malloc(sizeof(char) * 20);
        face_internal[j] = malloc(sizeof(char) * 20);
        strcpy(facelist[j], curr3->face1);
        sprintf(face_internal[j], "full_edge_%s.face1", curr3->edge);
      }

      i = j;
      while (facelist[i] && strcmp(facelist[i], curr3->face2) != 0) {
        i--;
      }
      if (i == 0) {
        ++j;
        facelist[j] = malloc(sizeof(char) * 20);
        face_internal[j] = malloc(sizeof(char) * 20);
        strcpy(facelist[j], curr3->face2);
        sprintf(face_internal[j], "full_edge_%s.face2", curr3->edge);
      }
      i = j;
      // sprintf(targetlist,"%sfull_edge_%s,\n ",selectclause, curr3->edge);
      curr3 = curr3->next;
      //  printf("i=%d\n",i);
    }
    // generate shape agg functions
    while (face_internal[i]) {
      printf("all face internal %s i=%d \n", face_internal[i], i);
      i--;
    }
    i = 9;
    while (face_internal[i]) {
      printf("face internal %s\n", face_internal[i]);
      j = i - 1;
      while (face_internal[j]) {
        sprintf(cmd_unequal, "%s%s<>%s AND\n", cmd_unequal, face_internal[i],
                face_internal[j]);
        // sprintf(cmd_unequal,"%s%s<>%s AND\n",cmd_unequal,face_internal[j],
        // face_internal[i] );
        printf("%s<>%s AND\n", face_internal[i], face_internal[j]);
        j--;
      }
      i--;
    }
    while (edge_internal[k]) {
      //  printf("%s\n",edge_internal[k]);
      j = k - 1;
      while (edge_internal[j]) {
        sprintf(cmd_unequal, "%s%s<>%s AND\n", cmd_unequal, edge_internal[k],
                edge_internal[j]);
        j--;
      }
      k--;
    }

    // puts(cmd_unequal);

    ///
    ////////////////////////////////////////////////////////////////////////
    // create joined triple relation.

    list3 l3 = head3, templist3;

    l3 = l3->next;
    while (l3) {
      templist3 = l3;
      while (templist3) {
        if (strcmp(l3->face1, templist3->face1) == 0 &&
            strcmp(l3->face2, templist3->face2) != 0) {
          sprintf(cmd_bounds, "%sfull_edge_%s.face1=full_edge_%s.face1 AND \n",
                  cmd_bounds, l3->edge, templist3->edge);
        } else if (strcmp(l3->face1, templist3->face2) == 0 &&
                   strcmp(l3->face2, templist3->face1) != 0) {
          sprintf(cmd_bounds, "%sfull_edge_%s.face1=full_edge_%s.face2 AND \n",
                  cmd_bounds, l3->edge, templist3->edge);
        } else if (strcmp(l3->face1, templist3->face2) != 0 &&
                   strcmp(l3->face2, templist3->face1) == 0) {
          sprintf(cmd_bounds, "%sfull_edge_%s.face2=full_edge_%s.face1 AND \n",
                  cmd_bounds, l3->edge, templist3->edge);
        } else if (strcmp(l3->face1, templist3->face1) != 0 &&
                   strcmp(l3->face2, templist3->face2) == 0) {
          sprintf(cmd_bounds, "%sfull_edge_%s.face2=full_edge_%s.face2 AND \n",
                  cmd_bounds, l3->edge, templist3->edge);
        } else if (strcmp(l3->edge, templist3->edge) &&
                   strcmp(l3->face1, templist3->face1) == 0 &&
                   strcmp(l3->face2, templist3->face2) == 0) {
          sprintf(cmd_bounds, "%sfull_edge_%s.edge<>full_edge_%s.edge AND\n",
                  cmd_bounds, l3->edge, templist3->edge);
        } else if (strcmp(l3->edge, templist3->edge) &&
                   strcmp(l3->face1, templist3->face2) == 0 &&
                   strcmp(l3->face2, templist3->face1) == 0) {
          sprintf(cmd_bounds, "%sfull_edge_%s.edge<>full_edge_%s.edge AND\n",
                  cmd_bounds, l3->edge, templist3->edge);
        }
        templist3 = templist3->next;
      }

      l3 = l3->next;
    }
    //  printf("cmd_bounds\n%s\n",cmd_bounds);
    // ends bounds rewrite
  }

  ///////////////////////////////////////////////////////////////////////////////////////////////////////
  puts("Concate all query together");

  int full_edge_temp = full_edge_number;

  selectclause[strlen(selectclause) - 2] = '\0';

  full_edge_temp = full_edge_number;
  while (full_edge_temp) {
    sprintf(fromclause, "%sfull_edge full_edge_e%d,\n", fromclause,
            full_edge_temp);
    full_edge_temp--;
  }

  fromclause[strlen(fromclause) - 2] = '\0';
  // generate where clause

  sprintf(whereclause, "%s%s%s%s%s%s%s%s%s", whereclause, cmd_bounds,
          cmd_dihedral, cmd_equal, cmd_unequal, cmd_geom, cmd_maxarea,
          cmd_parallel, cmd_shape_face);

  whereclause[strlen(whereclause) - 4] = '\0';

  // generate final query
  if (isshape) {
    targetlist[strlen(targetlist) - 2] = '\0';
    sprintf(query, "%s%s%s\nGROUP BY\n%s\nHAVING\n%s", selectclause, fromclause,
            whereclause, targetlist, agglist);
    query[strlen(query) - 4] = '\0';
  } else
    sprintf(query, "%s%s%s;", selectclause, fromclause, whereclause);
  puts("QUERY:");
  puts(query);

  //////////////////////////////////////////////////////////
  fclose(fp);
  PG_RETURN_CSTRING(query);
  // PG_RETURN_INT32(0);
}