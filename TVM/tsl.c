#include <stdio.h>
#include "tsl.h"

/*
TvmStandartLib v0.3.5
Главная библиотека TVM
25.03.2019
by Centrix
*/

int jump(int num) {
	for (int i = 0; i < MEMSIZE-1; i++) {
		if (memory[i] == num) {
			return i;
		}
	}
	return 0;
}

int gotoMain() {
	unsigned int i = 0;
	acc = 0;
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
	for (int i = 0; i < endpoint; i++) {
		memory[i] = nil;
	}
}

void memInter() {
	while (memory[cell] != end) {
		if (cell == 0) {
			cell = gotoMain();
		}
		switch (memory[cell])
		{
		case CRG: {
			if (memory[cell + 1] == STDI) {
				indxX = memory[cell + 2];
				cell += 2;
			}
			else if (memory[cell + 1] == STDA) {
				detcoor(memory[cell + 2]);
				cell += 2;
			}
			break;
		}
		case CRC: {
			if (memory[cell + 1] == STDI) {
				indxY = memory[cell + 2];
				cell += 2;
			}
			break;
		}
		case PRG: {
			if (memory[cell + 1] == STDI) {
				reg[indxX][0] = memory[cell + 2];
				cell += 2;
			}
			else if (memory[cell + 1] == STDA) {
				reg[indxX][indxY] = memory[cell + 2];
			}
			break;
		}
		case PRC: {
			if (memory[cell + 1] == STDI) {
				reg[indxX][indxY] = memory[cell + 2];
				cell += 2;
			}
			else if (memory[cell + 1] == STDA) {
				int r1x, r1y, r2x, r2y;
				detcoorv(memory[cell + 2], &r1x, &r1y);
				detcoorv(memory[cell + 3], &r2x, &r2y);
				reg[r2x][r2y] = reg[r1x][r1y];
				cell++;
			}
			break;
		}
		case GJP: {
			if (memory[cell + 1] != nil && memory[cell + 2] > nil) {
				cellOld = cell;
				cell = jump(memory[cell + 1]);
				--cell;
			}
			break;
		}
		case PUT: {
			int tmp1, tmp2;
			detcoorv(memory[cell + 2], &tmp1, &tmp2);

			switch (memory[cell + 1]) {
			case STDI: {
				printf("%d", reg[tmp1][tmp2]);
				cell += 2;
				break;
			}

			case STDC: {
				printf("%c", reg[tmp1][tmp2]);
				cell += 2;
				break;
			}

			case CWR: {
				printf("%c", memory[cell + 2]);
				cell += 2;
				break;
			}

			case VWR: {
				printf("%d", memory[cell + 2]);
				cell += 2;
				break;
			}
			case ACC: {
				printf("%d", acc);
				cell++;
				break;
			}
			case CACC: {
				printf("%c", acc);
				cell++;
				break;
			}
			}
			break;
		}
		case DEB: {
			printf("%d\n", cell);
			break;
		}
		case RESTART: {
			cell = 0;
			break;
		}
		case QUIT: {
			memory[cell] = end;
			--cell;
			break;
		}
		case CLEAR: {
			if (memory[cell + 1] == ALL) {
				clear(cell);
			}
			else {
				memory[memory[cell + 1]] = nil;
			}
			break;
		}
		case ACCADD: {
			if (memory[cell + 1] == STDI) {
				acc++;
			}
			else if (memory[cell + 1] == STDA) {
				int tmp1, tmp2;
				detcoorv(memory[cell + 2], &tmp1, &tmp2);
				acc += reg[tmp1][tmp2];
				cell += 2;
			}
			break;
		}
		case ACCSUBT: {
			if (memory[cell + 1] == STDI) {
				acc--;
			}
			else if (memory[cell + 1] == STDA) {
				int tmp1, tmp2;
				detcoorv(memory[cell + 2], &tmp1, &tmp2);
				acc -= reg[tmp1][tmp2];
				cell += 2;
			}
			break;
		}
		case CMP: {
			if (memory[cell + 1] == STDA) {
				int tmp1, tmp2, tmp3, tmp4;
				auto int ansX, ansY;
				detcoorv(memory[cell + 2], &tmp1, &tmp2);
				detcoorv(memory[cell + 3], &tmp3, &tmp4);
				detcoorv(memory[cell + 4], &ansX, &ansY);
				reg[ansX][ansY] = reg[tmp1][tmp2] - reg[tmp3][tmp4];
				cell += 4;
			}
			else if (memory[cell + 1] == STDI) {
				int val1 = memory[cell + 2], val2 = memory[cell + 3];
				int ansX, ansY;
				detcoorv(memory[cell + 4], &ansX, &ansY);
				reg[ansX][ansY] = val1 - val2;
				cell += 4;
			}
			break;
		}
		case GOBACK: {
			cell = cellOld + 1;
			break;
		}
		case INPUT: {
			int tmp1, tmp2;
			detcoorv(memory[cell + 2], &tmp1, &tmp2);
			switch (memory[cell + 1]) {
				case STDI: {
					scanf("%d", &reg[tmp1][tmp2]);
					cell += 2;
					break;
				}
				case STDC: {
					scanf("%c", &reg[tmp1][tmp2]);
					cell += 2;
					break;
				}
				case ACC: {
					scanf("%d", &acc);
					cell++;
					break;
				}
				case CACC: {
					scanf("%c", &acc);
					cell++;
					break;
				}
			}
			break;
		}
		}
		cell++;
	}
}