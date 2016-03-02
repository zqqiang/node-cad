# contrib/cadfix/Makefile

MODULE_big = cadfix

OBJS =  cadfix.o $(WIN32RES)

EXTENSION = cadfix

ifdef USE_PGXS
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
else
subdir = contrib/cadfix
top_builddir = ../..
include $(top_builddir)/src/Makefile.global
include $(top_srcdir)/contrib/contrib-global.mk
endif