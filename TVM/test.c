#include <stdio.h>
#include <stdlib.h>
#include "tvmAsm.h"

int main(void) {
	/* Файл для тестирования TVM */
	/* File for testing TVM */
	_POINT 1;
	$PUTCWR 65;
	_GOBACK
	_MAIN
	$JUMP 1;
	_$COND 1;
	_END
	_toNCP("app1.ncp")
	system("pause>nul");
	return 0;
}