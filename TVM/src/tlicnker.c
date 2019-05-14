#include <stdio.h>

void fcopy(FILE* from, FILE* to) {
	int c = fgetc(from);

	while (c != EOF) {
		putc(c, to);
		c = fgetc(from);
	}
	putc('\n', to);
}

int main(int argc, char *argv[]) {
	if (argc == 4) {
		FILE* src = fopen(argv[1], "r");
		FILE* out = fopen(argv[3], "w");

		fcopy(src, out);
		freopen(argv[2], "r", src);
		fcopy(src, out);

		fclose(src);
		fclose(out);
		perror("Errors");
	}
	else {
		printf("TLincker when you call requires four parameters, however, transferred to %d\n", argc);
	}
	return 0;
}