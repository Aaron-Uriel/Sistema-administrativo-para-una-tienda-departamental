#include "ProductFunc.h"
#include <stdio.h>
#include <stdlib.h>

static FILE *g_FilePtr;

bool FindFileAndCountLines() {
    g_FilePtr = fopen("Product Struct.txt", "r");
    printf ("FUNCIONA.");
    getchar();
    exit(0);
    return 0;
}

void FOO() {
    bool FirstLaunch = 1;
    if (FirstLaunch) {
        FindFileAndCountLines();
        FirstLaunch = 0;
    }
}