#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int leap_birthdays(const int D, const int M, const int Y, const int QY) {
	int birthday_counts = 0;
	// TODO
    
	return birthday_counts;
}

int main(int argc, char *argv[]) {
	FILE *fp;
    char *line = NULL, *dup = NULL, *pch = NULL;
    size_t len = 0;
    ssize_t read;
    int i = 0, num_of_tests = 0, j = 0;
    int data [4];

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

        printf("%s\n", line);
        
        dup = strdup(line);
        pch = strtok(dup, " ");
        while(pch != NULL && j < 4){
            data[j++] = atoi(pch);
            pch = strtok(NULL, " ");
        }
        free(dup);
        j = 0;

        printf("Case #%d : %d\n", i, leap_birthdays(data[0], data[1], data[2], data[3]));
    }

    fclose(fp);
    if (line)
        free(line);

	return 0;
}