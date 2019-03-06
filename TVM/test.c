#include <stdio.h>
#include <stdlib.h>
#include "tvmAsm.h"

int main(void) {
	/* Файл для тестирования TVM */
	/* File for testing TVM */
	_MAIN
	$CRGA R11;
	$PRGA 123;
	$PRCA R11;
	_$DATA R15;
	_END
	_RUN
	printf("%d\t%d\t%d", reg[1][5], indxX, indxY);
	system("pause>nul");
	return 0;
}