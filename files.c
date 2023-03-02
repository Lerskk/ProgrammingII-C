#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fileCopy(FILE *input, FILE *output) {
	char str[1024], c;
	while ((c = fgetc(input)) != EOF) {
		if (c == ' ') 
			fputc(c, output);
		else if (c == '\n') {
			fputc(c, output);
		} else {
			ungetc(c, input);
			fscanf(input, "%1023s", str);
			fprintf(output,"%s", str);
		}
	}

}

void getLine(FILE *file, char **buffer) {
	int i, c = fgetc(file);
	for (i = 0; c != EOF && c != '\n'; i++, c = fgetc(file)) {
		*buffer = realloc(*buffer, sizeof(char) * (i + 1));
		(*buffer)[i] = c;
	}
	*buffer = realloc(*buffer, sizeof(char) * (i + 1));
	(*buffer)[i] = '\0'; 
}

char **lines(char *fileName) {
	FILE *file = fopen(fileName, "r");
	char *buffer = malloc(sizeof(char)), **lines = malloc(sizeof(char));
	int i, c;

	for (i = 0; (c = fgetc(file)) != EOF; i++) {
		ungetc(c, file);
		getLine(file, &buffer);
		lines = realloc(lines, sizeof(char*) * (i + 1));
		*(lines + i) = malloc(sizeof(char) * strlen(buffer));
		strcpy(*(lines + i), buffer);
	}
	lines = realloc(lines, sizeof(char*) * (i + 1));
	*(lines + i) = NULL;
	fclose(file);
	return lines;
}

int main() {
	// FILE *input = fopen("input.txt", "r"), *output = fopen("output.txt", "w");
	char *buffer = malloc(sizeof(char)), **my_lines = lines("input.txt");
	for (int i = 0; my_lines[i] != NULL; i++) {
		printf("%s\n", my_lines[i]);
		free(my_lines[i]);
	}
	free(my_lines);
	return 0;
}
		
	
	
	