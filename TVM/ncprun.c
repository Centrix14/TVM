#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tsl.c"

/*
ncprun.c v0.3.4
Запуск .ncp файлов / NCP file launcher
17.03.2019
by Centrix
*/

int flen(char* name) {
	int i = 0;
	FILE* stream = fopen(name, "r");
	if (stream != NULL) {
		while (!feof(stream)) {
			fgetc(stream);
			i++;
		}
	}
	else {
		perror("Fail");
	}
	fclose(stream);
	return i;
}

int main(int argc, char* argv[]) {
	FILE* prog;

	char txt[1000];
	char* tok;
	int i = 0;
	int len = flen(argv[1]);
	prog = fopen(argv[1], "r");

	if (prog != NULL) {
		fread(txt, 1, len, prog);
		tok = strtok(txt, " ");

		while (tok != NULL) {
			memory[i] = atoi(tok);
			tok = strtok(NULL, " ");
			if (argc == 3 && strcmp(argv[2], "-m") == 0) {
				printf("%d\n", memory[i]);
			}
			i++;
		}
		memInter();
	}
	else {
		perror("Fail");
	}
	fclose(prog);
	return 0;
}