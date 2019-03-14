#include <stdio.h>
#include <stdlib.h>
#include "tvmAsm.h"

int main(void) {
	/* Файл для тестирования TVM */
	/* File for testing TVM */
	_MAIN
	$CRGA R10;
	$PRCI 123;
	$ADDA R10;
	$PUTA
	_END
	_RUN
	system("pause>nul");
	return 0;
}