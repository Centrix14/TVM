#include <stdio.h>
#include <stdlib.h>
#include "tvmAsm.h"

int main(void) {
	/* Файл для тестирования TVM */
	/* File for testing TVM */
	_MAIN
	$CRGA R10;
	$PRCI 12;
	$CRGA R11;
	$PRCI 10;
	$CMPA
		_$DATA R10;
		_$DATA R11;
		_$DATA R12;
	$PUTV R12;
	_END
	_RUN
	system("pause>nul");
	return 0;
}