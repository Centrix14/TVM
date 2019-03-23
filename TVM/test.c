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
	/*$CRGA R10;
	$PRCI 12;
	$CRGA R11;
	$PRCI 11;
	$CMPA
		_$DATA R10;
		_$DATA R11;
		_$DATA R12;
	$PUTV R12;
	$CMPWR
		_$DATA 9;
		_$DATA 2;
		_$DATA R10;
	$PUTV R10;*/
	$JUMP 1;
	_$COND 1;
	_END
	_toNCP("app1.ncp")
	system("pause>nul");
	return 0;
}