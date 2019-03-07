#ifndef TVMLIB_H_INCLUDED
#define TVMLIB_H_INCLUDED

/*
tvmlib.h v0.3
�������� ���������� TVM / Basic TVM library
07.03.2019
by Centrix
*/

#define MEMSIZE 1024 /* ������ ������ / Memory size */
#define end 3070 /* ��������� �� ����� ��������� / A pointer to the end of the program */
unsigned int memory[MEMSIZE]; /* ������ / Memory */

unsigned int cell; /* ��������� �� �������� ������ ������  / Pointer to a readable memory cell */
unsigned int reg[8][8]; /* �������� / Registers */
unsigned int indxX = 0; /* ������ / Row */
unsigned int indxY = 0; /* ������� / Column */
unsigned short int nil = 0; /* ���� ��� ���������� ���� - ���� / Zero or the absence of something */

int jump(int num); /* ��������� ������������ $JUMP / Allows you to use $JUMP */
int gotoMain(); /* ��������� � ����� ������ ��������� / Comes to the starting point of the program */
void memInter(); /* ������������� / Interpreter */

enum commands { /* ������ ������� / List of commands */
	CRG = 1, /* Change ReGister - ������� ������� [1] */
	CRC, /* Change Register Cell [2] */
	PRG, /* Put in ReGister - �������� ������ � ������� ������ �������� [3] */
	PRC, /* Put Register Cell �������� ������ � ������ indxY �������� indxX [4] */
	GJP, /* Go to Jump Point ���������� ����������� goto [5] */
	JPT, /* Jump PoinT ����� ��� ���������� GJP [6] */
	DEB, /* DEBug ������� ����� �������� ������ [7] */
	MAIN, /* ����� ������ ���������� ��������� / The start point of program execution [8] */
	COM, /* ������������� �������� / Using the command [9] */
	PUT, /* ���������� ����� */
	RESTART, /* ������ ���������� ��������� ������ */
	QUIT, /* ���������� ������ ��������� */
	CLEAR /* �������� ����������� ����� ������ */
};

enum flags { /* ������ ������ / List of flags */
	STDI = 1, /* ����������� ���� / Standard flag */
	STDA,
	ALL
};

enum Regs /* ������ ���� ��������� */
{
	R10 = 10,
	R11,
	R12,
	R13, 
	R14, 
	R15,
	R16, 
	R17,
	R18,
	R20 = 20,
	R21,
	R22,
	R23,
	R24,
	R25,
	R26,
	R27,
	R28,
	R30 = 30,
	R31,
	R32,
	R33,
	R34,
	R35,
	R36,
	R37,
	R38,
	R40 = 40,
	R41,
	R42,
	R43,
	R44,
	R45,
	R46,
	R47,
	R48,
	R50 = 50,
	R51,
	R52,
	R53,
	R54,
	R55,
	R56,
	R57,
	R58,
	R60 = 60,
	R61,
	R62,
	R63,
	R64,
	R65,
	R66,
	R67,
	R68,
	R70 = 70,
	R71,
	R72,
	R73,
	R74,
	R75,
	R76,
	R77,
	R78,
	R80 = 80,
	R81,
	R82,
	R83,
	R84,
	R85,
	R86,
	R87,
	R88
};

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
	while (cell != end) {
		if (cell == 0) {
			cell = gotoMain();
		}
		if (memory[cell] == CRG && memory[cell + 1] == STDI) {
			indxX = memory[cell + 2];
			cell++;
		}
		else if (memory[cell] == CRC && memory[cell + 1] == STDI) {
			indxY = memory[cell + 2];
			cell++;
		}
		else if (memory[cell] == PRG && memory[cell + 1] == STDI) {
			reg[indxX][0] = memory[cell + 2];
			cell++;
		}
		else if (memory[cell] == PRC && memory[cell + 1] == STDI) {
			reg[indxX][indxY] = memory[cell + 2];
			cell++;
		}
		else if (memory[cell] == GJP && memory[cell + 1] != nil && memory[cell + 2] > nil) {
			cell = jump(memory[cell + 1]);
			cell--;
		}
		else if (memory[cell] == CRG && memory[cell + 1] == STDA) {
			detcoor(memory[cell + 2]);
		}
		else if (memory[cell] == PRG && memory[cell + 1] == STDA) {
			reg[indxX][indxY] = memory[cell + 2];
		}
		else if (memory[cell] == PRC && memory[cell + 1] == STDA) {
			int r1x, r1y, r2x, r2y;
			detcoorv(memory[cell + 2], &r1x, &r1y);
			detcoorv(memory[cell + 3], &r2x, &r2y);
			reg[r2x][r2y] = reg[r1x][r1y];
		}
		else if (memory[cell] == PUT) {
			printf("%d ", memory[cell + 1]);
		}
		else if (memory[cell] == DEB) {
			printf("%d\n", cell);
		}
		else if (memory[cell] == RESTART) {
			cell = 0;
		}
		else if (memory[cell] == QUIT) {
			memory[cell] = end;
			cell--;
		}
		else if (memory[cell] == CLEAR) {
			if (memory[cell + 1] == ALL) {
				clear(memory[cell]);
			}
			else {
				memory[memory[cell + 1]] = nil;
			}
		}
		cell++;
	}
}

#endif // TVMLIB_H_INCLUDED
