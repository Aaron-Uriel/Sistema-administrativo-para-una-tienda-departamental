#include "ProductFunc.h"
#include <stdio.h>
#include <stdlib.h>

static FILE *g_FilePtr;
static const unsigned short g_CharLimit = 50;
static unsigned g_Lines = 1;

bool FindFileAndCountLines() {
    g_FilePtr = fopen("Product Struct.txt", "r");
    if (g_FilePtr == NULL) {
        printf ("No se pudo abrir el archivo\n");
        exit (EXIT_FAILURE);
    }
    char TempBuff;
    while (!feof (g_FilePtr)) {
        TempBuff = fgetc (g_FilePtr);
        if (TempBuff == '\n') {
            g_Lines++;
        }
    }
    fseek (g_FilePtr, 0, SEEK_SET); //Lleva el puntero al final
    exit(0);
    return 0;
}

void AgregarProducto() {
    printf ("Nombre del producto: ");
}