#ifndef NCPGEN_H_INCLUDED
#define NCPGEN_H_INCLUDED

/*
ncpgen.h v0.1
���������� ��� �������� ncp ������ / Library for creating ncp files
03.03.2019
by Centrix
*/

#include "tvmlib.h"
#include <stdio.h>

FILE* code;
char filename[100];

void ncpGen(); /* ������� ������������ ncp ����� / Function generating ncp files */

void ncpGen() {
	code = fopen(filename, "w");
	int i = 0;

	if (code != NULL) {
		while (memory[i] != end) {
			if (memory[i] == CRG && memory[i + 1] == STDI) {
				fprintf(code, "%d %d ", CRG, STDI);
				i++;
			}
			else if (memory[i] == CRC && memory[i + 1] == STDI) {
				fprintf(code, "%d %d ", CRC, STDI);
				i++;
			}
			else if (memory[i] == PRG && memory[i + 1] == STDI) {
				fprintf(code, "%d %d ", PRG, STDI);
				i++;
			}
			else if (memory[i] == PRC && memory[i + 1] == STDI) {
				fprintf(code, "%d %d ", PRC, STDI);
				i++;
			}
			else if (memory[i] == GJP && memory[i + 1] != nil && memory[i + 2] > nil) {
				fprintf(code, "%d %d %d ", GJP, memory[i + 1], memory[i + 2]);
				i--;
			}
			else if (memory[i] == DEB) {
				fprintf(code, "%d ", DEB);
			}
			else if (memory[i] == MAIN) {
				fprintf(code, "%d ", MAIN);
			}
			else if (memory[i] == COM) {
				fprintf(code, "%d %d ", COM, memory[i + 1]);
			}
			i++;
		}
		fprintf(code, "%d", end);
	}
	else {
		perror("Fail");
	}
	fclose(code);
}

#endif // NCPGEN_H_INCLUDED

