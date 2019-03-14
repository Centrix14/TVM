#include <stdio.h>
#include "tsl.h"

/*
NcpGenLib.c v0.3.2
��������� ������� ��������� � �������������� .ncp ������
10.03.2019
by Centrix
*/

void ncpGen() {
	code = fopen(filename, "w");
	int i = 0;

	if (code != NULL) {
		while (memory[i] != end) {
			switch (memory[i])
			{
			case CRG:
				if (memory[i + 1] == STDI) {
					fprintf(code, "%d %d ", CRG, STDI);
					i++;
				}
				else if (memory[i + 1] == STDA) {
					fprintf(code, "%d %d %d ", CRG, STDA, memory[i + 2]);
				}
				break;
			case CRC:
				if (memory[i + 1] == STDI) {
					fprintf(code, "%d %d ", CRC, STDI);
					i++;
				}
				break;
			case PRG:
				if (memory[i + 1] == STDI) {
					fprintf(code, "%d %d ", PRG, STDI);
					i++;
				}
				else if (memory[i + 1] == STDA) {
					fprintf(code, "%d %d %d ", PRG, STDA, memory[i + 2]);
				}
				break;
			case PRC:
				if (memory[i + 1] == STDI) {
					fprintf(code, "%d %d %d ", PRC, STDI, memory[i + 2]);
					i++;
				}
				else if (memory[i + 1] == STDA) {
					fprintf(code, "%d %d %d %d ", PRC, STDA, memory[i + 2], memory[i + 3]);
				}
				break;
			case GJP:
				if (memory[i + 1] != nil && memory[i + 2] > nil) {
					fprintf(code, "%d %d %d ", GJP, memory[i + 1], memory[i + 2]);
					i--;
				}
				break;
			case JPT:
				if (memory[i + 1] > nil) {
					fprintf(code, "%d %d ", JPT, memory[i + 1]);
					i++;
				}
				break;
			case DEB:
				fprintf(code, "%d ", DEB);
				break;
			case MAIN:
				fprintf(code, "%d ", MAIN);
				break;
			case COM:
				fprintf(code, "%d %d ", COM, memory[i + 1]);
				break;
			case PUT:
				//fprintf(code, "%d %d %d ", PUT, memory[i + 1], memory[i + 2]);
				if (memory[i + 1] == STDI || memory[i + 1] == STDC || memory[i + 1] == CWR || memory[i + 1] == VWR) {
					fprintf(code, "%d %d %d ", PUT, memory[i + 1], memory[i + 2]);
				}
				else if (memory[i + 1] == ACC) {
					fprintf(code, "%d %d ", PUT, ACC);
					i++;
				}
				break;
			case RESTART:
				fprintf(code, "%d %d ", RESTART, memory[i + 1]);
				break;
			case QUIT:
				fprintf(code, "%d ", QUIT);
				break;
			case CLEAR:
				fprintf(code, "%d %d ", CLEAR, memory[cell + 1]);
				break;
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