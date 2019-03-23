#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
nom compiler v0.1 BETA
23.03.2019
by Centrix
*/

#define KEYERR -1
#define ISINT -2

char* keys[] = {"nil", "crg", "crc", "prg", "prc", ".point", ".jump", ".deb", ".main", "com", "put", ".restart", ".quit", ".clear",\
"add", "subt", "cmp", ".goback", ".end"};
int values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 3070};
int code[1024];
int cursor = 0;
int kwcount = 19;
int codelen = 0;

int find(char* word) {
	for (int i = 0; i < kwcount; i++) {
		if (strcmp(keys[i], word) == 0) {
			return i;
		}
		else if (isdigit(word[0]) == 1) {
			return ISINT;
		}
	}
	return KEYERR;
}

void install(char* word) {
	int indx = find(word);

	if (indx >= 0) {
		code[cursor++] = values[indx];
	}

	else {
		if (indx == KEYERR) {
			printf("Error!:\n%s\n", word);
			exit(0);
		}
		else {
			code[cursor++] = atoi(word);
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
		fprintf(file, "%d ", code[i]);
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
	return 0;
}