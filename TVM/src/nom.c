#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "tsl.h"

/*
nom compiler v0.4 BETA
2.06.2019
by Centrix
*/

int buff[MEMSIZE];
int cursor = 0;
int codelen = 0;
int com = 0;

int find(char* word) {
	if (strstr(word, "*") != NULL && com == 0) { com = 1; return ISCOM; }
	else if (strstr(word, "*") != NULL && com == 1) { com = 0; return ISCOM; }

	for (int i = 0; i < kwcount; i++) {
		if (strcmp(keys[i], word) == 0) {
			return i;
		}
		else if (isdigit(word[0]) == 1) {
			return ISINT;
		}
	}
	if (com == 1) { return ISCOM; }
	return KEYERR;
}

int install(char* word) {
	int indx = find(word);

	if (com == 1 && indx == ISCOM) { return ISCOM; }

	if (indx >= 0) {
		buff[cursor++] = values[indx];
	}

	else {
		if (indx == KEYERR) {
			printf("Critical error. Unrecognized expression:\n%s\n", word, com, indx);
			exit(0);
		}
		else {
			buff[cursor++] = atoi(word);
		}
	}
	return 1;
}

void write(char* str, char* name) {
	FILE* file = fopen(name, "w");
	char* token = strtok(str, " ");
	int res = 0;

	if (file == NULL) { perror("Fail"); exit(0); }

	while (token != NULL) {
		res = install(token);
		token = strtok(NULL, " ");

		if (res == 1) {
			++codelen;
		}
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