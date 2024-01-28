#include "platform_defines.h"


#if USING(PLATFORM_OPENGL)
#define SOKOL_GLCORE33
#endif

#define SOKOL_IMPL
#include "sokol_gfx.h"
#include "sokol_app.h"
#include "sokol_log.h"
#include "sokol_glue.h"
