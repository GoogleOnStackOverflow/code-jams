/* An implelemtation of Google Code Jam Practice Round APAC test 2017
/* Lazy Spelling Bee (Problem A) in C
/* For more information, browse the website
/* https://code.google.com/codejam/contest/5254486/dashboard
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Parameters
//	string: 
//		a char array with a..z
//	length_of_string:
//		the length of the char array (in number of characters)
// Return
//		The number of possible answers corresponding to the string
int lazy_spelling_bee(const char *string, const ssize_t length_of_string) {
	int possible_choices = 0;
	// TODO

	return possible_choices;
}

int main(int argc, char *argv[]) {
	FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int i = 0, num_of_tests = 0;

    if (argc != 2) {
    	printf("USAGE: %s <path_to_input_file>\n", argv[0]);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
    	printf("Error opening file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((read = getline(&line, &len, fp)) != -1) {
    	num_of_tests = atoi(line);
    }

    while ((read = getline(&line, &len, fp)) != -1 
    	&& (i++ < num_of_tests)) {
    	if(line[read - 1] == '\n') {
    		memset(&line[read - 1], 0, 1);
    		--read;
    	}

        printf("Case #%d : %d\n", i, lazy_spelling_bee(line, read));
    }

    fclose(fp);
    if (line)
        free(line);

	return 0;
}