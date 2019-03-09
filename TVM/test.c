#include <stdio.h>
#include <stdlib.h>
#include "tvmAsm.h"

int main(void) {
	/* Файл для тестирования TVM */
	/* File for testing TVM */
	_MAIN
		$CRGA R10;
		$PRCI 123;
		$PRGA R11;
		_$DATA R10;
	_END
	_RUN
	printf("%d", reg[1][1]);
	system("pause>nul");
	return 0;
}