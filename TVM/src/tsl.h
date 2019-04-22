#ifndef TSL_H_INCLUDED
#define TSL_H_INCLUDED

#include <stdio.h>
#include "stackLib.h"

/*
tsl.h v0.4
TVM resource library
22.04.2019
by Centrix
*/

#define MEMSIZE 1024 /* Размер памяти / Memory size */
#define end 3070 /* Указатель на конец программы / A pointer to the end of the program */
#define KEYERR -1
#define ISINT -2
#define ISCOM -3

unsigned int memory[MEMSIZE]; /* The memory of the machine */
unsigned int memIndx; /* Ячейка памяти в которую ведётся запись / The memory location to which the recording is
performed */
unsigned int cell; /* Указатель на читаемую ячейку памяти  / Pointer to a readable memory cell */
unsigned int cellOld; /* The cell is read prior to this */
unsigned int reg[8][8]; /* Регистры / Registers */
unsigned int indxX; /* Строка / Row */
unsigned int indxY; /* Столбец / Column */
int acc; /* Аккумулятор / Accumularor */
int kwcount = 43; /* Number of keywords and flags */
char filename[100]; /* Имя файла для записи */
FILE* code; /* Поток файла для записи */

int jump(int num); /* Позволяет использовать $JUMP / Allows you to use $JUMP */
int gotoMain(); /* Переходит к точке начала программы / Comes to the starting point of the program */
void memInter(); /* Интерпретатор / Interpreter */
void detcoor(int rtype); /* Определение адреса регистра с изменением indxX & indxY / Definition
						register address change indxX & indxY */
void detcoorv(int rtype, int* x, int* y); /* Определение адреса регистра / The definition of the address register */
void clear(int endpoint); /* Очищение памяти / Memory cleaning */
void ncpGen(); /* Функция генерирующая ncp файлы / Function generating ncp files */
int flen(char* name); /* Подсчёт символов в файле / Counting characters in a file */

enum commands { /* Список комманд / List of commands */
	nil = 0,
	CRG, /* Change ReGister - Выбрать регистр [1] */
	CRC, /* Change Register Cell [2] */
	PRG, /* Put in ReGister - положить данные в нулевую ячейку регистра [3] */
	PRC, /* Put Register Cell Положить данные в ячейку indxY регистра indxX [4] */
	GJP, /* Go to Jump Point инструкция аналогичная goto [5] */
	JPT, /* Jump PoinT метка для инструкции GJP [6] */
	DEB, /* DEBug выводит номер читаемой ячейки [7] */
	MAIN, /* Точка начала исполнения программы / The start point of program execution [8] */
	COM, /* Использование комманды / Using the command [9] */
	PUT, /* Простейший вывод / The simplest conclusion [10] */
	RESTART, /* Начало исполнения программы заново / Start of program execution again [11] */
	QUIT, /* Завершение работы программы / The completion of the program [12] */
	CLEAR, /* Очищение определённых ячеек памяти / Clearing specific memory locations [13] */
	ACCADD, /* Увиличение аккумулятора [14] */
	ACCSUBT, /* Уменьшение аккумулятора [15] */
	CMP, /* Сравнения значений в регистрах [16] */
	GOBACK, /* Возвращает интерпретатор в место вызова процедуры [17] */
	INPUT, /*  Простой ввод [18] */
	ACCMULT, /* Умножение аккумулятора [19] */
	ACCDIV /* Деление [20] */
};

enum flags { /* Список флагов / List of flags */
	STDI = 100, /* Стандартный флаг / Standard flag */
	STDA, /* Адресный флаг / Address flag */
	STDC, /* Флаг для символов */
	CWR, /* Char Without Register */
	VWR, /* Value Without Register */
	ALL, /* Флаг для _CLEAR / The _CLEAR flag for */
	ACC, /* Флаг для вывода значения аккумулятора как числа */
	CACC, /* Флаг для вывода значения аккумулятора как символа */
	STACK
};

enum ops {
	GZ = 400,
	GEZ,
	EZ,
	LZ,
	LEZ,
	INF
};

char* keys[] = {"nil", "crg", "crc", "prg", "prc", ".jump", ".point", ".deb", ".main", "com", "put", ".restart", ".quit", ".clear",\
"add", "subt", "cmp", ".goback", ".end", "input", "mult", "div", "push", "eject", "sum", "write", "_stdi", "_stda", "_stdc",\
"_cwr", "_vwr", "_all", "_acc", "_cacc", "_num", "_sym", "_stack", ">", ">=", "=", "<", "<=", "~"};
int values[] = {nil, CRG, CRC, PRG, PRC, GJP, JPT, DEB, MAIN, COM, PUT, RESTART, QUIT, CLEAR, ACCADD, ACCSUBT, CMP, GOBACK, end,\
INPUT, ACCMULT, ACCDIV, PUSH, EJECT, SUM, OUTPUT, STDI, STDA, STDC, CWR, VWR, ALL, ACC, CACC, NUM, SYM, STACK, GZ, GEZ, EZ, LZ,\
LEZ, INF};

#endif