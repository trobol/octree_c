#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>

#define NOB_IMPLEMENTATION
#include "./src/nob.h"

const char* DEBUG_ARGS = "";
const char* SHIP_ARGS = "";
const char* DEBUG_ARGS_LINKER = "";
const char* SHIP_ARGS_LINKER = "";
const char* SHARED_ARGS = "-WAll -Fe\"build\\\" /out:build/octree.exe /pdb:build/octree.pdb";



char* cstrcat(char* a, char* b)
{
	const size_t a_len = strlen(a);
    const size_t b_len = strlen(b);
	char* out = malloc(a_len + b_len + 1);
	memcpy(out, a, a_len);
	memcpy(out+a_len, b, b_len);
	*(out+a_len+b_len) = '\0';
	return out;
}



int main( int argc, const char* argv[] ) 
{
	if (!nob_mkdir_if_not_exists("build")) return 1; // TODO: move this into nob.h
	NOB_GO_REBUILD_URSELF( argc, argv );

	Nob_Cmd cmd = {0};
	cmd.count = 0;
	// TODO: support other oses
	// TODO: support SHIP builds
	nob_cmd_append(&cmd, "cl", "/nologo"); 

	FOREACH_FILE_IN_DIR( sourcefile, "src", {
		if (ENDS_WITH(sourcefile, ".c")) {
			nob_log( NOB_INFO, "%s", sourcefile );
			nob_cmd_append(&cmd, cstrcat("src/", sourcefile));
		}
	});

	//nob_cmd_append(&cmd, "-Wall");
	//nob_cmd_append(&cmd, "/out:build/octree.exe");
	nob_cmd_append(&cmd, "-Febuild\\", "-Fobuild\\");


	nob_cmd_run_sync(cmd);
	
}