#include <stdio.h>
#include <stdlib.h>

char ins[262147] = {-1};
int len = 50;

int main(int argc, char ** argv) {
    FILE * in;
    FILE * out;

    if( (in = fopen( argv[1], "r")) == NULL ) {
	    printf("Failed to open input data file: %s \n", argv[1]);
    }
    if( (out = fopen( argv[2], "w")) == NULL ) {
	    printf("Failed to open input data file: %s \n", argv[2]);
	  }
    if(argc == 4) {
        len = atoi(argv[3]);
        if(len < 1) {
            printf("Length must be >= 1! Length set to 50.\n");
            len = 50;
        }
    }
    fscanf(in, "%s", ins);
    char c = ins[0];
    int counter = 1;
    int c2 = 0;
    while(c != '\0' && c != -1) {
        c = ins[c2];
        ++c2;
        fprintf(out, "%c", c);
        if(counter >= len) {
            fprintf(out, "\n");
            counter = 0;
        }
        ++counter;
    }

    fclose(in);
    fclose(out);
}