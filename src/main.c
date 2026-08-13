#include <errno.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    const char *file_path = "test-data/autotester2-input.txt";
    FILE *input = NULL;
    int ch;

    if (argc > 1) {
        file_path = argv[1];
    }

    input = fopen(file_path, "r");
    if (input == NULL) {
        fprintf(stderr, "Failed to open '%s': %s\n", file_path, strerror(errno));
        return 1;
    }

    while ((ch = fgetc(input)) != EOF) {
        if (putchar(ch) == EOF) {
            fprintf(stderr, "Failed to write output\n");
            fclose(input);
            return 1;
        }
    }

    if (ferror(input)) {
        fprintf(stderr, "Failed to read '%s'\n", file_path);
        fclose(input);
        return 1;
    }

    fclose(input);
    return 0;
}
