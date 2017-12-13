#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int word_counts(const char* string, const ssize_t len_of_string) {
    int word_count = 0;
    // TODO

    return word_count;
}

int *alphabetic_counts(const char *string, const ssize_t len_of_string) {
	static int alphabet_counts [26] = {0};
	// TODO
    
	return alphabet_counts;
}

int main(int argc, char *argv[]) {
	FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int i = 0;
    int *_alphabet_counts;

    if (argc != 2) {
    	printf("USAGE: %s <path_to_input_file>\n", argv[0]);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
    	printf("Error opening file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1 
    	&& strncmp(line, "-1", 2) != 0) {

        printf("%d ", word_counts(line, read));

        _alphabet_counts = alphabetic_counts(line, read);
        for(i=0;i<26;i++){
            printf("%d ", _alphabet_counts[i]);
        }
        printf("\n");
    }

    fclose(fp);
    if (line)
        free(line);

	return 0;
}