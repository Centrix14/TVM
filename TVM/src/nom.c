#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "tsl.h"

/*
nom compiler v0.5 BETA
06.03.2019
by Centrix
*/

#define KEYERR -1
#define ISINT -2
#define ISCOM -3

char* keys[] = {"nil", "crg", "crc", "prg", "prc", ".jump", ".point", ".deb", ".main", "com", "put", ".restart", ".quit", ".clear",\
"add", "subt", "cmp", ".goback", ".end", "input", "mult", "div", ".else", "push", "eject", "sum", "write", "_stdi", "_stda", "_stdc",\
"_cwr", "_vwr", "_all", "_acc", "_cacc", "_num", "_sym"};
int values[] = {nil, CRG, CRC, PRG, PRC, GJP, JPT, DEB, MAIN, COM, PUT, RESTART, QUIT, CLEAR, ACCADD, ACCSUBT, CMP, GOBACK, end,\
INPUT, ACCMULT, ACCDIV, ELSE, PUSH, EJECT, SUM, OUTPUT, STDI, STDA, STDC, CWR, VWR, ALL, ACC, CACC, NUM, SYM};
int buff[MEMSIZE];
int cursor = 0;
int kwcount = 40;
int codelen = 0;
int com = 0;

int find(char* word) {
	if (strstr(word, "*") != NULL && com == 0) { com = 1; }
	else if (strstr(word, "*") != NULL && com == 1) { com = 0; return ISCOM; }

	for (int i = 0; i < kwcount; i++) {
		if (strcmp(keys[i], word) == 0) {
			return i;
		}
		else if (isdigit(word[0]) == 1) {
			return ISINT;
		}
		else if (com == 1) { return ISCOM; }
	}
	return KEYERR;
}

void install(char* word) {
	int indx = find(word);

	if (com == 1 && indx == ISCOM) { return; }

	if (indx >= 0) {
		buff[cursor++] = values[indx];
	}

	else {
		if (indx == KEYERR) {
			printf("Critical error: Unrecognized expression:\n%s\n", word);
			exit(0);
		}
		else {
			buff[cursor++] = atoi(word);
		}
	}
}

void write(char* str, char* name) {
	FILE* file = fopen(name, "w");
	char* token = strtok(str, " ");

	if (file == NULL) { perror("Fail"); exit(0); }

	while (token != NULL) {
		install(token);
		token = strtok(NULL, " ");
		codelen++;
	}
	
	for (int i = 0; i < codelen; i++) {
		fprintf(file, "%d ", buff[i]);
	}
	fclose(file);
}

int main(int argc, char* argv[]) {
	FILE* resource = fopen(argv[1], "r");
	char line[100];

	if (resource == NULL) { perror("Fail"); exit(0); }

	while (!feof(resource)) {
		fscanf(resource, "%s", line);
		write(line, argv[2]);
	}

	perror("Errors");
	fclose(resource);
	return 0;
}