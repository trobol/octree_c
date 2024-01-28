#include "using.h"


#ifdef _WIN32
#define PLATFORM_WIN32 IN_USE
#else 
#define PLATFORM_WIN32 NOT_IN_USE
#endif

#define PLATFORM_OPENGL IN_USE