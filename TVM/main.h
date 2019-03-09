#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>

/*
main.h v0.1
������� ����������� TVM
08.03.2019
by Centrix
*/

#define MEMSIZE 1024 /* ������ ������ / Memory size */
#define end 3070 /* ��������� �� ����� ��������� / A pointer to the end of the program */
unsigned int memory[MEMSIZE]; /* ������ / Memory */

unsigned int memIndx = 0; /* ������ ������ � ������� ������ ������ / The memory location to which the recording is
performed */
unsigned int cell; /* ��������� �� �������� ������ ������  / Pointer to a readable memory cell */
unsigned int reg[8][8]; /* �������� / Registers */
unsigned int indxX = 0; /* ������ / Row */
unsigned int indxY = 0; /* ������� / Column */
char filename[100]; /* ��� ����� ��� ������ */
FILE* code; /* ����� ����� ��� ������ */

int jump(int num); /* ��������� ������������ $JUMP / Allows you to use $JUMP */
int gotoMain(); /* ��������� � ����� ������ ��������� / Comes to the starting point of the program */
void memInter(); /* ������������� / Interpreter */
void detcoor(int rtype); /* ����������� ������ �������� � ���������� indxX & indxY / Definition
						register address change indxX & indxY */
void detcoorv(int rtype, int* x, int* y); /* ����������� ������ �������� / The definition of the address register */
void clear(int endpoint); /* �������� ������ / Memory cleaning */
void ncpGen(); /* ������� ������������ ncp ����� / Function generating ncp files */
int flen(char* name); /* ������� �������� � ����� / Counting characters in a file */

enum commands { /* ������ ������� / List of commands */
	nil = 0,
	CRG, /* Change ReGister - ������� ������� [1] */
	CRC, /* Change Register Cell [2] */
	PRG, /* Put in ReGister - �������� ������ � ������� ������ �������� [3] */
	PRC, /* Put Register Cell �������� ������ � ������ indxY �������� indxX [4] */
	GJP, /* Go to Jump Point ���������� ����������� goto [5] */
	JPT, /* Jump PoinT ����� ��� ���������� GJP [6] */
	DEB, /* DEBug ������� ����� �������� ������ [7] */
	MAIN, /* ����� ������ ���������� ��������� / The start point of program execution [8] */
	COM, /* ������������� �������� / Using the command [9] */
	PUT, /* ���������� ����� / The simplest conclusion [10] */
	RESTART, /* ������ ���������� ��������� ������ / Start of program execution again [11] */
	QUIT, /* ���������� ������ ��������� / The completion of the program [12] */
	CLEAR /* �������� ����������� ����� ������ / Clearing specific memory locations [13] */
};

enum flags { /* ������ ������ / List of flags */
	STDI = 1, /* ����������� ���� / Standard flag */
	STDA, /* �������� ���� / Address flag */
	ALL /* ���� ��� _CLEAR / The _CLEAR flag for */
};

enum Regs /* ������ ���� ��������� / List of all registers */
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

#endif // !MAIN_H_INCLUDED

