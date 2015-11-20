/****************************************************************
**
**  File: oce_install_config.h.cmake, oce-config.h
**
**  This configuration header is installed with OCE headers.
**  It should NOT be used while building OCE.  It defines
**  a subset of the macros configured by CMake. This subset is
**  used by the installed OCE headers.
**
****************************************************************/


/* #undef MACOSX_USE_GLX */

/* #undef OCE_HAVE_ATOMIC_H */

#define OCE_IS_DUPLICATE_UINT32_T

#define OCC_VERSION_DEVELOPMENT "oce-0.17-dev"

