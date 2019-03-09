#include "main.h"
#include <stdio.h>

/*
TvmStandartLib v0.1
Реализует функции из tvmLib.h
08.03.2019
by Centrix
*/

int jump(int num) {
	unsigned int i = 0;
	while (memory[i] != end) {
		if (memory[i] == num) {
			return i;
		}
		i++;
	}
	return 0;
}

int gotoMain() {
	unsigned int i = 0;
	while (memory[i] != MAIN) {
		i++;
	}
	return i;
}

void detcoor(int rtype) {
	indxX = rtype / 10;
	indxY = rtype % 10;
}

void detcoorv(int rtype, int* x, int* y) {
	*x = rtype / 10;
	*y = rtype % 10;
}

void clear(int endpoint) {
	int i = 0;
	while (i != endpoint) {
		memory[i] = nil;
	}
}

void memInter() {
	while (memory[cell] != end) {
		switch (memory[cell])
		{
		case nil:
			cell = gotoMain();
			break;
		case CRG:
			if (memory[cell + 1] == STDI) {
				indxX = memory[cell + 2];
				cell++;
			}
			else if (memory[cell + 1] == STDA) {
				detcoor(memory[cell + 2]);
			}
			break;
		case CRC:
			if (memory[cell + 1] == STDI) {
				indxY = memory[cell + 2];
				cell++;
			}
			break;
		case PRG:
			if (memory[cell + 1] == STDI) {
				reg[indxX][0] = memory[cell + 2];
				cell++;
			}
			else if (memory[cell + 1] == STDA) {
				reg[indxX][indxY] = memory[cell + 2];
			}
			break;
		case PRC:
			if (memory[cell + 1] == STDI) {
				reg[indxX][indxY] = memory[cell + 2];
				cell++;
			}
			else if (memory[cell + 1] == STDA) {
				int r1x, r1y, r2x, r2y;
				detcoorv(memory[cell + 2], &r1x, &r1y);
				detcoorv(memory[cell + 3], &r2x, &r2y);
				reg[r2x][r2y] = reg[r1x][r1y];
			}
			break;
		case GJP:
			if (memory[cell + 1] != nil && memory[cell + 2] > nil) {
				cell = jump(memory[cell + 1]);
				cell--;
			}
			break;
		case PUT:
			printf("%d ", memory[cell + 1]);
			break;
		case DEB:
			printf("%d\n", cell);
			break;
		case RESTART:
			cell = 0;
			break;
		case QUIT:
			memory[cell] = end;
			cell--;
			break;
		case CLEAR:
			if (memory[cell + 1] == ALL) {
				clear(memory[cell]);
			}
			else {
				memory[memory[cell + 1]] = nil;
			}
			break;
		}
		cell++;
	}
}