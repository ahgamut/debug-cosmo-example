#include <stdio.h>
#define NUM_CHARS 16

void hex16(const char *filename) {
    FILE *fp = fopen(filename, "r");
    char res[NUM_CHARS];
    int i, c;

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
    ShowCrashReports();
    hex16(argv[1]);
    return 0;
}
