#include <stdio.h>
#include <stdlib.h>
#include "tvmAsm.h"

int main(void) {
	/* ���� ��� ������������ TVM */
	/* File for testing TVM */
	_MAIN
		$CRGA R20;
		$PRCI 65;
		$PUTC R20;
	_END
	_toNCP("exp.ncp")
	system("pause>nul");
	return 0;
}