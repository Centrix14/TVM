#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tsl.h"

/*
dis num code v0.2 BETA
13.04.2019
by Centrix
*/

#define BREAK -3070

int find(int code) {
	for (int i = 0; i < kwcount; i++) {
		if (code == values[i]) {
			return i;
		}
		else if (code == end) {
			return BREAK;
		}
	}
	return ISINT;
}

void write(char* nameI, char* nameO) {
	FILE* output = fopen(nameO, "w");
	FILE* source = fopen(nameI, "r");
	char line[100];
	char* tok;
	int num = 0;
	int indx = 0; 

	while (!feof(source)) {
		fscanf(source, "%s", line);
		tok = strtok(line, " ");

		while (tok != NULL) {
			num = atoi(tok);
			indx = find(num);

			if (indx == ISINT) {
				fprintf(output, "%s ", tok);
			}

			else if (indx == BREAK) {
				fprintf(output, "%s", keys[18]);
				return;
			}

			else {
				fprintf(output, "%s ", keys[indx]);
			}

			tok = strtok(NULL, " ");
		}
	}

	fclose(output);
	fclose(source);
}

int main(int argc, char* argv[]) {
	if (argc == 3) {
		write(argv[1], argv[2]);
	}
	return 0;
}