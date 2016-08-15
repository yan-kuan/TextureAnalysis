#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h> ///< define "pid_t"
#include <sys/wait.h>

#include "debug.h"

typedef unsigned long long lint;///< avoid the 

typedef struct clink *plink;
typedef struct instr *pinstr;

typedef struct clink{
	lint call; ///< calls maybe overflow
	plink next;
}clink;

typedef struct instr{
	char* name;
	unsigned int count;
	plink calls;
	plink last;
}instr;


pinstr new_instr( char* instrName);

pinstr append_instr( pinstr hNode, long call);

void apitrace_dump( char *tracef);
