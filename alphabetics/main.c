/* An implelemtation of ACM-ICPC Live Archive :: Regionals 2017 :: Africa/Middle East - South Africa 
/* #3396 Alphabetics in C
/* For more information, browse the website
/* https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=774&page=show_problem&problem=1397
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Parameters
//  string: 
//      a char array with [a..z][A..Z][.,':;?- ] with '\n' as its last element
//  len_of_string:
//      the length of the char array (in number of characters)
// Return
//      The number words in the string
//      A word is defined as one or more non-whitespace characters that contains at least one [a..z] and/or [A..Z]
int word_counts(const char* string, const ssize_t len_of_string) {
    int word_count = 0;
    // TODO

    return word_count;
}

// Parameters
//  string: 
//      a char array with [a..z][A..Z][.,':;?- ] with '\n' as its last element
//  len_of_string:
//      the length of the char array (in number of characters)
// Return
//      An int array denoting the number of times each character occurs in the string
//      eg. alphabet_counts[0] stands for the number of times that A and a occurs in the string
//          alphabet_counts[1] stands for B and b ...etc
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