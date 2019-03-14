#include <stdio.h>
#include <stdlib.h>
#include "tvmAsm.h"

int main(void) {
	/* Файл для тестирования TVM */
	/* File for testing TVM */
	_MAIN
	$ADDI
	$PUTA
	_END
	_RUN
	_toNCP("app.ncp")
	system("pause>nul");
	return 0;
}