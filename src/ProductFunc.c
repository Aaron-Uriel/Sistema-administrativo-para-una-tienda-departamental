#include "ProductFunc.h"
#include "Console.h"
#include <stdio.h>
#include <stdlib.h>

static FILE *g_FilePtr;
static const unsigned short g_CharLimit = 100;
static unsigned g_Lines = 1;
static unsigned g_Productos = 0;

static struct Producto {
    char Nombre[50];
    char Precio[6];
    char Descripcion[3][100];
}TempProducto;

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
        if (TempBuff == '{') {
            ++g_Productos;
        }
        if (TempBuff == '\n') {
            g_Lines++;
        }
    }
    fseek (g_FilePtr, 0, SEEK_SET); //Lleva el puntero al principio
    return 0;
}

void AgregarProducto() {
    ClearScreen();
    GoToEnd();
    printf ("Nombre del producto: ");
    fgets (TempProducto.Nombre, g_CharLimit, stdin);
    printf ("Precio: ");
    fgets (TempProducto.Precio, 6, stdin);
    printf ("Pequeña descripción (3 renglones de 100 caracteres máximo)\n");
    for (int Count = 0; Count < 3; Count++) {
        printf ("Renglón %d: ", Count + 1);
        fgets (TempProducto.Descripcion[Count], g_CharLimit, stdin);
    }

    //Se guarda
    fprintf(g_FilePtr, "{\n");
    fputs (TempProducto.Nombre, g_FilePtr);
    fputs (TempProducto.Precio, g_FilePtr);
    for (int Count = 0; Count < 3; Count++) {
        fputs (TempProducto.Descripcion[Count], g_FilePtr);
    }
    fprintf(g_FilePtr, "}\n");
    fseek (g_FilePtr, 0, SEEK_SET);
}

void GoToEnd() {
    char Temp;
    while ((Temp = getc(g_FilePtr)) != EOF);
}

void EliminarProducto() {
    ClearScreen();
    char StreamBuffer[g_CharLimit];
    printf ("Seleccione el producto a eliminar\n");

    //Se buscan los nombres
    while (!feof(g_FilePtr)) {
        fgets (StreamBuffer, g_CharLimit, g_FilePtr);
        if (StreamBuffer[0] == '{') {
            fgets (StreamBuffer, g_CharLimit, g_FilePtr);
            printf ("%s", StreamBuffer);
        }
    }
}