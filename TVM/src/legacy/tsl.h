#ifndef TSL_H_INCLUDED
#define TSL_H_INCLUDED

#include <stdio.h>

/*
tsl.h v0.3.8
Объявляет ресурсы для tsl.c
31.03.2019
by Centrix
*/

#define MEMSIZE 1024 /* Размер памяти / Memory size */
#define end 3070 /* Указатель на конец программы / A pointer to the end of the program */

unsigned int memory[MEMSIZE];
unsigned int memIndx; /* Ячейка памяти в которую ведётся запись / The memory location to which the recording is
performed */
unsigned int cell; /* Указатель на читаемую ячейку памяти  / Pointer to a readable memory cell */
unsigned int cellOld;
unsigned int reg[8][8]; /* Регистры / Registers */
unsigned int indxX; /* Строка / Row */
unsigned int indxY; /* Столбец / Column */
int acc; /* Аккумулятор / Accumularor */
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
	ACCDIV, /* Деление [20] */
	ELSE
};

enum flags { /* Список флагов / List of flags */
	STDI = 100, /* Стандартный флаг / Standard flag */
	STDA, /* Адресный флаг / Address flag */
	STDC, /* Флаг для символов */
	CWR, /* Char Without Register */
	VWR, /* Value Without Register */
	ALL, /* Флаг для _CLEAR / The _CLEAR flag for */
	ACC, /* Флаг для вывода значения аккумулятора как числа */
	CACC /* Флаг для вывода значения аккумулятора как символа */
};

enum Regs { /* Список всех регистров / List of all registers */
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

#endif