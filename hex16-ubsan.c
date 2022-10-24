#include <stdio.h>
#define NUM_CHARS 16

void hex16(const char *filename) {
    FILE *fp = fopen(filename, "r");
    char res[NUM_CHARS + 1];
    int i, c;

    if (!fp) {
        printf("unable to read %s!\n", filename);
        return;
    }
    printf("hex16.c -- reading file %s\n", filename);
    for (i = 0; i < NUM_CHARS; i++) {
        c = fgetc(fp);
        if (feof(fp) || c == -1) break;
        printf("0x%02x ", c);
        res[i] = (char)c;
    }
    res[i] = '\0';
    fclose(fp);
    printf("\n%s\n", res);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("USAGE:\n\t%s FILENAME\n", argv[0]);
        return 1;
    }
    hex16(argv[1]);
    return 0;
}
