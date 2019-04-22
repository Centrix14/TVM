#include <stdio.h>
#include "tsl.h"
#include "stackLib.h"

/*
TvmStandartLib v0.4
Basic TVM library
22.04.2019
by Centrix
*/

#define JMP_PROC {cellOld = cell;} {cell = jump(memory[cell + 3]);} {--cell;}

int jump(int num) {
	for (int i = 0; i < MEMSIZE-1; i++) {
		if (memory[i] == JPT && memory[i+1] == num) {
			return i;
		}
	}
	printf("Warning: the %d mark is not detected\n", num);
	return 1;
}

int gotoMain() {
	unsigned int i = 0;
	acc = 0;
	for (int i = 0; i < MEMSIZE-1; i++) {
		if (memory[i] == MAIN) {
			return i;
		}
	}
	printf("Critical error: directive not found .main\n");
	return 1;
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
			switch (memory[cell + 1]) {
				case STDI: {
					indxX = memory[cell + 2];
					cell += 2;
					break;
				}
				case STDA: {
					detcoor(memory[cell + 2]);
					cell += 2;
					break;
				}
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
			switch (memory[cell + 1]) {
				case STDI: {
					reg[indxX][0] = memory[cell + 2];
					cell += 2;
					break;
				}
				case STDA: {
					reg[indxX][indxY] = memory[cell + 2];
					break;
				}
			}
			break;
		}
		case PRC: {
			switch (memory[cell + 1]) {
				case STDI: {
					reg[indxX][indxY] = memory[cell + 2];
					cell += 2;
					break;
				}
				case STDA: {
					int r1x, r1y, r2x, r2y;
					detcoorv(memory[cell + 2], &r1x, &r1y);
					detcoorv(memory[cell + 3], &r2x, &r2y);
					reg[r2x][r2y] = reg[r1x][r1y];
					cell += 3;
					break;
				}
				case ACC: {
					if (memory[cell + 2] == STACK) {
						acc = stack[STACKSIZE-busyNum+1];
					}
					break;
				}
				case STACK: {
					if (memory[cell + 2] == ACC) {
						stack[STACKSIZE-busyNum+1] = acc;
					} 
					break;
				}
			}
			break;
		}
		case GJP: {
			int value = 0;

			switch (memory[cell + 2]) {
				case STACK: {
					value = stack[STACKSIZE-busyNum+1];
					break;
				}
				case ACC: {
					value = acc;
					break;
				}
				default: {
					int x, y;
					detcoorv(memory[cell + 2], &x, &y);
					value = reg[x][y];
					break;
				}
			}

			switch (memory[cell + 1]) {
				case GZ: {
					if (value > nil) {
						JMP_PROC
					}
					break;
				}
				case GEZ: {
					if (value >= nil) {
						JMP_PROC
					}
					break;
				}
				case EZ: {
					if (value == nil) {
						JMP_PROC
					}
					break;
				}
				case LZ: {
					if (value < nil) {
						JMP_PROC
					}
					break;
				}
				case LEZ: {
					if (value <= nil) {
						JMP_PROC
					}
					break;
				}
				case INF: {
					cellOld = cell;
					cell = jump(memory[cell + 2]);
					--cell;
					break;
				}
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
				printf("%d ", acc);
				cell++;
				break;
			}
			case CACC: {
				printf("%c ", acc);
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
			switch (memory[cell + 1]) {
				case STDI: {
					acc++;
					break;
				}
				case STDA: {
					int tmp1, tmp2;
					detcoorv(memory[cell + 2], &tmp1, &tmp2);
					acc += reg[tmp1][tmp2];
					cell += 2;
					break;
				}
				case VWR: {
					acc += memory[cell + 2];
					cell += 2;
					break;
				}
			}
			break;
		}
		case ACCSUBT: {
			switch (memory[cell + 1]) {
				case STDI: {
					acc--;
					break;
				}
				case STDA: {
					int tmp1, tmp2;
					detcoorv(memory[cell + 2], &tmp1, &tmp2);
					acc -= reg[tmp1][tmp2];
					cell += 2;
					break;
				}
				case VWR: {
					acc -= memory[cell + 2];
					cell += 2;
					break;
				}
			}
			break;
		}
		case CMP: {
			int r1X, r1Y, r2X, r2Y;
			int val1, val2;

			detcoorv(memory[cell + 2], &r1X, &r1Y);
			detcoorv(memory[cell + 3], &r2X, &r2Y);

			val1 = reg[r1X][r1Y];
			val2 = reg[r2X][r2Y];

			switch (memory[cell + 1]) {
				case ACC: {
					acc = val1 - val2;
					cell += 3;
					break;
				}
				case STACK: {
					stack[STACKSIZE-busyNum+1] = val1 - val2;
					cell += 3;
					break;
				}
				default: {
					int ansX, ansY;
					detcoorv(memory[cell + 1], &ansX, &ansY);
					reg[ansX][ansY] = val1 - val2;
					cell += 3;
					break;
				}
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
		case ACCMULT: {
			switch (memory[cell + 1]) {
				case STDA: {
					int tmp1, tmp2;
					detcoorv(memory[cell + 2], &tmp1, &tmp2);
					acc *= reg[tmp1][tmp2];
					cell += 2;
					break;
				}
				case VWR: {
					acc *= memory[cell + 2];
					cell += 2;
					break;
				}
			}
			break;
		}
		case ACCDIV: {
			switch (memory[cell + 1]) {
				case STDA: {
					int tmp1, tmp2;
					detcoorv(memory[cell + 2], &tmp1, &tmp2);
					acc *= reg[tmp1][tmp2];
					cell += 2;
					break;
				}
				case VWR: {
					acc /= memory[cell + 2];
					cell += 2;
					break;
				}
			}
		}
		case PUSH: {
			stack[STACKSIZE-(busyNum++)] = memory[cell+1];
			break;
		}
		case EJECT: {
			stack[STACKSIZE-busyNum] = nil;
			busyNum--;
			break;
		}
		case SUM: {
			int sum = 0;
			for (int i = 0; i < STACKSIZE; i++) {
				sum += stack[STACKSIZE-i];
				stack[STACKSIZE-i] = nil;
			}
			stack[STACKSIZE] = sum;
			break;
		}
		case OUTPUT: {
			switch (memory[cell+1]) {
				case NUM: {
					printf("%d", stack[STACKSIZE-(busyNum-1)]);
					break;
				}
				case SYM: {
					printf("%c", stack[STACKSIZE-(busyNum-1)]);
					break;
				}
			}
			break;
		}
		}
		cell++;
	}
}