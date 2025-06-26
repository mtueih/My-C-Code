#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {

    if (argc < 2) {
        fprintf(stderr, "\n\tUsage: touch <file1> [file2] ...\t\n");
        return EXIT_FAILURE;
    }

    for (register unsigned i = 1; i < argc; ++i) {
        
    }


    return EXIT_SUCCESS;
}
