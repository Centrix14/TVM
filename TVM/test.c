#include <stdio.h>
#include <stdlib.h>
#include "tvmAsm.h"

int main(void) {
	/* Файл для тестирования TVM */
	/* File for testing TVM */
	_MAIN
	$CRG
		_$STDI
		_$DATA 1;
	$CRC
		_$STDI
		_$DATA 0;
	$PRC
		_$STDI
		_$DATA 123;
	_END
	_toNCP("app.ncp")
	printf("%d\t%d\t%d", reg[1][5], indxX, indxY);
	system("pause>nul");
	return 0;
}