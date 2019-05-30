#include "ProductFunc.h"
#include <stdio.h>
#include <stdlib.h>

static FILE *g_FilePtr;
static const unsigned short g_CharLimit = 50;
static unsigned g_Lines = 1;

static struct Producto {
    char Nombre[50];
    char Precio[4];
};

void GoToEnd();

bool FindFileAndCountLines() {
    g_FilePtr = fopen("Product Struct.txt", "r+"); //Con permisos de lectura y escritura, debe existir
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
    fseek (g_FilePtr, 0, SEEK_SET); //Lleva el puntero al principio
    return 0;
}

void AgregarProducto() {
    struct Producto TempProducto;
    GoToEnd();
    printf ("Nombre del producto: ");
    fgets (TempProducto.Nombre, g_CharLimit, stdin);
    printf ("Precio: ");
    fgets (TempProducto.Precio, 4, stdin);

    //Se guarda
    fprintf(g_FilePtr, "%s", "\n");
    fputs(TempProducto.Nombre, g_FilePtr);
    fprintf(g_FilePtr, "%s", "\n");
}

void GoToEnd() {
    char Temp;
    while ((Temp = getc(g_FilePtr)) != EOF);
}