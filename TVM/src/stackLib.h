#ifndef STACKLIB_H_INCLUDED
#define STACKLIB_H_INCLUDED

/* 
stackLib.h v0.6
Library for working with stack
10.05.2019
by Centrix
*/

#include "tsl.h"

#define STACKSIZE 1024 /* Specifies the stack size - Определяет размер стека */

int stack[STACKSIZE]; /* Stack - стек */
int busyNum = 0; /* The number of occupied cells in a stack */
int addrIndx = STACKSIZE; /* The index of the cell stack */
int memCount = 0;

enum moves { /* Stack commands */
	PUSH = 200,
	EJECT
};

#endif